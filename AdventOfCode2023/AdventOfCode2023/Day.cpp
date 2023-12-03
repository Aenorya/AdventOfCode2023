#include "Day.h"

Day::Day(int day, bool test)
{
    if(!test) inputFile = ifstream("Data/day"+std::to_string(day)+".txt");
    else inputFile = ifstream("Data/dataTest.txt");
    if(!inputFile.is_open())
    {
        cout<<"Failed to open file..."<<endl;
        const string error = "Failed to open file Data/day"+std::to_string(day)+".txt";
        throw std::exception(error.c_str());
    }
    
}

Day::~Day()
{
    if(inputFile.is_open())inputFile.close();
}