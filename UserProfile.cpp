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
    chickenFarmCost = 100;
    cowFarmCost = 200;
    sheepFarmCost = 400;
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

void UserProfile::chickenPriceLevel(){
    chickenFarmCost = chickenFarmCost*1.5;
}

void UserProfile::cowPriceLevel(){
    cowFarmCost = cowFarmCost*1.5;
}

void UserProfile::sheepPriceLevel(){
    sheepFarmCost = sheepFarmCost*1.5;
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

int UserProfile::get_chickenFarmCost(){
    return chickenFarmCost;
}

int UserProfile::get_cowFarmCost(){
    return cowFarmCost;
}

int UserProfile::get_sheepFarmCost(){
    return sheepFarmCost;
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

void UserProfile::set_chickenFarmCost(int chickenFarmCost){
    this->chickenFarmCost = chickenFarmCost;
}

void UserProfile::set_cowFarmCost(int cowFarmCost){
    this->cowFarmCost = cowFarmCost;
}

void UserProfile::set_sheepFarmCost(int sheepFarmCost){
    this->sheepFarmCost = sheepFarmCost;
}