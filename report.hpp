#include "ttt_stats.hpp"
#pragma once
class Report
{
private:
    TTT* ttt;
public:
    Report(TTT* ttt);
    string generate_report()const;
};
