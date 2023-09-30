#include "Dragon.h"
Dragon::Dragon() : Monster(210, 15, 30) {}

Dragon::Dragon(int game_level)
    : Monster(400 + ((Machine::get_level() - 1) * 200),
              10 + ((Machine::get_level() - 1) * 10)) {}

int Dragon::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "wind") {
        return strength * 1.5;
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "wind") {
        return strength * 3;
        health -= round((0.015 * Player::get_player_level()) * health);
      } else {
        return strength * 2;
        health -= round((0.015 * Player::get_player_level()) * health);
      }
      break;
  }
}

void Dragon::reFill() {
  set_strength(get_strength() + 15);
  set_health(get_health() + 45);
  set_critical_attack(get_critical_attack() + 15);
}

void Dragon::reset() {
  set_strength(15 + ((Player::get_player_level() - 1) * 15));
  set_health(210 + ((Player::get_player_level() - 1) * 45));
  set_critical_attack(30 + ((Player::get_player_level() - 1) * 15));
}
