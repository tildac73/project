#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>

class Screen{
public:

    virtual void addItem();
    virtual void levelUp();

    Screen();
    Screen(std::string buildingName, int buildingID, int cost, std::string imageName); //constructor

    ~Screen(); //destructor

    //getters
    std::string get_buildingName();
    int get_buildingID();
    int get_cost();
    int get_inventoryAmount();
    bool get_activeState();
    std::string get_imageName();

    //setters
    void set_buildingName(std::string buildingName);
    void set_buildingID(int buildingID);
    void set_cost(int cost);
    void set_inventoryAmount(int inventoryAmount);
    void set_activeState(bool activeState);
    void set_imageName(std::string imageName);

    std::string buildingName;
    std::string imageName;
    int buildingID;
    int cost;
    int inventoryAmount; //contains the number of items which can be harvested
    bool activeState; //is the building currently displayed on screen - i.e. can it be interacted with?

private:

};

#endif