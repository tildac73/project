#include "Instructions.h"
#include "HomeScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

Instructions::Instructions(){

}

void Instructions::display(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Idle Farm Tycoon"); //makes a window with the name as the building name

    // Create a font for the text
    sf::Font font;
    if (!font.loadFromFile("ARLRDBD.ttf")) {
        std::cout << "font couldnt load" << std::endl;
    }

    // Create text for menu items
    sf::Text back("Back", font, 36);

    back.setPosition(50, 50);
    sf::Texture texture1;
    if (!texture1.loadFromFile("instructions.png")) {
        std::cout << "Image could not be loaded" << std::endl;
    }

    
    sf::Sprite background;
    background.setTexture(texture1);

    // scaling the background to fill the window
    sf::Vector2u imageSize = texture1.getSize();
    float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
    float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
    background.setScale(scaleX, scaleY);
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the mouse click is within the bounds of a menu item
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (back.getGlobalBounds().contains(mousePos)) {
                        window.close();
                        HomeScreen home;
                        home.display();
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(back);
        window.display();
    }
}