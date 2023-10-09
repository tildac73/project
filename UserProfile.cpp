#include "UserProfile.h"
#include <iostream>

void UserProfile::addWool(int amount){
    wool+= amount;
}

void UserProfile::addEggs(int amount){
    eggs+= amount;
}

void UserProfile::addMilk(int amount){
    milk+= amount;
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

void UserProfile::set_wool(int wool){
    this->wool = wool;
}

void UserProfile::set_eggs(int eggs){
    this->eggs = eggs;
}

void UserProfile::set_milk(int milk){
    this->milk = milk;
}