#pragma once
#include <vector>
class WinningCombos
{
    private:
    std::vector<std::vector<int>> winning_combos;

    public:
    WinningCombos();
    WinningCombos(std::vector<int> additional_combo);
    std::vector<std::vector<int>> all();
    
};