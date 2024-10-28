#include <iostream>
#include <limits>
#include <cctype>
#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "game.hpp"
using namespace std;
int main()
{
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  Board board;
  GameState game_state(&board);
  Console console(&board);
  Human_Player player_one(&board, 'X');
  Human_Player player_two(&board, 'O');
  Human_Player current_player = player_one;
  Game game(&game_state, &console,  &player_one, &player_two, &current_player);

char ans = 'Y';
while(toupper(ans) == 'Y')
{
    game.start();
  cout << game_state.current_state() << endl;
  cout << console.display() << endl; 
  cout << "Play again (Y/N)?" << endl;
  cin >> ans;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  board.clear();
}
  
  return 0;
}
