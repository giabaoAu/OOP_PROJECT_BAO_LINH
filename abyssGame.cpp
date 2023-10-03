#include "abyssGame.h"

abyssGame::abyssGame() {}

void abyssGame::new_game() {
    cout<<"Creating a new game ............." <<endl;
    sleep(1);
    cout<<"Create game player ............" <<endl;
    sleep(1);
    string player_name;
    cout<<"Please enter an user name (no longer than 20 characters)"<<endl;
    while(true){
        cin>>player_name;
        if(player_name.length() < 21){
            break;
        }
        cout<<"Invalid user name. Please enter no more than 20 characters";
    }
    game_player = new Player(player_name);
    cout<<"Player created" <<endl;
    sleep(1);
    cout<<"Welcome to The Abyss Game "<<player_name<<" !"<<endl;
    sleep(1);
    cout<<"Creating monster............."<<endl;
    sleep(1);
    game_machine = new Machine();
    game_machine->set_monster(Machine::game_level); //result in seg fault - solved
    cout<<"Level 1 monster created!"<<endl;
    cout<<"Begin tutorial"<<endl;
}

void abyssGame::load_game() {}

void abyssGame::save_game() {}
