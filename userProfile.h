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

    int get_wool();
    int get_eggs();
    int get_milk();
    int get_balance();

    void set_wool(int wool);
    void set_eggs(int eggs);
    void set_milk(int milk);
    void set_balance(int balance);

    int wool;
    int eggs;
    int milk;
    int balance;

private:
};

#endif