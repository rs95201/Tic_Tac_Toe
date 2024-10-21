#include <iostream>

#include "game.hpp"

Game::Game(GameState* game_state, Console* console, Human_Player* player_one, Human_Player*
player_two, Human_Player* current_player):game_state(game_state), console(console), player_one(player_one),
player_two(player_two), current_player(current_player){};

void Game::start()
{
    while(game_state->current_state() == "in-progress")
    {
        std::cout << console->display();
        current_player->get_move();
        if(current_player->mark == 'X')
        {
            current_player = player_two;
        }
        else
        {
            current_player = player_one;
        }
    }
}
