#include "HUD.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Building.h"
#include "Shop.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"
#include "UserProfile.h"


HUD::HUD() : currentFarmIndex(0) {
    farms.push_back(new ChickenFarm());
    farms.push_back(new CowFarm());
    farms.push_back(new SheepFarm());
    farms.push_back(new Shop());
}

HUD::~HUD() {
    for (Building* farm : farms) {
        delete farm;
    }
}

void HUD::display() {
    sf::Clock clock;//check system time and check when last open
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idle Farm Tycoon"); //makes a window with the name as the building name

    UserProfile user;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        currentFarmIndex = (currentFarmIndex - 1 + farms.size()) % farms.size();
                        break;
                    case sf::Keyboard::Right:
                        currentFarmIndex = (currentFarmIndex + 1) % farms.size();
                        break;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (farms[currentFarmIndex]->get_buildingID() == 1){
                    user.addEggs(farms[currentFarmIndex]->get_itemAmount());
                }else if (farms[currentFarmIndex]->get_buildingID() == 2){
                    user.addMilk(farms[currentFarmIndex]->get_itemAmount());
                }else if (farms[currentFarmIndex]->get_buildingID() == 3){
                    user.addWool(farms[currentFarmIndex]->get_itemAmount());
                }

                farms[currentFarmIndex]->set_itemAmount(0);

                std::cout << "eggs: " << user.get_eggs() << " milk: " << user.get_milk() << " wool: " << user.get_wool() << std::endl;
            }
        }

        sf::Time elapsed1 = clock.getElapsedTime();

        int timeInSeconds = elapsed1.asSeconds();
        for (int i = 0; i<farms.size(); i++){
            if (((timeInSeconds % farms[i]->get_secondsToRenew()) == 0)&&(abs(elapsed1.asSeconds()-timeInSeconds)<0.007)){
                farms[i]->addItem();
            }
        }
        

        // loads the image and makes it a sprite for the background
        sf::Texture texture1;
        sf::Texture texture2;
        if (!texture1.loadFromFile(farms[currentFarmIndex]->imageName)) {
            std::cout << "Image could not be loaded" << std::endl;
        }
        if (!texture2.loadFromFile(farms[currentFarmIndex]->itemImage)) {
            std::cout << "Image could not be loaded" << std::endl;
        }
        
        sf::Sprite background;
        background.setTexture(texture1);

        sf::Sprite item;
        item.setTexture(texture2);
        sf::Vector2u itemSize = texture2.getSize(); //gets size
        float fixedItemWidth = 100.0f; // Set the desired width
        float scaleFactor = fixedItemWidth / itemSize.x;
        item.setScale(scaleFactor, scaleFactor);

        // scaling the background to fill the window
        sf::Vector2u imageSize = texture1.getSize();
        float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
        float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
        background.setScale(scaleX, scaleY);

         // Clear the window
        window.clear();
        window.draw(background);

        for (int i = 0; i<farms[currentFarmIndex]->get_itemAmount(); i++){

            float posX = static_cast<float>((window.getSize().x - 150.0f)-i*100);
            float posY = static_cast<float>((window.getSize().y - 150.0f)-i*50);

            // Set the item position
            item.setPosition(posX, posY);

            // Draw the item
            window.draw(item);
        }

        // Display the content
        window.display();
    }
}