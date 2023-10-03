#include "Player.h"

Player::Player() {}

Player::Player(string user_name) {
  this->user_name = user_name;
  monster_list = new Monster*[4];
  monster_list[0] = new Dragon();
  monster_list[1] = new Titan();
  monster_list[2] = new Aqua();
  monster_list[3] = new Serbine();
}

void Player::set_monster(string monster_name) {
  if (monster_name == "Dragon") {
    this->current_monster = 0;
  } else if (monster_name == "Titan") {
    this->current_monster = 1;
  } else if (monster_name == "Aqua") {
    this->current_monster == 2;
  } else if (monster_name == "Serbine") {
    this->current_monster = 3;
  }
}

int Player::get_current_monster() { return current_monster; }

int Player::get_player_level() { return player_level; }

void Player::attack(Monster** monster_list, Machine* opponent, int attack_type) {
  int strength = monster_list[current_monster]->attack(attack_type, Machine::monster_type);
  opponent->take_attack(strength);
}

void Player::take_attack(int strength) {
  int new_health = monster_list[current_monster]->get_health();
  monster_list[current_monster]->set_health(new_health);
}

void Player::level_up() {
  if (coins >= (player_level + 1) * 100 - 50) {
    coins -= (player_level + 1) * 100 - 50;
    player_level++;
    for (int i = 0; i < 4; i++) {
      monster_list[i]->reFill();
    }
  }
}

// After each round, the player monsters stat reset to original level (level before the battle)
void Player::reset() {
  monster_list[get_current_monster()]->reFill();
  monster_list[get_current_monster()]->reFill();
}

void Player::reward(bool win) {
  if(win){
    Machine::game_level * 60 + 100;
  }else{
    Machine::game_level * 30 + 30;
  }
}

//void Player::draw(RenderWindow* win) {}

Player::~Player() {}
