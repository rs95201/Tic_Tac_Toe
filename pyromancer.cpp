#include <iostream>
#include <limits>
#include "pyromancer.hpp"
using namespace std;

Pyromancer::Pyromancer(Board* board, char mark)
{
    this->board = board;
    this->mark = mark;
    this->combos = WinningCombos();
}
char Pyromancer::get_mark()
{
    return this->mark;
}
WinningCombos Pyromancer::get_winning_combos()
{
  return this->combos;
}
void Pyromancer::get_move()
{
    int option;
    bool valid = false;
    while(!valid)
    { 
        cout << "Do you want to (1) enter a cell or (2) explode the board?" << endl;
        while(cin.peek() == '\n')
        {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry!!! Please try again\n";
        cout << "Do you want to (1) enter a cell or (2) explode the board?" << endl;
        break;
        }
    
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid entry!!! Please try again\n";
            cout << "Do you want to (1) enter a cell or (2) explode the board?" << endl;
            continue; 
        }
        if (option == 1 || option == 2) 
        {
            valid = true;  
        } else 
        {
            cout << "Invalid entry!!! Please choose 1 or 2." << endl;
        }
    }
    if (option == 1) 
    {
        cout << "Sounds good! Enter a cell between 1 and 9." << endl;

        bool valid_move = false;
        int value;
        while (!valid_move) {
            cout << "What is your move? (1-9)" << endl;
            cin >> value;
            if (cin.fail()) 
            {
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "Invalid entry!!! Please enter a number between 1 and 9." << endl;
                continue;  
            }
            if (value < 1 || value > 9) 
            {
                cout << "Invalid entry!!! Please enter a number between 1 and 9." << endl;
                continue;
            }
            if (board->get_mark(value) == 'X' || board->get_mark(value) == 'O') 
            {
                cout << "That position is already taken! Please try again." << endl;
            } else 
            {
                board->move(value, mark);
                valid_move = true;  
            }
        }

    } else 
    {  
        cout << "Exploding the board!" << endl;
        this->board->clear();  
    }
}