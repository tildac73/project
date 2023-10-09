#ifndef HUD_H
#define HUD_H
#include "Building.h"
#include <vector>
#include <iostream>

class HUD{
public:
    virtual void display();
    HUD();
    ~HUD();
    void loadImages(std::string background, std::string item);

private:
    std::vector<Building*> farms;
    int currentFarmIndex;
};

#endif