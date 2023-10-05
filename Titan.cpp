#include "Titan.h"

Titan::Titan() : Monster(250, 10, 25) {}

Titan::Titan(int game_level)
    : Monster(400 + ((game_level - 1) * 200),
              10 + ((game_level - 1) * 10)) {}

int Titan::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Aqua") {
        return (strength * 1.5);
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Aqua") {
        return (strength * 3);
        health -= round((0.015 * monster_level) * health);
      } else {
        return (strength * 2);
        health -= round((0.015 * monster_level) * health);
      }
      break;
    default:
      return strength;
  }
}

void Titan::reFill() {
  set_strength(get_strength() + 10);
  set_health(get_health() + 60);
  set_critical_attack(get_critical_attack() + 10);
}

void Titan::reset() {
  set_strength(15 + ((monster_level - 1) * 10));
  set_health(250 + ((monster_level - 1) * 60));
  set_critical_attack(25 + ((monster_level - 1) * 10));
}
