#include "Day4.h"
using namespace std;

int ExtractNumbers(string&);

void Day4::RunFirst()
{
    string line;
    int total = 0;
    while(getline(inputFile, line))
    {
        cout<<line<<" --> "<<ExtractNumbers(line)<<endl;
        total += ExtractNumbers(line);
    }
    cout<<"Total : "<<total<<endl;
}

void Day4::RunSecond()
{
    
}

int ExtractNumbers(string& line)
{
    cout<<"Match :";
    vector<int> winners{};
    int currentNumber = 0, points = 0;
    size_t c = line.find(':');
    bool enable = false;
    for(; c < line.length(); c++)
    {
        if(line[c] == '|') break;
        if(!enable && line[c] == ' ' && currentNumber!=0) {enable = true; winners.push_back(currentNumber); currentNumber = 0;}
        if(line[c]-'0' >= 0 && line[c]-'0'<10)
        {
            enable = false;
            currentNumber = (currentNumber*10) + (line[c]-'0');
        }
    }
    enable = false;
    for(c++;c <= line.length(); c++)
    {   if(line[c] == ' ' || c==line.length())enable = true;
        if(enable && currentNumber != 0 && (line[c] == ' ' || c == line.length()))
        {
            for(int w : winners)
            {
                if(w!=currentNumber) continue;
                points ++; break;
            }
            currentNumber = 0;
        }
        if((line[c]-'0')>=0 && (line[c]-'0')<10)
        {
            enable = false;
            currentNumber = (currentNumber*10) + (line[c]-'0');
        }
    }
    return points == 0? 0: pow(2,points-1);
}
