#ifndef ABYSSGAME_H
#define ABYSSGAME_H

#include "Player.h"
#include "Machine.h"
#include "Monster.h"
#include <time.h>
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
    int game_menu();
    void new_game();
    void go_battle();
    abyssGame load_game();
    void level_up();
    void save_game();

};
#endif