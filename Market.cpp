#include "Market.h"
#include <iostream>

Market::Market(){
    buildingName = "Market";
    cost = 0; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "market.png";
    itemName = "";
    itemImage = "Empty.png";
    itemAmount = 0;
}

Market::~Market(){

}