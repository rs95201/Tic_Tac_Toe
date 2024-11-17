#include <iostream>
#include <limits>

#include "player.hpp"
#include "swarm.hpp"
#include "winning_combos.hpp"

using namespace std;
Swarm::Swarm(Board* board, char mark) 
{
    this->board = board;
    this->mark = mark;
    std::vector<int> additional_win =  {1,3,7,9};
    this->combos = WinningCombos(additional_win);
}
char Swarm::get_mark()
{
    return this->mark;
}
WinningCombos Swarm::get_winning_combos()
{
  return this->combos;
}
void Swarm::get_move()
{
    bool valid = false;
    int value;
    while(!valid)
    {
        cout << "What is your move?\n";
        while(cin.peek() == '\n')
        {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry!!! Please try again\n";
        cout << "What is your move?\n";
        break;
        }
        cin >> value;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cin.fail())
        {
            cout << "Invalid entry!!! Please try again\n";
            cout << "What is your move?\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else if(value < 1 || value > 9)
        {
            cout << "Invalid entry!!! Please try again\n";
            continue;
        }
        if(board->get_mark(value) == 'X' or board->get_mark(value) == 'O' )
        {
            cout << "That postition is already taken!Please try again\n";
        }
        else
        {
            board->move(value, mark);
            valid = true; 
        }
    }
    
}
