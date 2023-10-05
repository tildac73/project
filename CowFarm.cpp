#include "CowFarm.h"
#include <iostream>

CowFarm::CowFarm(){
    buildingName = "Cow Farm";
    cost = 200; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "dairyFarm.png";
}

CowFarm::~CowFarm(){

}