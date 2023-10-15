#include "SheepFarm.h"
#include <iostream>

SheepFarm::SheepFarm(){
    buildingName = "Sheep Farm";
    cost = 350; //arbitrary cost
    buildingID = 3;
    inventoryAmount = 0;
    activeState = false;
    imageName = "sheepFarm.png";
    itemName = "wool";
    itemImage = "wool.png";
    itemAmount = 0;
    secondsToRenew = 20;
    itemValue = 20;
    capacity = 3;
}

SheepFarm::~SheepFarm(){

}