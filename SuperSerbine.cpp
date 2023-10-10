#include "SuperSerbine.h"

SuperSerbine::SuperSerbine() : Serbine() {
  skill_name = "Wind attack";
  monster_level = 2;
  reset();
}

int SuperSerbine::attack(int attack_type, string opponent_type) {
  switch (attack_type) {
    case 1:
      if (opponent_type == "Titan") {
        return (strength * 1.5);
      } else {
        return strength;
      }
      break;
    case 2:
      if (opponent_type == "Titan") {
        health = health - ((0.015 * monster_level) * health);
        return strength * 3;
      } else {
        health = health - ((0.015 * monster_level) * health);
        return strength * 2;
      }
      break;
    case 3:
      if (opponent_type == "Titan") {
        return strength * 2.5;
      } else {
        return strength * 1.8;
      }
      break;
    default:
      return strength;
  }
}