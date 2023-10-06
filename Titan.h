#ifndef TITAN_H
#define TITAN_H

#include "Monster.h"

class Titan: public Monster{
private:
public:
//constructor for player monster
Titan();
//constructor for machine monster
Titan(int game_level);

int attack(int attack_type, string opponent_type);
void reFill();
void reset();
void reset_for_load(int player_level);
};

#endif