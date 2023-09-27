#ifndef MACHINE_H
#define MACHINE_H

#include "Monster.h"
#include <string>

using namespace std;
class Machine {
    private: 
    Monster ** machine_monster;
    static string monster_type;
    int game_level;
    public: 
    Machine();
    int get_level();
    static string get_monster_type();
    //No need get_monster, may delete later
    Monster * get_monster();
    void update_level();
    void set_monster(int level);
    void take_attack(int strength);
    ~Machine();

};
#endif