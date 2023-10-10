#ifndef SUPERTITAN_H
#define SUPERTITAN_H

#include "Titan.h"
#include <string>

using namespace std;

class SuperTitan:public Titan {
    private:
    public:
    SuperTitan();
    int attack(int attack_type, string opponent_type);
};

#endif