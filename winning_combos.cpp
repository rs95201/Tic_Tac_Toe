
#include "winning_combos.hpp"

    WinningCombos::WinningCombos()
    {
        std::vector<int> combo_one;
        combo_one.push_back(1);
        combo_one.push_back(2);
        combo_one.push_back(3);
        this->winning_combos.push_back(combo_one);

        std::vector<int> combo_two;
        combo_one.push_back(4);
        combo_one.push_back(5);
        combo_one.push_back(6);
        this->winning_combos.push_back(combo_two);

        std::vector<int> combo_three;
        combo_one.push_back(7);
        combo_one.push_back(8);
        combo_one.push_back(8);
        this->winning_combos.push_back(combo_three);

        std::vector<int> combo_four;
        combo_one.push_back(1);
        combo_one.push_back(4);
        combo_one.push_back(7);
        this->winning_combos.push_back(combo_four);

        std::vector<int> combo_five;
        combo_one.push_back(2);
        combo_one.push_back(5);
        combo_one.push_back(8);
        this->winning_combos.push_back(combo_five);

        std::vector<int> combo_six;
        combo_one.push_back(3);
        combo_one.push_back(6);
        combo_one.push_back(9);
        this->winning_combos.push_back(combo_six);

        std::vector<int> combo_seven;
        combo_one.push_back(1);
        combo_one.push_back(5);
        combo_one.push_back(9);
        this->winning_combos.push_back(combo_seven);

        std::vector<int> combo_eight;
        combo_one.push_back(3);
        combo_one.push_back(5);
        combo_one.push_back(7);
        this->winning_combos.push_back(combo_eight);


    }

    WinningCombos::WinningCombos(std::vector<int> additional_combo)
    {
        std::vector<int> combo_one;
        combo_one.push_back(1);
        combo_one.push_back(2);
        combo_one.push_back(3);
        this->winning_combos.push_back(combo_one);

        std::vector<int> combo_two;
        combo_one.push_back(4);
        combo_one.push_back(5);
        combo_one.push_back(6);
        this->winning_combos.push_back(combo_two);

        std::vector<int> combo_three;
        combo_one.push_back(7);
        combo_one.push_back(8);
        combo_one.push_back(8);
        this->winning_combos.push_back(combo_three);

        std::vector<int> combo_four;
        combo_one.push_back(1);
        combo_one.push_back(4);
        combo_one.push_back(7);
        this->winning_combos.push_back(combo_four);

        std::vector<int> combo_five;
        combo_one.push_back(2);
        combo_one.push_back(5);
        combo_one.push_back(8);
        this->winning_combos.push_back(combo_five);

        std::vector<int> combo_six;
        combo_one.push_back(3);
        combo_one.push_back(6);
        combo_one.push_back(9);
        this->winning_combos.push_back(combo_six);

        std::vector<int> combo_seven;
        combo_one.push_back(1);
        combo_one.push_back(5);
        combo_one.push_back(9);
        this->winning_combos.push_back(combo_seven);

        std::vector<int> combo_eight;
        combo_one.push_back(3);
        combo_one.push_back(5);
        combo_one.push_back(7);
        this->winning_combos.push_back(combo_eight);

        this->winning_combos.push_back(additional_combo);
    }

    std::vector<std::vector<int>> WinningCombos::all()
    {
        return this->winning_combos;
    }
