#include "Day2.h"


Day2::Game Day2::ParseGame(string line)
{
    Game game{};
    int round = -1, lastAmount = 0;
    for(size_t c = 0; c < line.length(); c++)
    {
        switch(line[c])
        {
        case 'r':
        case 'g':
        case 'b':
            if(game.rounds[round].colors[line[c]]!=0) break;
            game.rounds[round].colors[line[c]] = lastAmount;
            lastAmount = 0;
            break;
        case ':':
        case ';':
            //new round
            round ++;
            game.rounds.emplace_back();
            
        default:
            if(line[c]-'0' >= 0 && line[c]-'0'< 10)
            {
                if(game.rounds.empty())
                {
                    game.id = (game.id * 10) + (line[c] - '0');
                }else
                {
                    lastAmount = lastAmount * 10 + (line[c]-'0');
                }
                break;
            }
            break;
        }
    }
    return game;
}

void Day2::MaxInRounds(Game game, int& r, int& g, int& b)
{
    for(Round round : game.rounds)
    {
        if(r < round.colors['r']) r = round.colors['r'];
        if(g < round.colors['g']) g = round.colors['g'];
        if(b < round.colors['b']) b = round.colors['b'];
    }
}

void Day2::MinInRounds(Game game, int& r, int& g, int& b)
{
    for(Round round : game.rounds)
    {
        if(r < round.colors['r']) r = round.colors['r'];
        if(g < round.colors['g']) g = round.colors['g'];
        if(b < round.colors['b']) b = round.colors['b'];
    }
}

void Day2::RunFirst()
{
    cout<<"=========PART 1==========\n";
    string line;
    int total = 0;
    while(getline(inputFile, line))
    {
        Game game = ParseGame(line);
        int r=0,g=0,b=0;
        MaxInRounds(game, r,g,b);
        if(r > 12 || g > 13 || b > 14)
        {
            //cout<<"Game "<<game.id<<" is impossible.\n";
        }
        else
        {
            //cout<<"Game "<<game.id<<" is possible.\n";
            total += game.id;
        }
    }
    cout<<"Total : "<<total;
}

void Day2::RunSecond()
{
    cout<<"\n\n=========PART 2==========\n";
    inputFile.clear();
    inputFile.seekg(0);
    string line;
    int total = 0;
    while(getline(inputFile, line))
    {
        Game game = ParseGame(line);
        int r=0,g=0,b=0;
        MinInRounds(game, r,g,b);
        total += (r*g*b);
    }
    cout<<"Total : "<<total;
}

