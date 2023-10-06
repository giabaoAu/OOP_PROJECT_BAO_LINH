#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <cmath>
using namespace std;
class Monster {
  protected:
  int health;
  int strength;
  int monster_level;
  int critical_attack; 

  public:
  //constructor for player monster 
  Monster(int health, int strength, int critical_attack);
  //constructor for machine monster
  Monster(int health, int strength);

  void set_strength(int new_strength);
  void set_health(int new_health);
  void set_critical_attack(int new_critical_attack);

  int get_strength();
  int get_health();
  int get_critical_attack();
  int get_monster_level();

  virtual void reset();
  virtual void reFill();
  virtual void reset_for_load(int player_level);
  virtual int attack(int attack_type, string opponent_type) = 0;  
};

#endif