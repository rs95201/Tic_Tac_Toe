#pragma once

#include <string>

#include "board.hpp"

class Human_Player
{
    Board* board;
    public:
    char mark;
    Human_Player(Board *board, char mark);
    void get_move();
};
