#ifndef TEXTLOADING_H
#define TEXTLOADING_H
#include <SFML/Graphics.hpp>
#include <iostream>

class text{
public: 
    sf::Text InitialiseText(std::string font, int size, sf::Color colour, float posX, float posY, std::string string){
        sf::Text text;

        // Load from a font file on disk
        sf::Font MyFont;
        if (!MyFont.loadFromFile(font))
        {
            std::cout << "Couldnt load font" << std::endl;
        }

        text.setFont(MyFont);
        text.setCharacterSize(size);  // Font size
        text.setFillColor(sf::Color::Black);  // Text color
        text.setPosition(posX, posY);  // Position on the window
        text.setString(string);

        return text;
    }
};

#endif