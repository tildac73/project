#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <iostream>

class UserProfile {
public:

    void addWool(int amount);
    void addEggs(int amount);
    void addMilk(int amount);

    int get_wool();
    int get_eggs();
    int get_milk();

    void set_wool(int wool);
    void set_eggs(int eggs);
    void set_milk(int milk);

    int wool = 0;
    int eggs = 0;
    int milk = 0;

private:
};

#endif