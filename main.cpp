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

int main() 
{
    bool playAgain = true;  
    cout << "\n\t\tWelcome to Tic-Tac-Toe!" << endl;

    while (playAgain) 
    {
        Board board;  
        GameState game_state(&board);
        Console console(&board);
        
        bool valid = false;
      
        while (!valid) 
        {
            string ans;
            
            cout << "Do you want to play \"regular\" or \"battle\" Tic-Tac-Toe?" << endl;
            cin >> ans;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
         
            if (ans == "regular") 
            {
                valid = true;
                Human_Player player_one(&board, 'X');
                Human_Player player_two(&board, 'O');
                Game game(&console, &game_state, &player_one, &player_two);

                cout << "Starting Regular Tic-Tac-Toe game!" << endl;
                game.start();
                cout << console.display() << endl;
            } 
            else if (ans == "battle") 
            {
                valid = true;
                string battle_choice1, battle_choice2;
                
               
                while (true) 
                {
                    cout << "Player 1: Choose an archetype: Pyromancer or Swarm?" << endl;
                    cout <<  endl;
                    cout << "Pyromancer: This archetype allows the user to use a special move "
                    "once per game that explode all the current marks on the "
                    "board and resets the board to an empty state" << endl;
                    cout <<  endl;
                    cout << "Swarm: This archetype allows the user to win the game by "
                    "filling in all four corners of the board" << endl;
                    cout <<  endl;
                    cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                    cin >> battle_choice1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                    if (battle_choice1 == "Pyromancer" || battle_choice1 == "Swarm") 
                    {
                        break;  
                    } 
                    else 
                    {
                        cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
                    }
                }

                while (true) 
                {
                    cout << "Player 2: Choose an archetype: Pyromancer or Swarm?" << endl;
                    cout <<  endl;
                    cout << "Pyromancer: This archetype allows the user to use a special move "
                    "once per game that explode all the current marks on the "
                    "board and resets the board to an empty state" << endl;
                    cout <<  endl;
                    cout << "Swarm: This archetype allows the user to win the game by "
                    "filling in all four corners of the board" << endl;
                    cout <<  endl;
                    cout << "(Enter \"Pyromancer\" or \"Swarm\")" << endl;
                    cin >> battle_choice2;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  

           
                    if (battle_choice2 == "Pyromancer" || battle_choice2 == "Swarm") 
                    {
                        break;
                    }
                    else 
                    {
                        cout << "Invalid entry! Please choose 'Pyromancer' or 'Swarm'." << endl;
                    }
                }

                if (battle_choice1 == "Pyromancer") 
                {
                    if (battle_choice2 == "Swarm") 
                    {
                        Pyromancer player_one(&board, 'X');
                        Swarm player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                        cout << console.display() << endl;
                    } 
                    else 
                    {
                        Pyromancer player_one(&board, 'X');
                        Pyromancer player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                        cout << console.display() << endl;
                    }
                } 
                else if (battle_choice1 == "Swarm")
                 {
                    if (battle_choice2 == "Pyromancer") 
                    {
                        Swarm player_one(&board, 'X');
                        Pyromancer player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                        cout << console.display() << endl;
                    } 
                    else
                    {
                        Swarm player_one(&board, 'X');
                        Swarm player_two(&board, 'O');
                        Game game(&console, &game_state, &player_one, &player_two);
                        cout << "Starting Battle Tic-Tac-Toe!" << endl;
                        game.start();
                        cout << console.display() << endl;
                    }
                }
            } 
            else 
            {
                cout << "Invalid entry! Please choose 'regular' or 'battle'." << endl;
            }
        }
        char replayAnswer;
        bool validAnswer = false;
        while (!validAnswer) 
        {
            cout << "Do you want to play again? (Y/N): ";
            cin >> replayAnswer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            replayAnswer = toupper(replayAnswer);  
            
            if (replayAnswer == 'Y') 
            {
                validAnswer = true;
                playAgain = true;  
            } 
            else if (replayAnswer == 'N') 
            {
                validAnswer = true;
                playAgain = false;  
                cout << "Thank you for playing! Goodbye!" << endl;
            } 
            else 
            {
                cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
            }
        }
    }

    return 0;
}
