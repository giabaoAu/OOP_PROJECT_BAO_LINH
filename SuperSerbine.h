#ifndef SUPERSERBINE_H
#define SUPERSERBINE_H

#include "Serbine.h"
#include <string>

using namespace std;

class SuperSerbine: public Serbine {
    private:
    public:
    SuperSerbine();
    int attack(int attack_type, string opponent_type);
};

#endif