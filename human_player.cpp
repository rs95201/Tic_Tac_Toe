#include <iostream>
#include <limits>

#include "human_player.hpp"

Human_Player::Human_Player(Board *board, char mark):board(board), mark(mark){};
void Human_Player::get_move()
{
    bool valid = false;
    int value;
    while(!valid)
    {
        std::cout << "What is your move?" << std::endl;
        std::cin >> value;
        if(value < 1 || value > 9)
        {
            std::cout << "Invalid entry!!! Please try again\n";
            continue;
        }
        if(board->get_mark(value) == 'X' or board->get_mark(value) == 'O' )
        {
            std::cout << "That postition is already taken!Please try again\n";
        }
        else
        {
            board->move(value, mark);
            valid = true; 
        }
    }
    
}
