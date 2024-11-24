/*#include <iostream>
#include <cassert>

#include "board.hpp"
#include "game_state.hpp"

using namespace std;

int main()
{
    Board board;
    GameState gameState(&board);

    board.move(1, 'X');
    board.move(2, 'O');
    assert(gameState.current_state() == "in-progress");
    
    board.clear(); 
    board.move(1, 'X');
    board.move(2, 'X');
    board.move(3, 'X');
    assert(gameState.current_state() == "X wins");

    board.clear(); 
    board.move(1, 'O');
    board.move(4, 'O');
    board.move(7, 'O');
    assert(gameState.current_state() == "O wins");

    
    board.clear(); 
    board.move(1, 'X');
    board.move(5, 'X');
    board.move(9, 'X');
    assert(gameState.current_state() == "X wins");

    
    board.clear(); 
    board.move(1, 'X');
    board.move(2, 'O');
    board.move(3, 'X');
    board.move(4, 'O');
    board.move(5, 'X');
    board.move(6, 'O');
    board.move(7, 'O');
    board.move(8, 'X');
    board.move(9, 'O');
    assert(gameState.current_state() == "It's a tie!"); 

    std::cout << "All tests passed!" << std::endl;
    return 0;


}
*/
