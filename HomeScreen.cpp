#include "HomeScreen.h"
#include "HUD.h"
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
    sf::Text playText("Play", font, 36);
    sf::Text restartText("Restart", font, 36);
    sf::Text quitText("Quit", font, 36);

    playText.setPosition(350, 200);
    restartText.setPosition(350, 300);
    quitText.setPosition(350, 400);

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
                    if (playText.getGlobalBounds().contains(mousePos)) {
                        HUD HUD;
                        HUD.display();
                    } else if (restartText.getGlobalBounds().contains(mousePos)) {
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
                    } else if (quitText.getGlobalBounds().contains(mousePos)) {
                        window.close();
                    }
                }
            }
        }

        window.clear();
        window.draw(playText);
        window.draw(restartText);
        window.draw(quitText);
        window.display();
    }
}