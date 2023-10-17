#ifndef HUD_H
#define HUD_H
#include "Building.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class HUD{
public:
    virtual void display(); //displays the main game
    HUD(); //initiates the HUD
    ~HUD(); //deletes the HUD

private:
    std::vector<Building*> farms; //the farm vector which contains the farms to switch between
    int currentFarmIndex; //contains the index of the farm which is currently displayed
};

#endif