#ifndef AQUA_H
#define AQUA_H

#include "Monster.h"

class Aqua: public Monster{
private:
public:
Aqua();
int attack(int attack_type, string opponent_type);
};

#endif