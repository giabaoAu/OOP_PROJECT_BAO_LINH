#ifndef SUPERDRAGON_H
#define SUPERDRAGON_H

#include "Dragon.h"
#include <string>

using namespace std;

class SuperDragon:public Dragon {
    private:
    public:
    SuperDragon();
    int attack(int attack_type, string opponent_type);
};
#endif