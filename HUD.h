#ifndef HUD_H
#define HUD_H
#include "Building.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class HUD{
public:
    virtual void display();
    HUD();
    ~HUD();
    /*void loadImages(std::string background, std::string item);
    sf::Text initialiseText(std::string font,int size,sf::Color colour,float posX, float posY,std::string string);
*/
private:
    std::vector<Building*> farms;
    int currentFarmIndex;
};

#endif