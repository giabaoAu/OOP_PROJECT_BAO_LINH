#include "Aqua.h"

Aqua::Aqua() : Monster(160, 25, 40) {}

Aqua::Aqua(int game_level)
    : Monster(400 + ((Machine::get_level() - 1) * 200),
              10 + ((Machine::get_level() - 1) * 10)) {}

void Aqua::reFill() {
  set_strength(get_strength() + 25);
  set_health(get_health() + 35);
  set_critical_attack(get_critical_attack() + 25);
}

void Aqua::reset() {
  set_strength(25 + ((Player::get_player_level() - 1) * 25));
  set_health(160 + ((Player::get_player_level() - 1) * 35));
  set_critical_attack(40 + ((Player::get_player_level() - 1) * 25));
  ;
}

int Aqua::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "fire") {
        return strength * 1.5;
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "fire") {
        return strength * 3;
        health -= round((0.015 * Player::get_player_level()) * health);
      } else {
        return strength * 2;
        health -= round((0.015 * Player::get_player_level()) * health);
      }
      break;
  }
}
