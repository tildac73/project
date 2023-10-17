#include "Screen.h"
#include <iostream>

Screen::Screen(){
    buildingName = "";
    buildingID = 0;
    inventoryAmount = 0;
    activeState = false;
    imageName = "";
}

Screen::Screen(std::string buildingName, int buildingID, int cost, std::string imageName){
    this->buildingName = buildingName;
    this->buildingID = buildingID;
    this->cost = cost;
    inventoryAmount = 0;
    activeState = false;
    this->imageName = imageName;
}

Screen::~Screen(){
    
}

void Screen::addItem(){
}

void Screen::levelUp(){
}

//getters
std::string Screen::get_buildingName(){
    return buildingName;
}

int Screen::get_buildingID(){
    return buildingID;
}

int Screen::get_cost(){
    return cost;
}

int Screen::get_inventoryAmount(){
    return inventoryAmount;
}

bool Screen::get_activeState(){
    return activeState;
}

std::string Screen::get_imageName(){
    return imageName;
}

//setters
void Screen::set_buildingName(std::string buildingName){
    this->buildingName = buildingName;
}

void Screen::set_buildingID(int buildingID){
    this->buildingID = buildingID;
}

void Screen::set_cost(int cost){
    this->cost = cost;
}

void Screen::set_inventoryAmount(int inventoryAmount){
    this->inventoryAmount = inventoryAmount;
}

void Screen::set_activeState(bool activeState){
    this->activeState = activeState;
}

void Screen::set_imageName(std::string imageName){
    this->imageName = imageName;
}