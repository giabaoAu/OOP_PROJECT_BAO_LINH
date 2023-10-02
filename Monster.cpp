#include "Monster.h"

Monster::Monster(int health, int strenght, int critical_attack)
    : health(health), strength(strength), critical_attack(critical_attack) {}

Monster::Monster(int health, int strength): health(health), strength(strength) {}

void Monster::set_strength(int new_strength) { strength = new_strength; }

void Monster::set_health(int new_health) { health = new_health; }

void Monster::set_critical_attack(int new_critical_attack) {
  critical_attack = new_critical_attack;
}

int Monster::get_strength() { return strength; }

int Monster::get_health() { return health; }

int Monster::get_critical_attack() { return critical_attack; }

//int Monster::get_monster_level() { return Player::get_player_level(); }
// string Monster::get_monster_type(){return monster_type;}

void Monster::reset() {
  set_strength(get_strength() - 10);
  set_health(210 + ((Player::get_player_level() -1) * 45)); // -1 bc level 1 was not added with 45
  set_critical_attack(get_critical_attack() + 10);
}

void Monster::reFill() {
  set_strength(get_strength() + 10);
  set_health(get_health() + 10);
  set_critical_attack(get_critical_attack() + 10);
}

int Monster::attack(int attack_type, string opponent_type) { return 0; }
