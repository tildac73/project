#include "CowFarm.h"
#include <iostream>

int main(void){
    CowFarm myFarm;

    std::cout << "My farm is called " << myFarm.get_buildingName() << ", it costs " << myFarm.get_cost() << std::endl;

    myFarm.display();

    return 0;
}