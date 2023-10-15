#include "UserProfile.h"
#include <iostream>

UserProfile::UserProfile(){
    buildingName = "User Profile";
    cost = 0; //arbitrary cost
    buildingID = 0; //eventually change to the next ID in line
    inventoryAmount = 0;
    activeState = false;
    imageName = "userProfile.png";
    itemName = "";
    itemImage = "Empty.png";
    itemAmount = 0;
    wool = 0;
    milk = 0;
    eggs = 0;
    balance = 0;
}

UserProfile::~UserProfile(){
    
}

void UserProfile::addWool(int amount){
    wool+= amount;
}

void UserProfile::addEggs(int amount){
    eggs+= amount;
}

void UserProfile::addMilk(int amount){
    milk+= amount;
}

void UserProfile::addBalance(int amount){
    balance += amount;
}

void UserProfile::minusBalance(int amount){
    balance -= amount;
}

int UserProfile::get_wool(){
    return wool;
}

int UserProfile::get_eggs(){
    return eggs;
}   

int UserProfile::get_milk(){
    return milk;
}

int UserProfile::get_balance(){
    return balance;
}

void UserProfile::set_wool(int wool){
    this->wool = wool;
}

void UserProfile::set_eggs(int eggs){
    this->eggs = eggs;
}

void UserProfile::set_milk(int milk){
    this->milk = milk;
}

void UserProfile::set_balance(int balance){
    this->balance = balance;
}