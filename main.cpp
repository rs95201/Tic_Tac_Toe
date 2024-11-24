#include <iostream>
#include <limits>
#include <string>
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "game.hpp"
#include "swarm.hpp"
#include "pyromancer.hpp"

using namespace std;

int main() {
    Board board;
    GameState game_state(&board);
    Console console(&board);
    
    string ans;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Do you want to play \"regular\" or \"battle\" Tic-Tac-Toe?" << endl;
    cin >> ans;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    
    if (ans == "regular") {
        Human_Player player_one(&board, 'X');
        Human_Player player_two(&board, 'O');
        Game game(&console, &game_state, &player_one, &player_two);
        
        cout << "Starting Regular Tic-Tac-Toe game!" << endl;
        game.start();
    } 
    
    else if (ans == "battle") {
        string battle_choice1, battle_choice2;
        cout << "Player 1: Do you want to play as Pyromancer or Swarm?" << endl;
        cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
        cin >> battle_choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Player 2: Do you want to play as Pyromancer or Swarm?" << endl;
        cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
        cin >> battle_choice2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        
        
        if (battle_choice1 == "Pyromancer") 
        {
            if(battle_choice2 == "Swarm")
            {
                Pyromancer player_one(&board, 'X');
                Swarm player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);
                cout << "Starting Battle Tic-Tac-Toe!" << endl;
                game.start();

            }
            else
            {
                Pyromancer player_one(&board, 'X');
                Pyromancer player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);
                cout << "Starting Battle Tic-Tac-Toe!" << endl;
                game.start();
                
            }
            
        }
        else if (battle_choice1 == "Swarm") 
        {
            if(battle_choice2 == "Pyromancer")
            {
                Swarm player_one(&board, 'X');
                Pyromancer player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);
                cout << "Starting Battle Tic-Tac-Toe!" << endl;
                game.start();

            }
            else
            {
                Swarm player_one(&board, 'X');
                Swarm player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);
                cout << "Starting Battle Tic-Tac-Toe!" << endl;
                game.start();
                
            }
        }
        else 
        {
            cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
        }
    } 
    else 
    {
        cout << "Invalid entry! Please choose 'regular' or 'battle'." << endl;
    }

    return 0;
}
