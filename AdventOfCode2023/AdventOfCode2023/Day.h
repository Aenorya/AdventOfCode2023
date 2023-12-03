#pragma once
#include "ParsingUtility.h"
#include <vector>
using namespace std;

class Day
{
public:
    ifstream inputFile;
    Day(int day, bool test = false);
    
    virtual ~Day();
    virtual void RunFirst() = 0;
    virtual void RunSecond() = 0;
};
