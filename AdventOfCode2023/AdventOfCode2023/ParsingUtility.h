#pragma once
#include <iostream>
#include <string>
#include <fstream>

class ParsingUtility
{
public:
    static int IsDigit(char);
    static std::string GetInputText(const std::string& filename);
    
};
