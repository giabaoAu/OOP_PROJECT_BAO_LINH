#ifndef SERBINE_H
#define SERBINE_H

#include "Monster.h"

class Serbine: public Monster{
private:
public:
Serbine();
int attack(int attack_type, string opponent_type);
};

#endif