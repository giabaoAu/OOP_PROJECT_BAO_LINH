#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Player.h"
using namespace std;
class Monster {
  protected:
  //static int monster_type;
  int health;
  int strength;
  int monster_level; // add them function track level cua monster nguoi choi hay machine
  public:
  virtual void set_strength();
  virtual void set_health();
  int get_strength();
  void reFill();
  //int get_monster_type();
  virtual int attack(int attack_type, int opponent_type) = 0;  
};
#endif