#include "ParsingUtility.h"
using namespace std;

int ParsingUtility::IsDigit(char c)
{
    int digit = c - '0';
    return (digit>=0 && digit<10)? digit : -1;
}

string ParsingUtility::GetInputText(const string& filename){
    string text;
    ifstream myFile("Data/"+ filename + ".txt");
    if (myFile.is_open())
    {
        string line;
        while ( getline (myFile,line) )
        {
            //cout << line << '\n';
            text += line;
        }
        myFile.close();
    }

    else cout << "Unable to open file"; 
    return text;
}