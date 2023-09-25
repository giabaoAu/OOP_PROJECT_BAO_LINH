#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"

class Dragon: public Monster{
private:
public:
Dragon();
int attack(int attack_type, string opponent_type);
};

#endif