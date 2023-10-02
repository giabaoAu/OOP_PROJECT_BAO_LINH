#ifndef ABYSSGAME_H
#define ABYSSGAME_H

#include "Player.h"
#include "Machine.h"
#include "Monster.h"
#include "Serbine.h"
#include "abyssGame.h"
#include "Dragon.h"
#include "Titan.h"
#include "Aqua.h"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

class abyssGame{
    private:
    Player * game_player;
    Machine * game_machine;
    public:
    abyssGame();
    void new_game();
    void load_game();
    void save_game();

};
#endif