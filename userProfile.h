#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <iostream>
#include "Building.h"

class UserProfile : public Building{
public:

    UserProfile();
    ~UserProfile();

    void addWool(int amount);
    void addEggs(int amount);
    void addMilk(int amount);
    void addBalance(int amount);
    void minusBalance(int amount);
    void chickenPriceLevel();
    void cowPriceLevel();
    void sheepPriceLevel();

    int get_wool();
    int get_eggs();
    int get_milk();
    int get_balance();
    int get_chickenFarmCost();
    int get_cowFarmCost();
    int get_sheepFarmCost();

    void set_wool(int wool);
    void set_eggs(int eggs);
    void set_milk(int milk);
    void set_balance(int balance);
    void set_chickenFarmCost(int chickenFarmCost);
    void set_cowFarmCost(int cowFarmCost);
    void set_sheepFarmCost(int sheepFarmCost);

    int wool;
    int eggs;
    int milk;
    int balance;

    int chickenFarmCost;
    int cowFarmCost;
    int sheepFarmCost;


private:
};

#endif