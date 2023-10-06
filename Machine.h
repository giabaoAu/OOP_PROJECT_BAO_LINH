#ifndef MACHINE_H
#define MACHINE_H

#include <string>

#include "Aqua.h"
#include "Dragon.h"
#include "Monster.h"
#include "Serbine.h"
#include "Titan.h"

using namespace std;
class Machine {
 private:
  Monster** machine_monster;

 public:
  Machine();
  //static int get_level();
  // need for attack function in Monster class
  //static string get_monster_type();
  static string monster_type;
  static int game_level;

  Monster * get_monster();

  void level_up();
  // random machine's monster (index) drawn before player going to each battle
  // in main.cpp
  int get_strength();
  void set_monster(int index);
  void take_attack(int strength);
  void set_game_level(int _game_level);

  ~Machine();
};

#endif