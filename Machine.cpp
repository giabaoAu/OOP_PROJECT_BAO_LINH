#include "Machine.h"

Machine::Machine() {}

int Machine::get_level() { return 0; }

string Machine::get_monster_type() { return monster_type; }

Monster * Machine::get_monster(){return *machine_monster;}

void Machine::update_level() {}

void Machine::set_monster(int level) {}

void Machine::take_attack(int strength) {
    int new_health = (**machine_monster).get_health() - strength;
    (**machine_monster).set_health(new_health);
}

Machine::~Machine() {}
