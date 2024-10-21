#include "game_state.hpp"

GameState::GameState(Board* board): board(board) 
{
    // Initialize winning_combos
    winning_combos[0][0] = 1; winning_combos[0][1] = 2; winning_combos[0][2] = 3; // Top row
    winning_combos[1][0] = 4; winning_combos[1][1] = 5; winning_combos[1][2] = 6; // Middle row
    winning_combos[2][0] = 7; winning_combos[2][1] = 8; winning_combos[2][2] = 9; // Bottom row
    winning_combos[3][0] = 1; winning_combos[3][1] = 4; winning_combos[3][2] = 7; // First column
    winning_combos[4][0] = 2; winning_combos[4][1] = 5; winning_combos[4][2] = 8; // Middle column
    winning_combos[5][0] = 3; winning_combos[5][1] = 6; winning_combos[5][2] = 9; // Last column
    winning_combos[6][0] = 1; winning_combos[6][1] = 5; winning_combos[6][2] = 9; // First diagonal
    winning_combos[7][0] = 3; winning_combos[7][1] = 5; winning_combos[7][2] = 7; // Second diagonal
}


bool GameState::three_in_a_row(int cell_one, int cell_two, int cell_three)
{
	return(board->get_mark(cell_one) == board->get_mark(cell_two) && board->get_mark(cell_two) == board->get_mark(cell_three));
}
std::string GameState::select_winner(int cell)
{
    std::string output = "";
    output += board->get_mark(cell);
    output += " wins";
    return output;
}
std::string GameState::current_state() {
    // Check for a winning combination
    for (int i = 0; i < 8; ++i) {
        if (three_in_a_row(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return select_winner(winning_combos[i][0]);
        }
    }

    // Check if the board is full
    bool is_board_full = true;
    for (int i = 1; i <= 9; ++i) {
        if (board->get_mark(i) == '1' || board->get_mark(i) == '2' || 
            board->get_mark(i) == '3' || board->get_mark(i) == '4' || 
            board->get_mark(i) == '5' || board->get_mark(i) == '6' || 
            board->get_mark(i) == '7' || board->get_mark(i) == '8' || 
            board->get_mark(i) == '9') {
            is_board_full = false; // There's at least one empty spot
            break;
        }
    }

    // If the board is full and there is no winner, it's a tie
    if (is_board_full) {
        return "It's a tie!";
    }

    return "in-progress"; // Game is still ongoing
}
