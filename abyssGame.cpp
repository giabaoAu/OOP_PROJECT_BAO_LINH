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
  cout << "Level 1 monster created!" << endl;
  cout << "Begin tutorial" << endl;
}

void abyssGame::go_battle() {
  srand(time(NULL));  // 3 test deu ra Aqua
  int index = 0 + (rand() % 4);
  game_machine->set_monster(index);
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
  sleep(1);
  cout << "3" << endl;
  sleep(1);
  cout << "2" << endl;
  sleep(1);
  cout << "1" << endl;
  sleep(1);
  while (true) {
    cout << "Player turn. Choose your attack type: " << endl;
    sleep(1);
    cout << "1. Normal attack" << endl;
    cout << "2. Critical attack" << endl;
    int attack_type;
    while (true) {
      cin >> attack_type;
      if (cin.fail() || (attack_type != 1 && attack_type != 2)) {
        cout << "Please enter number 1 or 2." << endl;
        cin.clear();
        cin.ignore();
      } else if (attack_type == 1 || attack_type == 2) {
        break;
      }
    }
    int strength = game_player->attack(game_machine, attack_type);
    if (attack_type == 1) {
      cout << "Your attack damage: " << strength
           << ". Machine remained health: "
           << game_machine->get_monster()->get_health() << endl;
    } else if (attack_type == 2) {
      cout
          << "Your attack damage: " << strength << ". Machine remained health: "
          << game_machine->get_monster()->get_health() << ". You lose: "
          << round(((0.015 * game_player->get_player_level()) *
                    game_player
                        ->get_monster_list()[game_player->get_current_monster()]
                        ->get_health()))
          << " health from using critical attack. Your remained health is: "
          << game_player->get_monster_list()[game_player->get_current_monster()]
                 ->get_health()
          << endl;
    }
    if (game_machine->get_monster()->get_health() <= 0) {
      cout << "Machine lose" << endl;
      break;
    }
    sleep(1);
    cout << "Machine turn" << endl;
    sleep(1);
    game_player->take_attack(game_machine->get_strength());
    cout << "You take " << game_machine->get_strength()
         << " damage. Remained health: "
         << game_player->get_monster_list()[game_player->get_current_monster()]
                ->get_health()
         << endl;
    sleep(1);
    if (game_player->get_monster_list()[game_player->get_current_monster()]
            ->get_health() <= 0) {
      cout << "Player lose" << endl;
      break;
    }
  }
}
void abyssGame::load_game() {}

void abyssGame::save_game() {}
