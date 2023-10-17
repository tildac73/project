#include "buildingTestFile.h"
#include "chickenFarmTest.h"
#include "sheepFarmTest.h"
#include "cowFarmTest.h"
#include "HUD.h"
#include <iostream>
#include <vector>
#include "Building.h"
#include "Shop.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"
#include "UserProfile.h"
#include "Market.h"
#include <fstream>
#include "Screen.h"
#include "userProfileTest.h"
#include "shopTest.h"

int main(void){

    buildingTest();
    chickenFarmTest();
    sheepFarmTest();
    cowFarmTest();
    userProfileTest();
    shopTest();

}