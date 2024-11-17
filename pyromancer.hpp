#pragma once

#include "board.hpp"
#include "player.hpp"
#include "winning_combos.hpp"
class Pyromancer :  public Player
{
  Board* board;
  char mark;
  WinningCombos combos;

  public:

  Pyromancer(Board* board, char  mark);
  void get_move() override;
  char get_mark() override;
  WinningCombos get_winning_combos() override;

};