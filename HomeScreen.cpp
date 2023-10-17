#include "HomeScreen.h"
#include "HUD.h"
#include "Instructions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

HomeScreen::HomeScreen(){

}

void HomeScreen::display(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Idle Farm Tycoon"); //makes a window with the name as the building name

    // Create a font for the text
    sf::Font font;
    if (!font.loadFromFile("ARLRDBD.ttf")) {
        std::cout << "font couldnt load" << std::endl;
    }

    // Create text for menu items
    sf::Text loadSavedText("Load Saved Game", font, 30);
    sf::Text restartText("Restart", font, 30);
    sf::Text quitText("Quit", font, 30);
    sf::Text instructionText("Instructions", font, 30);

    loadSavedText.setPosition(300, 200);
    restartText.setPosition(300, 250);
    quitText.setPosition(300, 350);
    instructionText.setPosition(300, 300);

    loadSavedText.setColor(sf::Color::Black);
    restartText.setColor(sf::Color::Black);
    quitText.setColor(sf::Color::Black);;
    instructionText.setColor(sf::Color::Black);

    sf::Texture texture1;
    if (!texture1.loadFromFile("homescreen.png")) {
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
                    if (loadSavedText.getGlobalBounds().contains(mousePos)) {
                        window.close();
                        HUD HUD;
                        HUD.display();
                    } else if (restartText.getGlobalBounds().contains(mousePos)) {
                        window.close();

                        std::ofstream outFile("save.txt");

                        if (outFile.is_open()) {

                            // Write integers to consecutive lines
                            outFile << 5 << std::endl;
                            outFile << 1 << std::endl;
                            outFile << 100 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 3 << std::endl;
                            outFile << 3 << std::endl;
                            outFile << 1 << std::endl;
                            outFile << 200 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 10 << std::endl;
                            outFile << 2 << std::endl;
                            outFile << 1 << std::endl;
                            outFile << 400 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 20 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 0 << std::endl;
                            outFile << 0 << std::endl;

                            // Closes the file when done
                            outFile.close();

                            HUD HUD;
                            HUD.display();
                        }
                    } else if (instructionText.getGlobalBounds().contains(mousePos)) {
                        window.close();
                        Instructions instructions;
                        instructions.display();
                    } else if (quitText.getGlobalBounds().contains(mousePos)) {
                        window.close();
                    } 
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(loadSavedText);
        window.draw(restartText);
        window.draw(quitText);
        window.draw(instructionText);
        window.display();
    }
}