#ifndef PLAYER_H
#define PLAYER_H

#include "Player.h"
#include "Machine.h"
#include "Monster.h"
#include "abyssGame.h"
#include <string>

using namespace std;
class Player {
 private:
  string user_name;
  Monster** monster_list;
  int current_monster;
  int attack_type; 
  int coins;
  static int player_level;
  
  public: 
  Player();
  Player(string user_name);
  void set_monster(string monster_name);
  static int get_player_level();
  void attack(Monster** monster_list, Machine* opponent, int attack_type);
  void take_attack(int strength);
  void level_up();
  void reset();
  void draw(RenderWindow * win);
  ~Player();
  
};

#endif