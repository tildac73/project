#include "Building.h"
#include <iostream>

int main(void){
    std::string barn = "Barn";
    Building myBarn;

    myBarn.set_buildingName("Barnyard");
    myBarn.set_cost(500);
    myBarn.set_buildingID(1);

    std::cout << "My barn is called " << myBarn.get_buildingName() << ", it costs " << myBarn.get_cost() << std::endl;

    myBarn.display();

    return 0;
}