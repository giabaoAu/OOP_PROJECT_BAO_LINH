#include "Titan.h"

Titan::Titan() {}

int Titan::attack(int attack_type, string opponent_type) {
  switch (attack_type)
  case 1:
    if (opponent_type == "aqua") {
      return strength * 1.5;
    } else {
      return strength;
      break;

      case 2:
        if (opponent_type == "aqua") {
          return strength * 3;
          health -= (0.015 * monster_level) * health;
        } else {
          return strength * 2;
          health -= (0.015 * monster_level) * health;
        }
        break;
    }
}
