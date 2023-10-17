#ifndef BUILDING_H
#define BUILDING_H
#include "Screen.h"
#include <iostream>

class Building : public Screen{
public:

    void addItem();
    void levelUp();
    
    //getters
    std::string get_itemName();
    std::string get_itemImage();
    int get_itemAmount();
    int get_secondsToRenew();

    int get_level();

    int get_itemValue();

    int get_capacity();

    //setters

    void set_itemName(std::string itemName);
    void set_itemImage(std::string itemImage);
    void set_itemAmount(int itemAmount);
    void set_secondsToRenew(int secondsToRenew);

    void set_level(int level);

    void set_itemValue(int itemValue);

    void set_capacity(int capacity);

    std::string itemName;
    std::string itemImage;
    int itemAmount;
    int secondsToRenew;

    int level;

    int itemValue;

    int capacity;

private:

};

#endif