#ifndef TITAN_H
#define TITAN_H

#include "Monster.h"

class Titan: public Monster{
private:
public:
Titan();
int attack(int attack_type, string opponent_type);
};

#endif