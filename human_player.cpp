#include <iostream>
#include <limits>

#include "human_player.hpp"
using namespace std;
Human_Player::Human_Player(Board *board, char mark):board(board), mark(mark){};
void Human_Player::get_move()
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
