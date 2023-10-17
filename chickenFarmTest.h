#include "ChickenFarm.h"
#include <iostream>

void chickenFarmTest(){
    std::string farm = "chicken farm";
    ChickenFarm myFarm;

    myFarm.set_buildingName("Barnyard");
    myFarm.set_cost(500);
    myFarm.set_buildingID(1);
    myFarm.levelUp();
    myFarm.set_capacity(5);

    std::cout << "My farm's capacity is " << myFarm.get_capacity() << ", it costs " << myFarm.get_cost() << std::endl;
}