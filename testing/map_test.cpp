#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int testing() {
    //save game
  int total_line = 0;
  string temporary;
  ifstream check;
  check.open("map_test.txt");
  while (!check.eof()) {
    getline(check, temporary);
    total_line++;
  }
  check.close();
  cout << total_line<<endl;;

  if (total_line < 6) {
    ofstream test1;
    test1.open(
        "map_test.txt",
        ios::app);  // apending new element without overwritting the old one
    // test1 << "Bao" << endl;
    // test1 << 100 << endl;  // coins
    // test1 << 3 << endl;    // player level
    // test1 << 3 << endl;    // machine level
    test1 << "Linh" << endl;
    test1 << 10 << endl;  // coins
    test1 << 4 << endl;   // player level
    test1 << 6 << endl;   // machine level
    // test1 << "\n"<<endl;
    test1.close();
  }else{
    cout<<"No more than 2 game saved"<<endl;
  }

  //load game
  ifstream test2("map_test.txt");
  map<string, vector<int>> first_map, second_map;
  vector<int> stats1, stats2;
  string player_name1, player_name2;
  int coins1, player_level1, machine_level1;
  int coins2, player_level2, machine_level2;
  test2 >> player_name1 >> coins1 >> player_level1 >> machine_level1;
  test2 >> player_name2 >> coins2 >> player_level2 >> machine_level2;
  stats1.push_back(coins1);
  stats1.push_back(player_level1);
  stats1.push_back(machine_level1);
  first_map[player_name1] = stats1;

  stats2.push_back(coins2);
  stats2.push_back(player_level2);
  stats2.push_back(machine_level2);
  second_map[player_name2] = stats2;

  cout << "Enter your player name: " << endl;
  string player_name;
  std::getline(std::cin, player_name);
  if (first_map.find(player_name) != first_map.end()) {
    vector<int> tmp = first_map[player_name];
    for (auto i = tmp.begin(); i != tmp.end(); ++i) cout << *i << " ";
  }
  if (second_map.find(player_name) != second_map.end()) {
    vector<int> tmp = second_map[player_name];
    for (auto i = tmp.begin(); i != tmp.end(); ++i) cout << *i << " ";
    int testing = tmp[1];
    cout<<testing<<endl;
  }
}