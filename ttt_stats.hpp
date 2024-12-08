#pragma once
#include <string>
using namespace std;
class TTT
{
private:
    int num_of_games;
    int player1_wins;
    int player2_wins;
    int num_of_ties;

public:
    TTT(int num_of_games = 0, int player1_wins = 0, 
        int player2_wins = 0, int num_of_ties = 0);

    void stats(const string& result);

    int get_num_of_games();
    int get_player1_wins();
    int get_player2_wins();
    int get_num_of_ties();
};
