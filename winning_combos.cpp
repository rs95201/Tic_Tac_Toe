#include "winning_combos.hpp"

WinningCombos::WinningCombos()
{
    // Direct initialization of each combo
    std::vector<int> combo_one = {1, 2, 3};
    this->winning_combos.push_back(combo_one);

    std::vector<int> combo_two = {4, 5, 6};
    this->winning_combos.push_back(combo_two);

    std::vector<int> combo_three = {7, 8, 9};  // Fixed repeated value error
    this->winning_combos.push_back(combo_three);

    std::vector<int> combo_four = {1, 4, 7};
    this->winning_combos.push_back(combo_four);

    std::vector<int> combo_five = {2, 5, 8};
    this->winning_combos.push_back(combo_five);

    std::vector<int> combo_six = {3, 6, 9};
    this->winning_combos.push_back(combo_six);

    std::vector<int> combo_seven = {1, 5, 9};
    this->winning_combos.push_back(combo_seven);

    std::vector<int> combo_eight = {3, 5, 7};
    this->winning_combos.push_back(combo_eight);
}

// Constructor to add an additional combo
WinningCombos::WinningCombos(std::vector<int> additional_combo)
{
    // Directly add the default combos
    this->winning_combos.push_back({1, 2, 3});
    this->winning_combos.push_back({4, 5, 6});
    this->winning_combos.push_back({7, 8, 9});
    this->winning_combos.push_back({1, 4, 7});
    this->winning_combos.push_back({2, 5, 8});
    this->winning_combos.push_back({3, 6, 9});
    this->winning_combos.push_back({1, 5, 9});
    this->winning_combos.push_back({3, 5, 7});

    // Add the additional combo
    this->winning_combos.push_back(additional_combo);
}

std::vector<std::vector<int>> WinningCombos::all()
{
    return this->winning_combos;
}
