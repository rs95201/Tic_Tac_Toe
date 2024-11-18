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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    // Regular Game - Human vs Human
    if (ans == "regular") {
        Human_Player player_one(&board, 'X');
        Human_Player player_two(&board, 'O');
        Game game(&console, &game_state, &player_one, &player_two);
        
        cout << "Starting Regular Tic-Tac-Toe game!" << endl;
        game.start();
    } 
    // Battle Game - Choose between Pyromancer or Swarm
    else if (ans == "battle") {
        string battle_choice;
        cout << "Do you want to play as Pyromancer or Swarm?" << endl;
        cout << "(Enter 'Pyromancer' or 'Swarm')" << endl;
        cin >> battle_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        
        if (battle_choice == "Pyromancer") {
            Pyromancer player_one(&board, 'X');
            Swarm player_two(&board, 'O');  // You can swap these as needed
            
            Game game(&console, &game_state, &player_one, &player_two);
            cout << "Starting Battle Tic-Tac-Toe as Pyromancer!" << endl;
            game.start();
        }
        else if (battle_choice == "Swarm") {
            Swarm player_one(&board, 'X');
            Pyromancer player_two(&board, 'O');  // You can swap these as needed
            
            Game game(&console, &game_state, &player_one, &player_two);
            cout << "Starting Battle Tic-Tac-Toe as Swarm!" << endl;
            game.start();
        }
        else {
            cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
        }
    } 
    else {
        cout << "Invalid entry! Please choose 'regular' or 'battle'." << endl;
    }

    return 0;
}
