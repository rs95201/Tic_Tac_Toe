#include <iostream>

#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "game.hpp"

int main()
{
  std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
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
  std::cout << game_state.current_state() << std::endl;
  std::cout << "Play again (Y/N)?" << std::endl;
  std::cin >> ans;
  board.clear();
}
  
  return 0;
}
