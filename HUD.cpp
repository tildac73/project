#include "HUD.h"
#include <SFML/Graphics.hpp>
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

//creates a vector of the farms that will be displayed
HUD::HUD() : currentFarmIndex(0) {
    farms.push_back(new ChickenFarm());
    farms.push_back(new CowFarm());
    farms.push_back(new SheepFarm());
    farms.push_back(new Shop());
    farms.push_back(new UserProfile());
    farms.push_back(new Market());
}

//clears the memory
HUD::~HUD() {
    for (int i = 0; i < farms.size(); i++) {
        delete farms[i];
    }
}


void HUD::display() {
    UserProfile user;

    std::ifstream inFile("save.txt");

    if (inFile.is_open()) {
        // Read lines from the file
        std::string line;
        if (std::getline(inFile, line)) {
            farms[0]->set_capacity(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[0]->set_level(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[0]->set_cost(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[0]->set_itemAmount(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[0]->set_secondsToRenew(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[1]->set_capacity(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[1]->set_level(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[1]->set_cost(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[1]->set_itemAmount(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[1]->set_secondsToRenew(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[2]->set_capacity(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[2]->set_level(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[2]->set_cost(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[2]->set_itemAmount(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            farms[2]->set_secondsToRenew(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            user.set_wool(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            user.set_milk(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            user.set_eggs(std::stoi(line));
        }
        if (std::getline(inFile, line)) {
            user.set_balance(std::stoi(line));
        }
        // Close the file when you're done
        inFile.close();
    } else {
        std::cerr << "Failed to open the file for reading." << std::endl;
    }

    

    sf::Clock eggClock;//clock for the eggs
    sf::Clock milkClock;//clock for the milk
    sf::Clock woolClock;//clock for the wool

    sf::RenderWindow window(sf::VideoMode(800, 600), "Idle Farm Tycoon"); //makes a window with the name as the building name

    
    

    bool isTextBoxOpen = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::ofstream outFile("save.txt");

                if (outFile.is_open()) {

                    // Write integers to consecutive lines
                    outFile << farms[0]->get_capacity() << std::endl;
                    outFile << farms[0]->get_level() << std::endl;
                    outFile << user.get_chickenFarmCost() << std::endl;
                    outFile << farms[0]->get_itemAmount() << std::endl;
                    outFile << farms[0]->get_secondsToRenew() << std::endl;
                    outFile << farms[1]->get_capacity() << std::endl;
                    outFile << farms[1]->get_level() << std::endl;
                    outFile << user.get_cowFarmCost() << std::endl;
                    outFile << farms[1]->get_itemAmount() << std::endl;
                    outFile << farms[1]->get_secondsToRenew() << std::endl;
                    outFile << farms[2]->get_capacity() << std::endl;
                    outFile << farms[2]->get_level() << std::endl;
                    outFile << user.get_sheepFarmCost() << std::endl;
                    outFile << farms[2]->get_itemAmount() << std::endl;
                    outFile << farms[2]->get_secondsToRenew() << std::endl;
                    outFile << user.get_wool() << std::endl;
                    outFile << user.get_milk() << std::endl;
                    outFile << user.get_eggs() << std::endl;
                    outFile << user.get_balance() << std::endl;

                    // Close the file when you're done
                    outFile.close();
                } else {
                    std::cerr << "Failed to open the file for writing." << std::endl;
                }
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        if (isTextBoxOpen){
                            isTextBoxOpen = false;
                        }
                        currentFarmIndex = (currentFarmIndex - 1 + farms.size()) % farms.size();
                        break;
                    case sf::Keyboard::Right:
                        if (isTextBoxOpen){
                            isTextBoxOpen = false;
                        }
                        currentFarmIndex = (currentFarmIndex + 1) % farms.size();
                        break;
                    case sf::Keyboard::E:
                    //checks if the screen is the market before selling the eggs, and adding to the balance. The same for the milk and wool
                        if (farms[currentFarmIndex]->get_buildingName() == "Market" && user.get_eggs() != 0){
                            user.addBalance(5*user.get_eggs());
                            user.set_eggs(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (user.get_chickenFarmCost()<=user.get_balance()){
                                user.minusBalance(user.get_chickenFarmCost());
                                farms[0]->levelUp();
                                user.chickenPriceLevel();
                            }
                        }
                        break;
                    case sf::Keyboard::M:
                        if (farms[currentFarmIndex]->get_buildingName() == "Market" && user.get_milk() != 0){
                            user.addBalance(10*user.get_milk());
                            user.set_milk(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (user.get_cowFarmCost()<=user.get_balance()){
                                user.minusBalance(user.get_cowFarmCost());                                
                                farms[1]->levelUp();
                                user.cowPriceLevel();
                            }
                            isTextBoxOpen = true;
                        }
                        break;
                    case sf::Keyboard::W:
                        if (farms[currentFarmIndex]->get_buildingName() == "Market" && user.get_wool() != 0){
                            user.addBalance(20*user.get_wool());
                            user.set_wool(0);
                            isTextBoxOpen = true;
                        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
                            if (user.get_sheepFarmCost()<=user.get_balance()){
                                user.minusBalance(user.get_sheepFarmCost());
                                farms[2]->levelUp();
                                user.sheepPriceLevel();
                            }
                            isTextBoxOpen = true;
                        }
                        break;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (farms[currentFarmIndex]->get_buildingID() == 1){
                    user.addEggs(farms[currentFarmIndex]->get_itemAmount());
                }else if (farms[currentFarmIndex]->get_buildingID() == 2){
                    user.addMilk(farms[currentFarmIndex]->get_itemAmount());
                }else if (farms[currentFarmIndex]->get_buildingID() == 3){
                    user.addWool(farms[currentFarmIndex]->get_itemAmount());
                }

                farms[currentFarmIndex]->set_itemAmount(0);
            }
}

//adds items to the farm as time passes
        sf::Time elapsedEggs = eggClock.getElapsedTime();
        sf::Time elapsedMilk = milkClock.getElapsedTime();
        sf::Time elapsedWool = woolClock.getElapsedTime();

        float eggSeconds = elapsedEggs.asSeconds();
        float milkSeconds = elapsedMilk.asSeconds();
        float woolSeconds = elapsedWool.asSeconds();

        if (eggSeconds > farms[0]->get_secondsToRenew()){
            eggClock.restart();
            if (farms[0]->get_itemAmount() < farms[0]->get_capacity()){
                farms[0]->addItem();
            }
        }

        if (milkSeconds > farms[1]->get_secondsToRenew()){
            milkClock.restart();
            if (farms[1]->get_itemAmount() < farms[1]->get_capacity()){
                farms[1]->addItem();
            }

        }

        if (woolSeconds > farms[2]->get_secondsToRenew()){
            woolClock.restart();
            if (farms[2]->get_itemAmount() < farms[2]->get_capacity()){
                farms[2]->addItem();
            }
        }

        // loads the image and makes it a sprite for the background
        sf::Texture texture1;
        sf::Texture texture2;
        if (!texture1.loadFromFile(farms[currentFarmIndex]->imageName)) {
            std::cout << "Image could not be loaded" << std::endl;
        }
        if (!texture2.loadFromFile(farms[currentFarmIndex]->itemImage)) {
            texture2.loadFromFile("farms[currentFarmIndex]->itemImage");
        }
        
        sf::Sprite background;
        background.setTexture(texture1);

        sf::Sprite item;
        item.setTexture(texture2);
        sf::Vector2u itemSize = texture2.getSize(); //gets size
        float fixedItemWidth = 150.0f; // Set the desired width
        float scaleFactor = fixedItemWidth / itemSize.x;
        item.setScale(scaleFactor, scaleFactor);
        float posX = static_cast<float>((window.getSize().x/5));
        float posY = static_cast<float>((window.getSize().y/2.5));
        item.setPosition(posX,posY);

        // scaling the background to fill the window
        sf::Vector2u imageSize = texture1.getSize();
        float scaleX = static_cast<float>(window.getSize().x) / imageSize.x;
        float scaleY = static_cast<float>(window.getSize().y) / imageSize.y;
        background.setScale(scaleX, scaleY);

        sf::Text itemAmount;

        sf::Font MyFont;

        // Load from a font file on disk
        if (!MyFont.loadFromFile("ARLRDBD.ttf"))
        {
            // Error...
        }
        itemAmount.setFont(MyFont);
        itemAmount.setCharacterSize(72);  // Font size
        itemAmount.setFillColor(sf::Color::Black);  // Text color
        itemAmount.setPosition(static_cast<float>((window.getSize().x/4.5)), static_cast<float>((window.getSize().y/1.3)));  // Position on the window  
        itemAmount.setString(std::to_string(farms[currentFarmIndex]->get_itemAmount()));

        //sets up the font to display the eggs amount
        sf::Text eggsAmount;
        eggsAmount.setFont(MyFont);
        eggsAmount.setCharacterSize(72);  // Font size
        eggsAmount.setFillColor(sf::Color::Black);  // Text color
        eggsAmount.setString(std::to_string(user.get_eggs()));

//sets up the font to display the eggs level
        sf::Text eggsLevel;
        eggsLevel.setFont(MyFont);
        eggsLevel.setCharacterSize(72);  // Font size
        eggsLevel.setFillColor(sf::Color::Black);  // Text color
        eggsLevel.setString(std::to_string(farms[0]->get_level()));

//sets up the font to display the chicken farm capacity
        sf::Text eggsCapacity;
        eggsCapacity.setFont(MyFont);
        eggsCapacity.setCharacterSize(72);  // Font size
        eggsCapacity.setFillColor(sf::Color::Black);  // Text color
        eggsCapacity.setString(std::to_string(farms[0]->get_capacity()));

//sets up the font to display the eggs price
        sf::Text eggsPrice;
        eggsPrice.setFont(MyFont);
        eggsPrice.setCharacterSize(72);  // Font size
        eggsPrice.setFillColor(sf::Color::Black);  // Text color
        eggsPrice.setString(std::to_string(user.get_eggs()*farms[0]->get_itemValue()));

//sets up the font to display the chicken farm price
        sf::Text chickenFarmPrice;
        chickenFarmPrice.setFont(MyFont);
        chickenFarmPrice.setCharacterSize(55);  // Font size
        chickenFarmPrice.setFillColor(sf::Color::Black);  // Text color
        chickenFarmPrice.setString(std::to_string(user.get_chickenFarmCost()));

//sets up the font to display the milk amount
        sf::Text milkAmount;
        milkAmount.setFont(MyFont);
        milkAmount.setCharacterSize(72);  // Font size
        milkAmount.setFillColor(sf::Color::Black);  // Text color
        milkAmount.setString(std::to_string(user.get_milk()));

//sets up the font to display the milk level
        sf::Text milkLevel;
        milkLevel.setFont(MyFont);
        milkLevel.setCharacterSize(72);  // Font size
        milkLevel.setFillColor(sf::Color::Black);  // Text color
        milkLevel.setString(std::to_string(farms[1]->get_level()));

//sets up the font to display the cow farm capacity
        sf::Text milkCapacity;
        milkCapacity.setFont(MyFont);
        milkCapacity.setCharacterSize(72);  // Font size
        milkCapacity.setFillColor(sf::Color::Black);  // Text color
        milkCapacity.setString(std::to_string(farms[1]->get_capacity()));

//sets up the font to display the milk price
        sf::Text milkPrice;
        milkPrice.setFont(MyFont);
        milkPrice.setCharacterSize(72);  // Font size
        milkPrice.setFillColor(sf::Color::Black);  // Text color
        milkPrice.setString(std::to_string(user.get_milk()*farms[1]->get_itemValue()));

//sets up the font to display the cow farm price
        sf::Text cowFarmPrice;
        cowFarmPrice.setFont(MyFont);
        cowFarmPrice.setCharacterSize(55);  // Font size
        cowFarmPrice.setFillColor(sf::Color::Black);  // Text color
        cowFarmPrice.setString(std::to_string(user.get_cowFarmCost()));

//sets up the font to display the wool amount
        sf::Text woolAmount;
        woolAmount.setFont(MyFont);
        woolAmount.setCharacterSize(72);  // Font size
        woolAmount.setFillColor(sf::Color::Black);  // Text color
        woolAmount.setString(std::to_string(user.get_wool()));

//sets up the font to display the wool level
        sf::Text woolLevel;
        woolLevel.setFont(MyFont);
        woolLevel.setCharacterSize(72);  // Font size
        woolLevel.setFillColor(sf::Color::Black);  // Text color
        woolLevel.setString(std::to_string(farms[2]->get_level()));

//sets up the font to display the sheep farm capacity
        sf::Text woolCapacity;
        woolCapacity.setFont(MyFont);
        woolCapacity.setCharacterSize(72);  // Font size
        woolCapacity.setFillColor(sf::Color::Black);  // Text color
        woolCapacity.setString(std::to_string(farms[2]->get_capacity()));

//sets up the font to display the wool price
        sf::Text woolPrice;
        woolPrice.setFont(MyFont);
        woolPrice.setCharacterSize(72);  // Font size
        woolPrice.setFillColor(sf::Color::Black);  // Text color
        woolPrice.setString(std::to_string(user.get_wool()*farms[3]->get_itemValue()));

//sets up the font to display the sheep farm price
        sf::Text sheepFarmPrice;
        sheepFarmPrice.setFont(MyFont);
        sheepFarmPrice.setCharacterSize(55);  // Font size
        sheepFarmPrice.setFillColor(sf::Color::Black);  // Text color
        sheepFarmPrice.setString(std::to_string(user.get_sheepFarmCost()));

//sets up the font to display the balance
        sf::Text balance;
        balance.setFont(MyFont);
        balance.setCharacterSize(45);  // Font size
        balance.setFillColor(sf::Color::Black);  // Text color
        balance.setString(std::to_string(user.get_balance()));

//drawing to the window
         // Clear the window
        window.clear();
        window.draw(background);

        //Only display the item if there is more than 1
        if (farms[currentFarmIndex]->get_itemAmount() > 0){
            window.draw(item);
        }

        //ONLY DISPLAY THE ITEM AMOUNT ON SCREENS THAT REQUIRE IT
        if (farms[currentFarmIndex]->get_buildingName() != "Shop" && farms[currentFarmIndex]->get_buildingName() != "User Profile" && farms[currentFarmIndex]->get_buildingName() != "Market"){
            window.draw(itemAmount);
            if (farms[currentFarmIndex]->get_buildingName() == "Cow Farm"){
                milkLevel.setPosition(static_cast<float>((window.getSize().x/1.5)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(milkLevel);

                milkCapacity.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(milkCapacity);

            }else if (farms[currentFarmIndex]->get_buildingName() == "Chicken Farm"){
                eggsLevel.setPosition(static_cast<float>((window.getSize().x/1.5)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(eggsLevel);

                eggsCapacity.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(eggsCapacity);

            }else if (farms[currentFarmIndex]->get_buildingName() == "Sheep Farm"){
                woolLevel.setPosition(static_cast<float>((window.getSize().x/1.5)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(woolLevel);

                woolCapacity.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.5)));  // Position on the window  
                window.draw(woolCapacity);
            }
        }

//displaying item amount and balance on user profile
        if (farms[currentFarmIndex]->get_buildingName() == "User Profile"){
            eggsAmount.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(eggsAmount);

            eggsLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(eggsLevel);

            milkAmount.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/2.25)));  // Position on the window  
            window.draw(milkAmount);


            milkLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.25)));  // Position on the window  
            window.draw(milkLevel);

            woolAmount.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/1.7)));  // Position on the window  
            window.draw(woolAmount);

            woolLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/1.7)));  // Position on the window  
            window.draw(woolLevel);

            balance.setCharacterSize(45);  // Font size
            balance.setPosition(static_cast<float>((window.getSize().x/1.45)), static_cast<float>((window.getSize().y/1.14)));  // Position on the window  
            window.draw(balance);
        }else if (farms[currentFarmIndex]->get_buildingName() == "Market"){
            eggsAmount.setCharacterSize(55);  // Font size
            eggsAmount.setPosition(static_cast<float>((window.getSize().x/1.4)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(eggsAmount);

            eggsPrice.setCharacterSize(55);  // Font size
            eggsPrice.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(eggsPrice);

            milkAmount.setCharacterSize(55);  // Font size
            milkAmount.setPosition(static_cast<float>((window.getSize().x/1.4)), static_cast<float>((window.getSize().y/2.3)));  // Position on the window  
            window.draw(milkAmount);

            milkPrice.setCharacterSize(55);  // Font size
            milkPrice.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.3)));  // Position on the window  
            window.draw(milkPrice);

            woolAmount.setCharacterSize(55);  // Font size
            woolAmount.setPosition(static_cast<float>((window.getSize().x/1.4)), static_cast<float>((window.getSize().y/1.9)));  // Position on the window  
            window.draw(woolAmount);

            woolPrice.setCharacterSize(55);  // Font size
            woolPrice.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/1.9)));  // Position on the window  
            window.draw(woolPrice);


            balance.setPosition(static_cast<float>((window.getSize().x/1.15)), static_cast<float>((window.getSize().y/1.2)));  // Position on the window  
            window.draw(balance);
        }else if (farms[currentFarmIndex]->get_buildingName() == "Shop"){
            chickenFarmPrice.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(chickenFarmPrice);

            eggsLevel.setCharacterSize(55);  // Font size
            eggsLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/3.3)));  // Position on the window  
            window.draw(eggsLevel);

            cowFarmPrice.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/2.3)));  // Position on the window  
            window.draw(cowFarmPrice);

            milkLevel.setCharacterSize(55);
            milkLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/2.3)));  // Position on the window  
            window.draw(milkLevel);

            sheepFarmPrice.setPosition(static_cast<float>((window.getSize().x/1.6)), static_cast<float>((window.getSize().y/1.7)));  // Position on the window  
            window.draw(sheepFarmPrice);

            woolLevel.setCharacterSize(55);
            woolLevel.setPosition(static_cast<float>((window.getSize().x/1.2)), static_cast<float>((window.getSize().y/1.7)));  // Position on the window  
            window.draw(woolLevel);

            balance.setPosition(static_cast<float>((window.getSize().x/1.55)), static_cast<float>((window.getSize().y/1.15)));  // Position on the window  
            window.draw(balance);
        }

        if (isTextBoxOpen){
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(600, 50)); // Set the size of the rectangle
            rectangle.setPosition(static_cast<float>((window.getSize().x/6.5)), static_cast<float>((window.getSize().y/1.4))); // Set the position of the top-left corner of the rectangle
            rectangle.setFillColor(sf::Color(195, 175, 205)); // Set the fill color

            window.draw(rectangle);

            sf::Text confirmation;
            confirmation.setFont(MyFont);
            confirmation.setCharacterSize(25);  // Font size
            confirmation.setFillColor(sf::Color::Black);  // Text color
            confirmation.setPosition(static_cast<float>((window.getSize().x/6.5)), static_cast<float>((window.getSize().y/1.4)));  // Position on the window  
            confirmation.setString("Transaction complete! Press Space to close");
            window.draw(confirmation);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isTextBoxOpen = false; // Close the text box
            }
        }

        // Display the content
        window.display();
    }
}