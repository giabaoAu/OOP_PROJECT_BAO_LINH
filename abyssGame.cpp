#include "abyssGame.h"

abyssGame::abyssGame() {}

void abyssGame::new_game() {
    cout<<"Creating a new game ............." <<endl;
    sleep(2);
    cout<<"Create game player ............" <<endl;
    sleep(1);
    string player_name;
    cout<<"Please enter an user name (no longer than 20 characters)"<<endl;
    while(true){
        cin>>player_name;
        if(player_name.length() < 21){
            break;
        }
        cout<<"Invalid user name. Please enter no more than 20 characters"<<endl;
    }
    game_player = new Player(player_name);
    cout<<"Player created" <<endl;
    cout<<"Welcome to The Abyss Game "<<player_name<<" !"<<endl;
    cout<<"Creating monster............."<<endl;
    sleep(2);
    game_machine = new Machine();
    game_machine->set_monster(Machine::get_level());
    cout<<"Level 1 monster created!"<<endl;
    cout<<"Are you ready for the tutorial. Hit enter when you are ready."<<endl;
    cin.ignore();
    cout<<"Begin tutorial"<<endl;
}

void abyssGame::load_game() {}

void abyssGame::save_game() {}
