#include "abyssGame.h"

abyssGame::abyssGame() {}

void abyssGame::new_game() {
  cout << "Creating a new game ............." << endl;
  sleep(1);
  cout << "Creating your character ............" << endl;
  sleep(1);
  string player_name;
  cout << "Enter your character name (no longer than 20 characters)" << endl;
  while (true) {
    cin >> player_name;
    if (player_name.length() < 21) {
      break;
    }
    cout << "Invalid user name! Please enter no more than 20 characters";
  }
  game_player = new Player(player_name);
  cout << "A tarnished has risen up from the ashes ..." << endl;
  sleep(1);
  cout << "Welcome to The Abyss, " << player_name << "!" << endl;
  sleep(1);
  cout << "Thy monster are being called............." << endl;
  sleep(1);
  game_machine = new Machine();
  srand(time(0));
  int index = 0 + (rand() % 4);
  game_machine->set_monster(index);  // result in seg fault - solved
  cout << "Level 1 monster created!" << endl;
  cout << "Begin tutorial" << endl;
}

void abyssGame::go_battle() {
  cout << "The machine monster type is: " << Machine::monster_type << endl;
  cout << "Choose your monster type wisely! Enter the name of the monster: ";
  string player_monster_type;
  while (true) {
    cin >> player_monster_type;
    bool check;
    check = game_player->set_monster(player_monster_type);
    if (check) {
      break;
    }
  }
  cout << "ALL SET. GAME START IN ........ " << endl;
  cout << "3" << endl;
  cout << "2" << endl;
  cout << "1" << endl;
  cout << "Player go first. Choose your attack type: ";
  cout << "1. Normal attack" << endl;
  cout << "2. Critical attack" << endl;
  int attack_type;
  while (true) {
    cin >> attack_type;
    if (cin.fail() || (attack_type != 1 && attack_type != 2)) {
      cout << "Please enter number 1 or 2" << endl;
      cin.clear();
      cin.ignore();
    } else if (attack_type == 1 || attack_type == 2) {
      break;
    }
  }
  game_player->attack(game_machine, attack_type);
  cout<<"Machine turn"<<endl;
  game_player->take_attack(game_machine->get_monster()->get_strength());
  cout<<"You take "<<game_machine->get_monster()->get_strength()<<"damage. Remained health: ";
}

void abyssGame::load_game() {}

void abyssGame::save_game() {}
