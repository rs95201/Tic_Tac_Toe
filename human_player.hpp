#pragma once

#include <string>

#include "board.hpp"
#include "player.hpp"
#include "winning_combos.hpp"

class Human_Player : public Player
{
    Board* board;
    char mark;
    WinningCombos combos;

  public:

  Human_Player(Board* board, char  m);
  void get_move() override;
  char get_mark() override;
  WinningCombos get_winning_combos() override;
};