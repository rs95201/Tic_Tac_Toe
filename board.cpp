#include "board.hpp"

void Board::move(int i, char m)
{
    if(i > 0 && i < 10)
    {
        moves[i-1] = m;
    }
}
char Board::get_mark(int i)
{
    return moves.at(i-1); 
}
void Board::clear()
{
    moves = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
}
