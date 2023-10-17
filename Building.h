#ifndef BUILDING_H
#define BUILDING_H
#include "Screen.h"
#include <iostream>

class Building : public Screen{
public:

    void addItem(); //adds an item to the farms item count
    void levelUp(); //levels up the game (inc. capacity and rate of item)
    
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

    std::string itemName; //the name of the item
    std::string itemImage; //the image used to display the item
    int itemAmount; // the number of items
    int secondsToRenew; // how long each item takes to renew

    int level; // the farms level

    int itemValue; // how much each item sells for

    int capacity; // how many of the item can be contained by the farm

private:

};

#endif