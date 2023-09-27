#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Player.h"
using namespace std;
class Monster {
  protected:
  int health;
  int strength;
  int monster_level;
  public:
  virtual void set_strength(int new_strength);
  virtual void set_health(int new_health);
  int get_strength();
  int get_health();
  void reFill();
  virtual int attack(int attack_type, string opponent_type) = 0;  
};
#endif