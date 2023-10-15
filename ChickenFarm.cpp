#include "ChickenFarm.h"
#include <iostream>

ChickenFarm::ChickenFarm(){
    buildingName = "Chicken Farm";
    cost = 150; //arbitrary cost
    buildingID = 1; 
    inventoryAmount = 0;
    activeState = false;
    imageName = "chickenFarm.png";
    itemName = "egg";
    itemImage = "egg.png";
    itemAmount = 0;
    secondsToRenew = 1;
    itemValue = 2;
    capacity = 7;
}

ChickenFarm::~ChickenFarm(){

}