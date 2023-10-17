#include "Shop.h"
#include <iostream>

void shopTest(){
    std::string farm = "shop";
    Shop shop;

    shop.set_buildingName("Shop");
    shop.set_cost(500);
    shop.set_buildingID(1);

    std::cout << "My shop's building id is: " << shop.get_buildingID() << ", it costs " << shop.get_cost() << std::endl;
}