#include "Building.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Building::Building(){
    buildingName = "";
    buildingID = 0;
    cost = 0;
    inventoryAmount = 0;
    activeState = false;
    imageName = "";
}

Building::Building(std::string buildingName, int buildingID, int cost, std::string imageName){
    this->buildingName = buildingName;
    this->buildingID = buildingID;
    this->cost = cost;
    inventoryAmount = 0;
    activeState = false;
    this->imageName = imageName;
}

Building::~Building(){
    
}

/*void Building::display(){
    sf::RenderWindow window(sf::VideoMode(200, 200), buildingName);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}*/

void Building::display(){
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), buildingName);

    // Load an image
    sf::Texture texture;
    if (!texture.loadFromFile(imageName)) {
        // Handle error if the image can't be loaded
        std::cout << "image could not be loaded" << std::endl;
    }

    // Create a sprite and set its texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Get the original size of the sprite
    sf::Vector2u imageSize = texture.getSize();

    // Calculate the scale factors to fit the sprite in the window
    float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
    float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;

    // Set the scale of the sprite to maintain aspect ratio and fill the window
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
}

//getters
std::string Building::get_buildingName(){
    return buildingName;
}

int Building::get_buildingID(){
    return buildingID;
}

int Building::get_cost(){
    return cost;
}

int Building::get_inventoryAmount(){
    return inventoryAmount;
}

bool Building::get_activeState(){
    return activeState;
}

std::string Building::get_imageName(){
    return imageName;
}

//setters
void Building::set_buildingName(std::string buildingName){
    this->buildingName = buildingName;
}

void Building::set_buildingID(int buildingID){
    this->buildingID = buildingID;
}

void Building::set_cost(int cost){
    this->cost = cost;
}

void Building::set_inventoryAmount(int inventoryAmount){
    this->inventoryAmount = inventoryAmount;
}

void Building::set_activeState(bool activeState){
    this->activeState = activeState;
}

void Building::set_imageName(std::string imageName){
    this->imageName = imageName;
}