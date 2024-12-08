#pragma once
#include "report.hpp"
#include "ttt_stats.hpp"
#include <string>
using namespace std;
Report::Report(TTT* ttt) : ttt(ttt){}

string Report::generate_report() const
{
    string report;
    report += "Number of Games: " + std::to_string(ttt->get_num_of_games()) + "\n";
    report += "Player 1 Wins: " + std::to_string(ttt->get_player1_wins()) + "\n";
    report += "Player 2 Wins: " + std::to_string(ttt->get_player2_wins()) + "\n";
    report += "Number of Ties: " + std::to_string(ttt->get_num_of_ties()) + "\n";
    return report;

}


