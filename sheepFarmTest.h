#include "SheepFarm.h"
#include <iostream>

void sheepFarmTest(){
    std::string farm = "sheep farm";
    SheepFarm myFarm;

    myFarm.set_buildingName("Sheepies");
    myFarm.set_cost(500);
    myFarm.set_buildingID(1);
    myFarm.levelUp();
    myFarm.set_capacity(5);

    std::cout << "My farm's capacity is " << myFarm.get_capacity() << ", it costs " << myFarm.get_cost() << std::endl;
}