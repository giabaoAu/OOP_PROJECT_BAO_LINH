#include "Serbine.h"

Serbine::Serbine() : Monster(180, 20, 35) {}

Serbine::Serbine(int game_level)
    : Monster(400 + ((Machine::get_level() - 1) * 200),
              10 + ((Machine::get_level() - 1) * 10)) {}

void Serbine::reFill() {
  set_strength(get_strength() + 20);
  set_health(get_health() + 55);
  set_critical_attack(get_critical_attack() + 20);
}

void Serbine::reset() {
  set_strength(20 + ((Player::get_player_level() - 1) * 20));
  set_health(180 + ((Player::get_player_level() - 1) * 55));
  set_critical_attack(35 + ((Player::get_player_level() - 1) * 20));
  ;
}

int Serbine::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "earth") {
        return strength * 1.5;
      } else {
        return strength;
      }
      break;
    case 2:  // cout terminal telling player how much health they're gonna
             // lose and confirm if they accept.
      if (opponent_type == "earth") {
        return strength * 3;
        health -= round((0.015 * Player::get_player_level()) * health);
      } else {
        return strength * 2;
        health -= round((0.015 * Player::get_player_level()) * health);
      }
      break;
  }
}