#include "ChickenFarm.h"
#include <iostream>

ChickenFarm::ChickenFarm(){
    buildingName = "Chicken Farm";
    cost = 150; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "chickenFarm.png";
}

ChickenFarm::~ChickenFarm(){

}