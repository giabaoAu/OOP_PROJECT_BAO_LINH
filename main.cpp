#include <string>

#include "Machine.h"
#include "abyssGame.h"
using namespace std;
string Machine::monster_type;
int Machine::game_level;
int main() {
  cout << "1. New game" << endl;
  cout << "2. Load game" << endl;
  int option;
  while (true) {
    cin >> option;
    if (cin.fail() || (option != 1 && option !=2)) {
      cout << "Please enter number 1 or 2" << endl;
      cin.clear();
      cin.ignore();
    } else if (option == 1 || option == 2) { 
      break;
    }
  }
  abyssGame game;
  if (option == 1) {
    game.new_game();
    game.go_battle();
  }

  
  return 0;
}