#include "HUD.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Building.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"

HUD::HUD() : currentFarmIndex(0) {
    farms.push_back(new ChickenFarm());
    farms.push_back(new CowFarm());
    farms.push_back(new SheepFarm());
}

HUD::~HUD() {
    for (Building* farm : farms) {
        delete farm;
    }
}

void HUD::display() {
    sf::RenderWindow window(sf::VideoMode(800, 600), farms[currentFarmIndex]->buildingName); //makes a window with the name as the building name

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
        }

        // loads the image and makes it a sprite
        sf::Texture texture;
        if (!texture.loadFromFile(farms[currentFarmIndex]->imageName)) {
            std::cout << "Image could not be loaded" << std::endl;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);

        // scaling the sprite to fill the window
        sf::Vector2u imageSize = texture.getSize();
        float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
        float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
        sprite.setScale(scaleX, scaleY);

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the content
        window.display();
    }
}

/*void HUD::display(){
    
    sf::RenderWindow window(sf::VideoMode(800, 600), buildingName); //makes a window with the name as the building name

//loads the image and makes it a sprite
    sf::Texture texture;
    if (!texture.loadFromFile(imageName)) {
        std::cout << "image could not be loaded" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

//scaling the sprite to fill the window
    sf::Vector2u imageSize = texture.getSize(); 
    float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
    float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
    sprite.setScale(scaleX, scaleY);

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the content
        window.display();
    }
}*/