#ifndef PLAYER_H
#define PLAYER_H

#include "Machine.h"
#include "Monster.h"
#include <string>
#include <iostream>

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
  
  bool set_monster(string monster_name);
  int get_current_monster();
  int get_player_level();
  
  void attack(Machine* opponent, int attack_type);
  void take_attack(int strength);
  void level_up();
  void reset();
  void reward(bool win);
  //void draw(RenderWindow * win);
  ~Player();
  
};

#endif