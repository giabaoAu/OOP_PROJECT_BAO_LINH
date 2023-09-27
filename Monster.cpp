#include "Monster.h"
#include "Player.h"
void Monster::set_strength(int new_strength) {
    this->strength = new_strength; 
}

// 
void Monster::set_health(int new_health) {
    this->health = new_health;
}
int Monster::get_strength(){return strength;}

int Monster::get_health(){return health;}

//string Monster::get_monster_type(){return monster_type;}

void Monster::reFill() {
    set_strength(Player::get_player_level()* 100 - 20);
    set_health(Player::get_player_level() * 100 - 20);
}

int Monster::attack(int attack_type, string opponent_type) { return 0; }
