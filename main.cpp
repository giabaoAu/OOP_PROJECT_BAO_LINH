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
    if (option == 1 || option == 2) { //error here infinite loop
      break;
    } else {
      cout << "Please enter number 1 or 2" << endl;
    }
  }
  abyssGame game;
  if (option == 1) {
    game.new_game();
  }
  return 0;
}