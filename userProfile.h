#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <iostream>
#include "Building.h"

class UserProfile : public Building{
public:

    UserProfile(); //initiates the user profile
    ~UserProfile(); //deletes the user profile

    void addWool(int amount); //adds to the number of wool
    void addEggs(int amount); // adds to the number of eggs
    void addMilk(int amount); // adds to the number of milk
    void addBalance(int amount); //increases the balances by the amount specified
    void minusBalance(int amount); //decreases the balance by the amount specified
    void chickenPriceLevel(); //increases the chicken farm cost
    void cowPriceLevel(); //increases the cow farm cost
    void sheepPriceLevel(); //increases the sheep price cost

//getters
    int get_wool(); 
    int get_eggs();
    int get_milk();
    int get_balance();
    int get_chickenFarmCost();
    int get_cowFarmCost();
    int get_sheepFarmCost();

//setters
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