#include "Player.h"
#include "Serbine.h"
#include "Dragon.h"
#include "Aqua.h"
#include "Titan.h"

Player::Player() {}

Player::Player(string user_name) {
    this->user_name = user_name;
    monster_list = new Monster*[4];
    monster_list[0] = new Dragon();
    monster_list[1] = new Titan();
    monster_list[2] = new Aqua();
    monster_list[3] = new Serbine();
}

void Player::set_monster(string monster_name) {
    if (monster_name == "Dragon"){
        this->current_monster = 0;
    }else if (monster_name == "Titan"){
        this->current_monster = 1;
    }else if (monster_name == "Aqua"){
        this->current_monster == 2;
    }else if (monster_name == "Serbine"){
        this->current_monster = 3;
    }
}

int Player::get_player_level() { return player_level; }

void Player::attack(Monster** monster_list, Machine* opponent, int attack_type) {
    int strength = monster_list[current_monster]->attack(attack_type, Machine::get_monster_type());
    opponent->get_monster()->health;
}

void Player::take_attack(int strength) {}

void Player::level_up() {}

void Player::reset() {}

void Player::draw(RenderWindow* win) {}

Player::~Player() {}
