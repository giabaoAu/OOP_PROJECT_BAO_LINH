#include "Serbine.h"

Serbine::Serbine() {}

int Serbine::attack(int attack_type, string opponent_type) {
  switch (attack_type)
  case 1:
    if (opponent_type == "earth") {
      return strength * 1.5;
    } else {
      return strength;
      break;

      case 2:  // cout terminal telling player how much health they're gonna
               // lose and confirm if they accept.

        if (opponent_type == "earth") {
          return strength * 3;
          health -= (0.015 * monster_level) * health;
        } else {
          return strength * 2;
          health -= (0.015 * monster_level) * health;
        }
        break;
    }
}