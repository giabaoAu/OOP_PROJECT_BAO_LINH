#ifndef PLAYER_H
#define PLAYER_H

#include "Machine.h"

#include <string>

using namespace std;
class Player {
 private:
  string user_name;
  Monster** monster_list;
  int current_monster;
  int attack_type; 
  int coins;
  int player_level;
  
  public: 
  Player();
  Player(string user_name);
  void set_monster(string monster_name);
  int get_player_level();
  void attack(Monster** monster_list, int attack_type);
  void take_attack(Machine* opponent, int strength);
  void level_up();
  

};

#endif