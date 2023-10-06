#include "Building.h"
#include <iostream>

Building::Building(){
    buildingName = "";
    buildingID = 0;
    cost = 0;
    inventoryAmount = 0;
    activeState = false;
    imageName = "";
}

Building::Building(std::string buildingName, int buildingID, int cost, std::string imageName){
    this->buildingName = buildingName;
    this->buildingID = buildingID;
    this->cost = cost;
    inventoryAmount = 0;
    activeState = false;
    this->imageName = imageName;
}

Building::~Building(){
    
}

//getters
std::string Building::get_buildingName(){
    return buildingName;
}

int Building::get_buildingID(){
    return buildingID;
}

int Building::get_cost(){
    return cost;
}

int Building::get_inventoryAmount(){
    return inventoryAmount;
}

bool Building::get_activeState(){
    return activeState;
}

std::string Building::get_imageName(){
    return imageName;
}

//setters
void Building::set_buildingName(std::string buildingName){
    this->buildingName = buildingName;
}

void Building::set_buildingID(int buildingID){
    this->buildingID = buildingID;
}

void Building::set_cost(int cost){
    this->cost = cost;
}

void Building::set_inventoryAmount(int inventoryAmount){
    this->inventoryAmount = inventoryAmount;
}

void Building::set_activeState(bool activeState){
    this->activeState = activeState;
}

void Building::set_imageName(std::string imageName){
    this->imageName = imageName;
}