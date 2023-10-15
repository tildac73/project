#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>

class Building{
public:

    Building();
    Building(std::string buildingName, int buildingID, int cost, std::string imageName); //constructor

    ~Building(); //destructor

    void addItem();
    void levelUp();
    
    //getters
    std::string get_buildingName();
    int get_buildingID();
    int get_cost();
    int get_inventoryAmount();
    bool get_activeState();
    std::string get_imageName();

    std::string get_itemName();
    std::string get_itemImage();
    int get_itemAmount();
    int get_secondsToRenew();

    int get_level();

    int get_itemValue();

    int get_capacity();

    //setters
    void set_buildingName(std::string buildingName);
    void set_buildingID(int buildingID);
    void set_cost(int cost);
    void set_inventoryAmount(int inventoryAmount);
    void set_activeState(bool activeState);
    void set_imageName(std::string imageName);

    void set_itemName(std::string itemName);
    void set_itemImage(std::string itemImage);
    void set_itemAmount(int itemAmount);
    void set_secondsToRenew(int secondsToRenew);

    void set_level(int level);

    void set_itemValue(int itemValue);

    void set_capacity(int capacity);

    std::string buildingName;
    std::string imageName;
    int buildingID;
    int cost;
    int inventoryAmount; //contains the number of items which can be harvested
    bool activeState; //is the building currently displayed on screen - i.e. can it be interacted with?

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