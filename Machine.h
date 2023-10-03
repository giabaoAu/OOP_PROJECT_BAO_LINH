#ifndef MACHINE_H
#define MACHINE_H

#include "Monster.h"
#include "Aqua.h"
#include "Dragon.h"
#include "Serbine.h"
#include "Titan.h"
#include <string>

using namespace std;
class Machine {
    private: 
    Monster ** machine_monster;
    static string monster_type;
    static int game_level;
    public: 
    Machine();
    static int get_level();
    //need for attack function in Monster class
    static string get_monster_type();


    //Monster * get_monster();

    void level_up();

    //random machine's monster (index) drawn before player going to each battle in main.cpp
    void set_monster(int index);
    void take_attack(int strength);
    
    ~Machine();

};
#endif