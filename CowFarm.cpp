#include "CowFarm.h"
#include <iostream>

CowFarm::CowFarm(){
    buildingName = "Cow Farm";
    cost = 200; //arbitrary cost
    buildingID = 2; 
    inventoryAmount = 0;
    activeState = false;
    imageName = "dairyFarm.png";
    itemName = "milk";
    itemImage = "milk.png";
    itemAmount = 0;
    secondsToRenew = 2;
}

CowFarm::~CowFarm(){

}