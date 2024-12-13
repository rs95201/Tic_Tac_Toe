#include "game_state.hpp"

GameState::GameState(Board* board)
{
    this->board = board;
}

bool GameState::winning_combo(std::vector<int> combo) {
    if (combo.empty()) return false;

    char first_mark = board->get_mark(combo[0]);
    if (first_mark != 'X' && first_mark != 'O') return false; 

    for (size_t i = 1; i < combo.size(); ++i) {
        if (board->get_mark(combo[i]) != first_mark) {
            return false;
        }
    }
    return true;
}


std::string GameState::select_winner(int cell)
{
    std::string output = "";
    output += board->get_mark(cell);
    output += " wins";
    return output;
}
std::string GameState::current_state(Player *current_player) 
{
  std::vector<std::vector<int>> combos = current_player->get_winning_combos().all();
  std::vector<std::vector<int>>::iterator combo_iterator;

  for (combo_iterator = combos.begin(); combo_iterator != combos.end(); combo_iterator++)
  {
    if (this->winning_combo(*combo_iterator))
    {
      return select_winner(combo_iterator->at(0));
    }
  }
    bool is_board_full = true;
    for (int i = 1; i <= 9; ++i) 
    {
        if (board->get_mark(i) == '1' || board->get_mark(i) == '2' || 
            board->get_mark(i) == '3' || board->get_mark(i) == '4' || 
            board->get_mark(i) == '5' || board->get_mark(i) == '6' || 
            board->get_mark(i) == '7' || board->get_mark(i) == '8' || 
            board->get_mark(i) == '9') 
        {
            is_board_full = false; 
            break;
        }
    }
    if (is_board_full) 
    {
        return "It's a tie!";
    }

    return "in-progress"; 
}
