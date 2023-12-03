#pragma once
#include "ParsingUtility.h"
using namespace std;

class Day
{
public:
    ifstream inputFile;
    Day(int day);
    
    virtual ~Day();
    virtual void RunFirst() = 0;
    virtual void RunSecond() = 0;
};
