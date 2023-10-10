#ifndef SUPERAQUA_H
#define SUPERAQUA_H

#include "Aqua.h"
#include <string>

using namespace std;

class SuperAqua:public Aqua {
    private:
    public:
    SuperAqua();
    int attack(int attack_type, string opponent_type);
};

#endif