#include <iostream>
#include <string>
#include <limits>
#include <ios>

using namespace std;

int main() {
//   string name;

//   cout << "Enter your first name" << endl;
//   cin >> name;
  
//   int j = 0;
//   for (int i = 0; i < name.length(); i++){

//   }

//   cout << "Your first name is: " << first_name << endl;

//char first[20], last[20];
string first, last;
  cout << "Please, enter your first name : ";

  cin>>first; 
  cin.ignore(numeric_limits<streamsize>::max(),'\n');   // delete everything until click Enter, only kept the first string 
  cout << "Please, enter your surname: ";
  cin>>last; 
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << "Your name is: " << first << last << '\n';

  return 0;
}
