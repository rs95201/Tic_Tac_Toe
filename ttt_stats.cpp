#include "ttt_stats.hpp" 

TTT::TTT(int num_of_games, int player1_wins, 
        int player2_wins, int num_of_ties) 
        {
          this->num_of_games = num_of_games;
          this-> player1_wins = player1_wins;
          this->player2_wins = player2_wins;
          this->num_of_ties = num_of_ties;
        }
void TTT::stats(const string& result)
    {
        num_of_games++;
        if (result == "X wins")
        {
            player1_wins++;
        }
        else if (result == "O wins")
        {
            player2_wins++;
        }
        else if (result == "It's a tie!")
        {
            num_of_ties++;
        }
    }
    int TTT::get_num_of_games()  
    { 
        return num_of_games; 
    }
    int TTT::get_player1_wins()  
    {
         return player1_wins; 
    }
    int TTT::get_player2_wins()  
    { 
        return player2_wins; 
    }
    int TTT::get_num_of_ties()  
    { 
        return num_of_ties; 
    }


