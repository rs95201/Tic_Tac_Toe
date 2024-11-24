#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "game.hpp"
#include "swarm.hpp"
#include "pyromancer.hpp"

using namespace std;

int main() {
    bool playAgain = true;  // Track whether the player wants to play again

    while (playAgain) {
        Board board;  // Reinitialize the board for each game
        GameState game_state(&board);
        Console console(&board);
        
        bool valid = false;
        // Game mode selection loop
        while (!valid) {
            string ans;
            cout << "Welcome to Tic-Tac-Toe!" << endl;
            cout << "Do you want to play \"regular\" or \"battle\" Tic-Tac-Toe?" << endl;
            cin >> ans;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear any extra input
            
            // Check for valid game mode
            if (ans == "regular") {
                valid = true;
                Human_Player player_one(&board, 'X');
                Human_Player player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);

                cout << "Starting Regular Tic-Tac-Toe game!" << endl;
                game.start();
            } else if (ans == "battle") {
                valid = true;
                string battle_choice1, battle_choice2;
                
                // Input validation for Player 1 choice
                while (true) {
                    cout << "Player 1: Do you want to play as Pyromancer or Swarm?" << endl;
                    cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                    cin >> battle_choice1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear extra input

                    // Validate input for player 1
                    if (battle_choice1 == "Pyromancer" || battle_choice1 == "Swarm") {
                        break;  // Exit the loop if input is valid
                    } else {
                        cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
                    }
                }

                // Input validation for Player 2 choice
                while (true) {
                    cout << "Player 2: Do you want to play as Pyromancer or Swarm?" << endl;
                    cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                    cin >> battle_choice2;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear extra input

                    // Validate input for player 2
                    if (battle_choice2 == "Pyromancer" || battle_choice2 == "Swarm") {
                        break;  // Exit the loop if input is valid
                    } else {
                        cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
                    }
                }

                // Setup the game based on chosen characters
                if (battle_choice1 == "Pyromancer") {
                    if (battle_choice2 == "Swarm") {
                        Pyromancer player_one(&board, 'X');
                        Swarm player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                    } else {
                        Pyromancer player_one(&board, 'X');
                        Pyromancer player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                    }
                } else if (battle_choice1 == "Swarm") {
                    if (battle_choice2 == "Pyromancer") {
                        Swarm player_one(&board, 'X');
                        Pyromancer player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                    } else {
                        Swarm player_one(&board, 'X');
                        Swarm player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                    }
                }
            } else {
                cout << "Invalid entry! Please choose 'regular' or 'battle'." << endl;
            }
        }
        char replayAnswer;
        bool validAnswer = false;
        while (!validAnswer) {
            cout << "Do you want to play again? (Y/N): ";
            cin >> replayAnswer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            replayAnswer = toupper(replayAnswer);  
            
            if (replayAnswer == 'Y') {
                validAnswer = true;
                playAgain = true;  
            } else if (replayAnswer == 'N') {
                validAnswer = true;
                playAgain = false;  
                cout << "Thank you for playing! Goodbye!" << endl;
            } else {
                cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
            }
        }
    }

    return 0;
}
