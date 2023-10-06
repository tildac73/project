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

private:
    std::vector<Building*> farms;
    int currentFarmIndex;
};

#endif