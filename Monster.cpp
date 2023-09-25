#include "Monster.h"
#include "Player.h"
void Monster::set_strength() {
    this->strength = get_player_level(); 
}


void Monster::set_health() {
    this->health= get_player_level();
}

void Monster::reFill() {
    set_strength(get_player_level());
    set_health(get_player_level());
}

int Monster::attack() { return 0; }
