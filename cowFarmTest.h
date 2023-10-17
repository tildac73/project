#include "CowFarm.h"
#include <iostream>

void cowFarmTest(){
    std::string farm = "cow farm";
    CowFarm myFarm;

    myFarm.set_buildingName("Cowies");
    myFarm.set_cost(500);
    myFarm.set_buildingID(1);
    myFarm.levelUp();
    myFarm.set_capacity(5);

    std::cout << "My farm's capacity is " << myFarm.get_capacity() << ", it costs " << myFarm.get_cost() << std::endl;
}