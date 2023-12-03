#pragma once
#include <map>

#include "Day.h"

class Day2: public Day
{
private:
    struct Round
    {
        std::map<char, int> colors{{'r', 0}, {'g', 0}, {'b', 0}};
    };
    struct Game
    {
        int id = 0;
        std::vector<Round> rounds{};
    };
    Game ParseGame(string line);
    void MaxInRounds(Game game, int& r, int& g, int& b);
    void MinInRounds(Game game, int& r, int& g, int& b);
public:
    Day2():Day(2){}
    void RunFirst() override;
    void RunSecond() override;
};
