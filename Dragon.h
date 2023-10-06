#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"

class Dragon: public Monster{
private:
public:
//constructor for player monster
Dragon();
//constructor for machine monster
Dragon(int game_level);

int attack(int attack_type, string opponent_type);
void reFill();
void reset();
void reset_for_load(int player_level);
};

#endif