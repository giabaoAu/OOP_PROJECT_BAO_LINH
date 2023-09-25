#ifndef MACHINE_H
#define MACHINE_H

#include "Monster.h"

class Machine {
    private: 
    Monster ** machine_monster;
    static int monster_type;
    int game_level;
    public: 
    Machine();
    int get_level();
    static int get_monster_type();
    Monster * get_monster();
    void update_level();
    void set_monster(int level);
    ~Machine();

};
#endif