#ifndef AQUA_H
#define AQUA_H

#include "Monster.h"

class Aqua: public Monster{
private:
public:
//Constructor for player monster
Aqua();
//constructor for machine monster
Aqua(int game_level);

void reFill();
void reset();
int attack(int attack_type, string opponent_type);
};

#endif