#include <iostream>
#include <limits>
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
  Board board;
  GameState game_state(&board);
  Console console(&board);
  Swarm player_one(&board, 'X');
  Pyromancer player_two(&board, 'O');
   Game game(&console, &game_state, &player_one, &player_two);

cout << "Welcome to Tic-Tac-Toe!" << endl;
string ans;
cout << "Do you want to  play \"regular\" or \"battle\" Tic-Tac-Toe" << endl;
cin >> ans;
while(cin.peek() == '\n')
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid entry!!! Please try again\n";
    cout << "What is your move?\n";
    break;
}
    cin >> ans;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
if(cin.fail())
{
      cout << "Invalid entry!!! Please try again\n";
      cout << "What is your move?\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
     // break;
}
else if(ans == "regular")
{
char ans = 'Y';
while(toupper(ans) == 'Y')
{
  game.start();
  cout << game_state.current_state(&player_two) << endl;
  cout << console.display() << endl; 
  cout << "Play again (Y/N)?" << endl;
  cin >> ans;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  board.clear();
}
}
else
{
  char ans = 'Y';
while(toupper(ans) == 'Y')
{
  game.start();
  cout << game_state.current_state(&player_one) << endl;
  cout << console.display() << endl; 
  cout << "Play again (Y/N)?" << endl;
  cin >> ans;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  board.clear();
}
}
  return 0;
}
