#include <string>
#include <fstream>
#include "Machine.h"
#include "abyssGame.h"
using namespace std;
string Machine::monster_type;
int Machine::game_level;
int main() {
    int total_line = 0;
  string temporary;
  ifstream check("game_saved.txt");
  if (!check.is_open()) {
    std::cout << "No saved game found." << std::endl;
    exit(1);
  }
  while (!check.eof()) {
    getline(check, temporary);
    total_line++;
  }
  check.clear();
  check.seekg(0, ios::beg);
  check.close();

  // Show the game interface when user first load the game. They have 2 options
  if(total_line < 7){
  cout << "1. New game" << endl;
  cout << "2. Load game" << endl;
  }else {
    cout<<"Max database capacity reach"<<endl;
    cout << "1. Load game" << endl;
  }
  int option;
  // Exceptional handling when user either enter string or unexpected integer
  while (true) {
    cin >> option;
    if (cin.fail() || (option != 1 && option != 2)) {
      cout << "Please enter number 1 or 2" << endl;
      cin.clear();
      cin.ignore();
    } else if (option == 1 || option == 2) {
      break;
    }
  }
  // Create game object
  abyssGame game;
  // When the player choose to play a new game. They will be greeted by
  // new_game() function and then be walked through tutorial ie. play against
  // the first level machine monster
  if (option == 1) {
    game.new_game();
    game.go_battle();
    // After the end of tutorial, the player comes back to user menu which have
    // 3 options
    while (true) {
      int option = game.game_menu();
      if (option == 1) {
        game.go_battle();
      } else if (option == 2) {
        game.level_up();
      } else if (option == 3) {
        game.save_game();
        exit(0);
      }
    }
    // if the player choose to load an existing game
  } else if (option == 2) {
    game = game.load_game();  // Load the game and assign it to the existing
                              // game object

    // continue the game
    while (true) {
      int option = game.game_menu();

      if (option == 1) {
        game.go_battle();
      } else if (option == 2) {
        game.level_up();
      } else if (option == 3) {
        game.save_game();
        exit(0);
      }
    }
  }

  return 0;
}