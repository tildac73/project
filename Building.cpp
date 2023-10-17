#include "Building.h"
#include "UserProfile.h"
#include <iostream>



void Building::addItem(){
    itemAmount++;
}

void Building::levelUp(){
    secondsToRenew = 0.8*secondsToRenew;
    capacity++;
    level++;
}

std::string Building::get_itemName(){
    return itemName;
}

std::string Building::get_itemImage(){
    return itemImage;
}

int Building::get_itemAmount(){
    return itemAmount;
}

int Building::get_secondsToRenew(){
    return secondsToRenew;
}

int Building::get_level(){
    return level;
}

int Building::get_itemValue(){
    return itemValue;
}

int Building::get_capacity(){
    return capacity;
}

//setters


void Building::set_itemName(std::string itemName){
    this->itemName = itemName;
}

void Building::set_itemImage(std::string itemImage){
    this->itemImage = itemImage;
}

void Building::set_itemAmount(int itemAmount){
    this->itemAmount = itemAmount;
}

void Building::set_secondsToRenew(int secondsToRenew){
    this->secondsToRenew = secondsToRenew;
}

void Building::set_level(int level){
    this->level = level;
}

void Building::set_itemValue(int itemValue){
    this->itemValue = itemValue;
}

void Building::set_capacity(int capacity){
    this->capacity = capacity;
}