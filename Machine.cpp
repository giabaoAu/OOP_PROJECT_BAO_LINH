#include "Machine.h"

Machine::Machine() { game_level = 1; }

// int Machine::get_level() { return game_level; }

// string Machine::get_monster_type() { return monster_type; }

// Monster * Machine::get_monster(){return *machine_monster;}

void Machine::level_up() { game_level++; }

void Machine::set_monster(int index) {
  if (game_level != 1) {
    delete *machine_monster;
  }
  machine_monster = new Monster*;
  switch (index) {
    case 0:
      *machine_monster = new Dragon(game_level);
      monster_type = "Dragon";
    case 1:
      *machine_monster = new Serbine(game_level);
      monster_type = "Serbine";
    case 2:
      *machine_monster = new Titan(game_level);
      monster_type = "Titan";
    case 3:
      *machine_monster = new Aqua(game_level);
      monster_type = "Aqua";
  }
}

void Machine::take_attack(int strength) {
  int new_health = (**machine_monster).get_health() - strength;
  (**machine_monster).set_health(new_health);
}

Machine::~Machine() { delete machine_monster; }
