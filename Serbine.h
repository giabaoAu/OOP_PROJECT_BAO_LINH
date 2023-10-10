#ifndef SERBINE_H
#define SERBINE_H

#include "Monster.h"

class Serbine: public Monster{
private:
public:
//Constructor for player monster
Serbine();
//construcor for machine monster
Serbine(int game_level);

void reFill();
void reset();
void reset_for_load(int player_level);
virtual int attack(int attack_type, string opponent_type);
};

#endif