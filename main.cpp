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
                cout << "Player 1: Do you want to play as Pyromancer or Swarm?" << endl;
                cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                cin >> battle_choice1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear extra input

                cout << "Player 2: Do you want to play as Pyromancer or Swarm?" << endl;
                cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                cin >> battle_choice2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear extra input

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
                } else {
                    cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
                }
            } else {
                cout << "Invalid entry! Please choose 'regular' or 'battle'." << endl;
            }
        }

        // Replay logic
        char replayAnswer;
        bool validAnswer = false;
        while (!validAnswer) {
            cout << "Do you want to play again? (Y/N): ";
            cin >> replayAnswer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear extra input
            replayAnswer = toupper(replayAnswer);  // Convert to uppercase for case insensitivity
            
            if (replayAnswer == 'Y') {
                validAnswer = true;
                playAgain = true;  // Set playAgain to true to continue playing
            } else if (replayAnswer == 'N') {
                validAnswer = true;
                playAgain = false;  // Set playAgain to false to exit
                cout << "Thank you for playing! Goodbye!" << endl;
            } else {
                cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
            }
        }
    }

    return 0;
}
