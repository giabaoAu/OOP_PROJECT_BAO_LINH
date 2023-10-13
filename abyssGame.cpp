#include "abyssGame.h"

#include <fstream>

// Abyss game constructor
abyssGame::abyssGame() {}

// This is the game menu function which show intuitive and functional user menu
int abyssGame::game_menu() {
  cout << "GAME MENU:" << endl;
  cout << "1. Go to battle" << endl;
  cout << "2. Level up" << endl;
  cout << "3. Quit and Save" << endl;
  cout << "Please choose 1, 2 or 3: ";
  // The player has 3 options to choose from the user menu. The program will
  // receive input from the user The program has exceptional handling technique
  // to check if the user entered correct integer
  int option;
  while (true) {
    cin >> option;
    if (cin.fail() || (option != 1 && option != 2 && option != 3)) {
      cout << "Please enter number 1, 2 or 3." << endl;
      cin.clear();
      cin.ignore();
    } else if (option == 1 || option == 2 || option == 3) {
      break;
    }
  }
  return option;
}

// New game function is used when the user first started the game ie. user
// choose to play new game rather than load an existing game from the folder
void abyssGame::new_game() {
  cout << "Creating a new game ............." << endl;
  sleep(1);
  cout << "Creating your character ............" << endl;
  sleep(1);
  // error when player name has space
  char player_name[21];
  cout << "Enter your character name (no longer than 20 characters)" << endl;
  // while (true) {
  cin.getline(player_name, 21);
  // if (player_name.length() < 21) {
  cin.ignore(numeric_limits<streamsize>::max(), ' ');
  //     break;
  //   }
  //   cout << "Invalid user name! Please enter no more than 20 characters";
  // }
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

// Go_battle is the function used when the user started the battle with Machine
// ie. user choose the option 1 in the user menu
void abyssGame::go_battle() {
  // Machine monster will be chosen randomly each new battle
  srand(time(NULL));
  int index = 0 + (rand() % 4);
  if (game_machine->game_level != 1) {
    delete game_machine->get_monster();
  }
  game_machine->set_monster(index);

  // Player will be notified which mosnter type the machine use and therefore
  // prompt to choose a type they will use in the battle The program use
  // execptional handling to ensure that the player enter the name of the
  // monster type correctly ERROR: space in name
  cout << "The machine monster type is: " << Machine::monster_type
       << ". Health: " << game_machine->get_monster()->get_health() << endl;
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

  // Battle loop: The player goes first each battle
  while (true) {
    cout << "Player turn. Choose your attack type: " << endl;
    sleep(1);
    cout << "1. Normal attack" << endl;
    cout << "2. Critical attack" << endl;
    if (game_player->get_player_level() >= 5) {
      cout << "3. "
           << game_player
                  ->get_monster_list()[game_player->get_current_monster()]
                  ->get_skill_name()
           << endl;
    }
    int attack_type;
    // Exceptional handling for attack type. Check if player enter the correct
    // number Attack type 3 will only appear when user reach level 5.
    while (true) {
      cin >> attack_type;
      if (cin.fail() ||
          (attack_type != 1 && attack_type != 2 && attack_type != 3)) {
        if (game_player->get_player_level() < 5) {
          cout << "Please enter number 1 or 2." << endl;
        } else if (game_player->get_player_level() >= 5) {
          cout << "Please enter number 1, 2 or 3." << endl;
        }
        cin.clear();
        cin.ignore();
      } else if (attack_type == 1 || attack_type == 2 || attack_type == 3) {
        break;
      }
    }

    // Display in terminal player attack damage annd machine remained health
    // based on different attack type the user chose
    int strength = game_player->attack(game_machine, attack_type);
    if (attack_type == 1) {
      game_player->display_attack(strength);
      cout << "Machine remained health: "
           << game_machine->get_monster()->get_health() << endl;
    } else if (attack_type == 2) {
      game_player->display_attack(strength);
      cout << "Machine remained health: "
           << game_machine->get_monster()->get_health() << "." << endl;
      cout << "You lose: "
           << round(
                  ((0.015 * game_player->get_player_level()) *
                   game_player
                       ->get_monster_list()[game_player->get_current_monster()]
                       ->get_health()))
           << " health from using critical attack. Your remained health is: "
           << game_player
                  ->get_monster_list()[game_player->get_current_monster()]
                  ->get_health()
           << endl;
    } else if (attack_type == 3) {
      game_player->display_attack(strength);
      cout << "Machine remained health: "
           << game_machine->get_monster()->get_health() << endl;
    }

    //Check if player win the game 
    if (game_machine->get_monster()->get_health() <= 0) {
      cout << "Machine lose" << endl;
      cout << "Your reward: " << game_player->reward(true) << endl;
      cout << "Your current coins: " << game_player->get_coins() << endl;
      game_player->get_monster_list()[game_player->get_current_monster()]
          ->reset();
      // When the player win against level 10 machine then the game
      // User can continue to play and level up their player however, the
      // machine level will remain at level 10
      if (game_machine->game_level == 10) {
        cout << "Game over! Player wins" << endl;
      } else if (game_machine->game_level < 10) {
        game_machine->game_level++;
      }
      break;
    }

    sleep(1);
    cout << "Machine turn" << endl;
    sleep(1);

    // Display in terminal the damage the player took and their remained health
    game_player->take_attack(game_machine->get_strength());
    game_machine->display_attack();
    cout << "Remained health: "
         << game_player->get_monster_list()[game_player->get_current_monster()]
                ->get_health()
         << endl;

    sleep(1);
    //Check if player lose the game
    if (game_player->get_monster_list()[game_player->get_current_monster()]
            ->get_health() <= 0) {
      cout << "Player lose" << endl;
      cout << "Your reward: " << game_player->reward(false) << endl;
      cout << "Your current coins: " << game_player->get_coins() << endl;
      game_player->get_monster_list()[game_player->get_current_monster()]
          ->reset();
      break;
    }
  }
}

// Level up function for player to upgrade their stats ie. choosing option 2 in
// user menu
void abyssGame::level_up() {
  // Reset monster stats  before showing the it to user.
  for (int i = 0; i < 4; i++) {
    game_player->get_monster_list()[i]->reset();
  }
  // Rewrite this to make it shorter - using for loop
  cout << "LEVEL UP PAGE:" << endl;
  cout << "Your current stats: " << endl;
  for (int i = 0; i<4; i++){
  cout<<game_player->get_monster_list()[i]->get_monster_name()<<" - Health: "<< game_player->get_monster_list()[i]->get_health()
       << " - Strength: " << game_player->get_monster_list()[i]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[i]->get_critical_attack() << endl;
  }
  // cout << "Dragon - Health: "
  //      << game_player->get_monster_list()[0]->get_health()
  //      << " - Strength: " << game_player->get_monster_list()[0]->get_strength()
  //      << " - Critical attack: "
  //      << game_player->get_monster_list()[0]->get_critical_attack() << endl;
  // cout << "Titan - Health: " << game_player->get_monster_list()[1]->get_health()
  //      << " - Strength: " << game_player->get_monster_list()[1]->get_strength()
  //      << " - Critical attack: "
  //      << game_player->get_monster_list()[1]->get_critical_attack() << endl;
  // cout << "Aqua - Health: " << game_player->get_monster_list()[2]->get_health()
  //      << " - Strength: " << game_player->get_monster_list()[2]->get_strength()
  //      << " - Critical attack: "
  //      << game_player->get_monster_list()[2]->get_critical_attack() << endl;
  // cout << "Serbine - Health: "
  //      << game_player->get_monster_list()[3]->get_health()
  //      << " - Strength: " << game_player->get_monster_list()[3]->get_strength()
  //      << " - Critical attack: "
  //      << game_player->get_monster_list()[3]->get_critical_attack() << endl;
  cout << "Your coins: " << game_player->get_coins() << endl;
  int level_up_requirement = (game_player->get_player_level() + 1) * 100 - 50;
  cout << "Level up requirement from level " << game_player->get_player_level()
       << " to " << game_player->get_player_level() + 1 << ": "
       << level_up_requirement << endl;
  cout << "Do you want to level up? Type Y/N" << endl;
  string answer;

  // Exceptional handling if user enter different format
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

  // Level up system
  if (answer == "Y") {
    if (game_player->get_coins() >= level_up_requirement) {
      // int new_coin = game_player->get_coins() - level_up_requirement;
      // game_player->set_coins(new_coin);
      game_player->level_up();
      // If the player reach level 5 meaning that their monster type is upgraded
      // to super monster -> delete the old class object and replace it with new
      // super mosnter classes
      if (game_player->get_player_level() == 5) {
        for (int i = 0; i < 4; i++) {
          delete game_player->get_monster_list()[i];
        }
        game_player->get_monster_list()[0] = new SuperDragon();
        game_player->get_monster_list()[1] = new SuperTitan();
        game_player->get_monster_list()[2] = new SuperAqua();
        game_player->get_monster_list()[3] = new SuperSerbine();
      }
      cout << "Level up successful! Your new stat: " << endl;
        for (int i = 0; i<4; i++){
  cout<<game_player->get_monster_list()[i]->get_monster_name()<<" - Health: "<< game_player->get_monster_list()[i]->get_health()
       << " - Strength: " << game_player->get_monster_list()[i]->get_strength()
       << " - Critical attack: "
       << game_player->get_monster_list()[i]->get_critical_attack() << endl;
  }
      // cout << "Dragon - Health: "
      //      << game_player->get_monster_list()[0]->get_health()
      //      << " - Strength: "
      //      << game_player->get_monster_list()[0]->get_strength()
      //      << " - Critical attack: "
      //      << game_player->get_monster_list()[0]->get_critical_attack() << endl;
      // cout << "Titan - Health: "
      //      << game_player->get_monster_list()[1]->get_health()
      //      << " - Strength: "
      //      << game_player->get_monster_list()[1]->get_strength()
      //      << " - Critical attack: "
      //      << game_player->get_monster_list()[1]->get_critical_attack() << endl;
      // cout << "Aqua - Health: "
      //      << game_player->get_monster_list()[2]->get_health()
      //      << " - Strength: "
      //      << game_player->get_monster_list()[2]->get_strength()
      //      << " - Critical attack: "
      //      << game_player->get_monster_list()[2]->get_critical_attack() << endl;
      // cout << "Serbine - Health: "
      //      << game_player->get_monster_list()[3]->get_health()
      //      << " - Strength: "
      //      << game_player->get_monster_list()[3]->get_strength()
      //      << " - Critical attack: "
      //      << game_player->get_monster_list()[3]->get_critical_attack() << endl;
      cout << "Your remained coins: " << game_player->get_coins() << endl;
    } else if (game_player->get_coins() < level_up_requirement) {
      cout << "Not enough coins" << endl;
    }
  } else if (answer == "N") {
    return;
  }
}

// Save game function
void abyssGame::save_game() {
  ofstream save_file("game_saved.txt");

  if (!save_file.is_open()) {
    cout << "Error! Unable to open saved file. " << endl;
    return;
  }

  // Save player data
  save_file << game_player->get_coins() << endl;
  save_file << game_player->get_player_name() << endl;
  save_file << game_player->get_player_level() << endl;

  // For machine
  save_file << game_machine->game_level;
  // Close the file
  save_file.close();

  cout << "Game saved successfully." << endl;
}

// Load existing game function
abyssGame abyssGame::load_game() {
  ifstream load_file("game_saved.txt");

  // Check if the file is open
  if (!load_file.is_open()) {
    std::cout << "No saved game found." << std::endl;
    exit(1);
  }

  // Load player data
  string player_name;
  int coins, player_level;

  abyssGame game;

  load_file >> coins >> player_name >> player_level;
  game.game_player = new Player(player_name);
  game.game_player->set_coins(coins);
  game.game_player->set_player_level(player_level);

  // If the loaded game has player level higher than 5, then change the player
  // normal monster class to super monster
  if (game.game_player->get_player_level() >= 5) {
    for (int i = 0; i < 4; i++) {
      delete game.game_player->get_monster_list()[i];
    }
    game.game_player->get_monster_list()[0] = new SuperDragon();
    game.game_player->get_monster_list()[1] = new SuperTitan();
    game.game_player->get_monster_list()[2] = new SuperAqua();
    game.game_player->get_monster_list()[3] = new SuperSerbine();
  }

  // Set the monster stats to current player level
  for (int i = 0; i < 4; i++) {
    game.game_player->get_monster_list()[i]->set_monster_level(player_level);
    game.game_player->get_monster_list()[i]->reset_for_load(player_level);
  }

  int game_level;
  load_file >> game_level;
  // Load machine data
  game.game_machine = new Machine();
  game.game_machine->set_game_level(game_level);
  // Set monster first so that go_battle delete function wont create seg fault
  game.game_machine->set_monster(1);

  // Close the file
  load_file.close();

  cout << "Game loaded successfully." << endl;

  return game;
}