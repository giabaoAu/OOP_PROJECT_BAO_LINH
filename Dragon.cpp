#include "Dragon.h"

Dragon::Dragon() {}

int Dragon::attack(int attack_type, string opponent_type) {
  switch (attack_type)
  case 1:
    if (opponent_type == "wind") {
      return strength * 1.5;
    } else {
      return strength;
      break;

      case 2:
        if (opponent_type == "wind") {
          return strength * 3;
          health -= (0.015 * monster_level) * health;
        } else {
          return strength * 2;
          health -= (0.015 * monster_level) * health;
        }
        break;
    }
}