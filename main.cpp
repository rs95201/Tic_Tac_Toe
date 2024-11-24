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
    Board board;
    GameState game_state(&board);
    Console console(&board);
    
    char ans = 'Y';  // Initially set to 'Y' to start the first game
    bool valid = false;

    while (toupper(ans) == 'Y') {  // Continue playing as long as the player wants to
        valid = false;

        // Game mode selection loop
        while (!valid) {
            string ans;
            cout << "Welcome to Tic-Tac-Toe!" << endl;
            cout << "Do you want to play \"regular\" or \"battle\" Tic-Tac-Toe?" << endl;
            cin >> ans;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Player 2: Do you want to play as Pyromancer or Swarm?" << endl;
                cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                cin >> battle_choice2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

        // Ask the player if they want to play again
        bool valid_answer = false;
        while (!valid_answer) {
            cout << "Do you want to play again? (Y/N): ";
            cin >> ans;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear any extra newline characters
            ans = toupper(ans);  // Convert input to uppercase to handle case insensitivity
            
            if (ans == 'Y' || ans == 'N') {
                valid_answer = true;  // Valid answer, exit the loop
            } else {
                cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
            }
        }

        // If 'N' is chosen, exit the game
        if (ans == 'N') {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
