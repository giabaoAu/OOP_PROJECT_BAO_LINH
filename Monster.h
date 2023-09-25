#ifndef MONSTER_H
#define MONSTER_H
#include <string>

using namespace std;
class Monster {
  private:
  string monster_type;
  int health;
  int strength;
  public:
  virtual void set_strength();
  virtual void set_health();
    
  void reFill();
  virtual int attack() = 0;  
};

#endif