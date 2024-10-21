#pragma once

#include "game_state.hpp"
#include "console.hpp"
#include "human_player.hpp"

class Game
{
    GameState* game_state;
    Console* console;
    Human_Player* player_one;
    Human_Player* player_two;
    Human_Player* current_player;
    public:
    
    Game(GameState* game_state, Console* console, Human_Player* player_one, Human_Player* player_two, Human_Player* current_player);
    void start();
};
