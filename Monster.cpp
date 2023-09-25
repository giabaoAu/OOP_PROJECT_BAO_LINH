#include "Monster.h"
#include "Player.h"
void Monster::set_strength() {
    this->strength = Player::get_player_level(); 
}

// 
void Monster::set_health() {
    this->health = Player::get_player_level() * 100 - 20;
}
int Monster::get_strength(){return strength;}

//string Monster::get_monster_type(){return monster_type;}

void Monster::reFill() {
    set_strength();
    set_health();
}

int Monster::attack(int attack_type, int opponent_type) { return 0; }
