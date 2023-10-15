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
#include "Market.h"

//creates a vector of the farms that will be displayed
HUD::HUD() : currentFarmIndex(0) {
    farms.push_back(new ChickenFarm());
    farms.push_back(new CowFarm());
    farms.push_back(new SheepFarm());
    farms.push_back(new Shop());
    farms.push_back(new UserProfile());
    farms.push_back(new Market());
}

//clears the memory
HUD::~HUD() {
    for (Building* farm : farms) {
        delete farm;
    }
}


void HUD::display() {
    sf::Clock clock;//check system time and check when last open

    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Idle Farm Tycoon"); //makes a window with the name as the building name

    
    UserProfile user;

    bool isTextBoxOpen = false;

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
                    case sf::Keyboard::E:
                    //checks if the screen is the market before selling the eggs, and adding to the balance. The same for the milk and wool
                        if (farms[currentFarmIndex]->get_buildingName() == "Market"){
                            user.addBalance(5*user.get_eggs());
                            user.set_eggs(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (farms[currentFarmIndex]->get_cost()<user.get_balance()){
                                farms[currentFarmIndex]->levelUp();
                                user.minusBalance(farms[currentFarmIndex]->get_cost());
                                isTextBoxOpen = true;
                            }
                        }
                        break;
                    case sf::Keyboard::M:
                        if (farms[currentFarmIndex]->get_buildingName() == "Market"){
                            user.addBalance(10*user.get_milk());
                            user.set_milk(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (farms[currentFarmIndex]->get_cost()<user.get_balance()){
                                farms[currentFarmIndex]->levelUp();
                                user.minusBalance(farms[currentFarmIndex]->get_cost());
                            }
                            isTextBoxOpen = true;
                        }
                        break;
                    case sf::Keyboard::W:
                        if (farms[currentFarmIndex]->get_buildingName() == "Market"){
                            user.addBalance(20*user.get_wool());
                            user.set_wool(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (farms[currentFarmIndex]->get_cost()<user.get_balance()){
                                farms[currentFarmIndex]->levelUp();
                                user.minusBalance(farms[currentFarmIndex]->get_cost());
                            }
                            isTextBoxOpen = true;
                        }
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
            }
}

//adds items to the farm as time passes
        sf::Time elapsed1 = clock.getElapsedTime();

        float elapsedSeconds = elapsed1.asSeconds();

        float farmRenewalSeconds = farms[currentFarmIndex]->get_secondsToRenew(); 
        for (int i = 0; i<farms.size(); i++){
            if (std::fmod(elapsedSeconds, farmRenewalSeconds) < 0.06) {

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
            texture2.loadFromFile("farms[currentFarmIndex]->itemImage");
        }
        
        sf::Sprite background;
        background.setTexture(texture1);

        sf::Sprite item;
        item.setTexture(texture2);
        sf::Vector2u itemSize = texture2.getSize(); //gets size
        float fixedItemWidth = 150.0f; // Set the desired width
        float scaleFactor = fixedItemWidth / itemSize.x;
        item.setScale(scaleFactor, scaleFactor);
        float posX = static_cast<float>((window.getSize().x/5));
        float posY = static_cast<float>((window.getSize().y/2.5));
        item.setPosition(posX,posY);

        // scaling the background to fill the window
        sf::Vector2u imageSize = texture1.getSize();
        float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
        float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
        background.setScale(scaleX, scaleY);

        sf::Text itemAmount;

        sf::Font MyFont;

        // Load from a font file on disk
        if (!MyFont.loadFromFile("ARLRDBD.ttf"))
        {
            // Error...
        }
        itemAmount.setFont(MyFont);
        itemAmount.setCharacterSize(72);  // Font size
        itemAmount.setFillColor(sf::Color::Black);  // Text color
        itemAmount.setPosition(static_cast<float>((window.getSize().x/4.5)), static_cast<float>((window.getSize().y/1.3)));  // Position on the window  
        itemAmount.setString(std::to_string(farms[currentFarmIndex]->get_itemAmount()));

         // Clear the window
        window.clear();
        window.draw(background);

        //Only display the item if there is more than 1
        if (farms[currentFarmIndex]->get_itemAmount() > 0){
            window.draw(item);
        }

        //ONLY DISPLAY THE ITEM AMOUNT ON SCREENS THAT REQUIRE IT
        if (farms[currentFarmIndex]->get_buildingName() != "Shop" && farms[currentFarmIndex]->get_buildingName() != "User Profile" && farms[currentFarmIndex]->get_buildingName() != "Market"){
            window.draw(itemAmount);
        }

        if (farms[currentFarmIndex]->get_buildingName() == "User Profile"){
            sf::Text eggsAmount;
            eggsAmount.setFont(MyFont);
            eggsAmount.setCharacterSize(72);  // Font size
            eggsAmount.setFillColor(sf::Color::Black);  // Text color
            eggsAmount.setPosition(static_cast<float>((window.getSize().x/2)), static_cast<float>((window.getSize().y/3.5)));  // Position on the window  
            eggsAmount.setString(std::to_string(user.get_eggs()));
            window.draw(eggsAmount);

            sf::Text milkAmount;
            milkAmount.setFont(MyFont);
            milkAmount.setCharacterSize(72);  // Font size
            milkAmount.setFillColor(sf::Color::Black);  // Text color
            milkAmount.setPosition(static_cast<float>((window.getSize().x/2)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
            milkAmount.setString(std::to_string(user.get_milk()));
            window.draw(milkAmount);

            sf::Text woolAmount;
            woolAmount.setFont(MyFont);
            woolAmount.setCharacterSize(72);  // Font size
            woolAmount.setFillColor(sf::Color::Black);  // Text color
            woolAmount.setPosition(static_cast<float>((window.getSize().x/2)), static_cast<float>((window.getSize().y/1.8)));  // Position on the window  
            woolAmount.setString(std::to_string(user.get_wool()));
            window.draw(woolAmount);

            sf::Text balance;
            balance.setFont(MyFont);
            balance.setCharacterSize(72);  // Font size
            balance.setFillColor(sf::Color::Black);  // Text color
            balance.setPosition(static_cast<float>((window.getSize().x/2)), static_cast<float>((window.getSize().y/1.3)));  // Position on the window  
            balance.setString(std::to_string(user.get_balance()));
            window.draw(balance);
        }

        if (isTextBoxOpen){
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(600, 50)); // Set the size of the rectangle
            rectangle.setPosition(static_cast<float>((window.getSize().x/5)), static_cast<float>((window.getSize().y/4))); // Set the position of the top-left corner of the rectangle
            rectangle.setFillColor(sf::Color::Red); // Set the fill color

            window.draw(rectangle);

            sf::Text confirmation;
            confirmation.setFont(MyFont);
            confirmation.setCharacterSize(30);  // Font size
            confirmation.setFillColor(sf::Color::Black);  // Text color
            confirmation.setPosition(static_cast<float>((window.getSize().x/5)), static_cast<float>((window.getSize().y/4)));  // Position on the window  
            confirmation.setString("Successfully sold! Press Space to close");
            window.draw(confirmation);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isTextBoxOpen = false; // Close the text box
            }
        }

        // Display the content
        window.display();
    }
}