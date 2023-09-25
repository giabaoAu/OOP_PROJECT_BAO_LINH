#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;
class Player {
 private:
  string userName;
  Monster** monster_list;
  int current_monster;
  int attack_type; 
  int coins;
  int player_level;
  
  public: 
  Player();
  Player(string userName);
  void set_monster(string monsterName);
  int get_player_level();
  void attack(Monster** monster_list, int attack_type);
  


};

#endif