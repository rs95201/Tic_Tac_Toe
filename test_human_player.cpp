#include <iostream>
#include "board.hpp"
#include "human_player.hpp"

int main()
{
    Board board;
    Human_Player human(&board, 'X');
    human.get_move();
    return 0;
}
