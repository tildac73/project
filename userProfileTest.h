#include "UserProfile.h"
#include <iostream>

void userProfileTest(){
    UserProfile user;

    

    std::cout << "The chicken farm capacity is " << user.get_buildingName() << ", it costs " << user.get_balance() << std::endl;
}