#include "abyssGame.h"

abyssGame::abyssGame() {}

int abyssGame::game_menu() {
  cout << "GAME MENU:" << endl;
  cout << "1. Go to battle" << endl;
  cout << "2. Level up" << endl;
  cout << "Please choose 1 or 2: ";
  int option;
  while (true) {
    cin >> option;
    if (cin.fail() || (option != 1 && option != 2)) {
      cout << "Please enter number 1 or 2." << endl;
      cin.clear();
      cin.ignore();
    } else if (option == 1 || option == 2) {
      break;
    }
  }
  if (option == 1) {
    return 1;
  } else if (option == 2) {
    return 2;
  }
}

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
  cout << "The machine monster type is: " << Machine::monster_type
       << ". Health: " << endl;
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
      int new_coins =
          game_player->get_coins() + (game_machine->game_level * 60 + 100);
      game_player->set_coins(new_coins);
      cout << "Your reward: " << new_coins << endl;
      game_machine->game_level++;
      game_player->get_monster_list()[game_player->get_current_monster()]
          ->reFill();
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
      int new_coins =
          game_player->get_coins() + (game_machine->game_level * 30 + 30);
      game_player->set_coins(new_coins);
      cout << "Your reward: " << new_coins << endl;
      game_player->get_monster_list()[game_player->get_current_monster()]
          ->reFill();
      break;
    }
  }
}
void abyssGame::load_game() {}

void abyssGame::level_up() {
  cout << "LEVEL UP PAGE:" << endl;
  cout << "Your current stat: " << endl;
  cout << "Dragon - Health: "
       << game_player->get_monster_list()[0]->get_health()
       << " - Strength: " << game_player->get_monster_list()[0]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[0]->get_critical_attack() << endl;
  cout << "Titan - Health: " << game_player->get_monster_list()[1]->get_health()
       << " - Strength: " << game_player->get_monster_list()[1]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[1]->get_critical_attack() << endl;
  cout << "Aqua - Health: " << game_player->get_monster_list()[2]->get_health()
       << " - Strength: " << game_player->get_monster_list()[2]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[2]->get_critical_attack() << endl;
  cout << "Serbine - Health: "
       << game_player->get_monster_list()[3]->get_health()
       << " - Strength: " << game_player->get_monster_list()[3]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[3]->get_critical_attack() << endl;
  cout << "Your coins: " << game_player->get_coins() << endl;
  int level_up_requirement = (game_player->get_player_level() + 1) * 100 - 50;
  cout << "Level up requirement from level " << game_player->get_player_level()
       << " to " << game_player->get_player_level() + 1 << ": "
       << level_up_requirement << endl;
  cout << "Do you want to level up? Type Y/N" << endl;
  string answer;
  while (true) {
    cin >> answer;
    if (cin.fail() || (answer != "Y" && answer != "N")) {
      cout << "Please choose again. Type Y/N" << endl;
    } else if (answer == "Y" || answer == "N") {
      break;
    }
  }
  cout << "Loading......................" << endl;
  sleep(1);
  if (answer == "Y") {
    if (game_player->get_coins() >= level_up_requirement) {
      int new_coin = game_player->get_coins() - level_up_requirement;
      game_player->set_coins(new_coin);
      game_player->level_up();
      cout << "Level up successful! Your new stat: " << endl;
      cout << "Dragon - Health: "
           << game_player->get_monster_list()[0]->get_health()
           << " - Strength: "
           << game_player->get_monster_list()[0]->get_strength()
           << " - Critical attack: "
           << game_player->get_monster_list()[0]->get_critical_attack() << endl;
      cout << "Titan - Health: "
           << game_player->get_monster_list()[1]->get_health()
           << " - Strength: "
           << game_player->get_monster_list()[1]->get_strength()
           << " - Critical attack: "
           << game_player->get_monster_list()[1]->get_critical_attack() << endl;
      cout << "Aqua - Health: "
           << game_player->get_monster_list()[2]->get_health()
           << " - Strength: "
           << game_player->get_monster_list()[2]->get_strength()
           << " - Critical attack: "
           << game_player->get_monster_list()[2]->get_critical_attack() << endl;
      cout << "Serbine - Health: "
           << game_player->get_monster_list()[3]->get_health()
           << " - Strength: "
           << game_player->get_monster_list()[3]->get_strength()
           << " - Critical attack: "
           << game_player->get_monster_list()[3]->get_critical_attack() << endl;
      cout << "Your remained coins: " << game_player->get_coins() << endl;
    } else if (game_player->get_coins() < level_up_requirement) {
      cout << "Not enough coins" << endl;
    }
  } else if (answer == "N") {
    return;
  }
}

void abyssGame::save_game() {}
