#include "Shop.h"
#include <iostream>

Shop::Shop(){
    buildingName = "Shop";
    cost = 0; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "shop.png";
    itemName = "";
    itemImage = "";
    itemAmount = 0;
}

Shop::~Shop(){

}