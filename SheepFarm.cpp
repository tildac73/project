#include "SheepFarm.h"
#include <iostream>

SheepFarm::SheepFarm(){
    buildingName = "Sheep Farm";
    cost = 350; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "sheepFarm.png";
}

SheepFarm::~SheepFarm(){

}