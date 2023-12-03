#include "Day1.h"

#include <vector>

void FindDigits(string line, int& first, size_t& firstPos, int& last, size_t& lastPos);
void FindAlphaDigit(string line, int& first, size_t& firstPos, int& last, size_t& lastPos);

void Day1::RunFirst()
{
    cout<<"=========PART 1==========\n";
    string line;
    ifstream myfile("Data/dataTest.txt");
    int total = 0, zero = '0';
    if (myfile.is_open())
    {
        int first=-1, last=-1;
        while ( getline (myfile,line) )
        {
            first = -1;
            last = -1;
            for(int c=0; c<line.length(); c++){
                if(line[c]-zero < 10){
                    if(first == -1){ first = line[c]-zero;}
                    if(c > last) last = line[c]-zero;
                }
            }
            if(first != -1) {
                total += (first*10)+last;
                cout<<((first*10)+last)<<endl;
            }
        }
        cout<<"Total : "<<total<<endl;
    }else
    {
        cout<<"Failed to open file..."<<endl;
    }
    myfile.close();
}

void Day1::RunSecond()
{
    cout<<"\n\n=========PART 2==========\n";

    string line;
    ifstream myfile("Data/dataTest.txt");
    int total = 0, zero = '0';
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            int first=-1, last=-1;
            size_t firstNum = 0, lastNum = 0;
            //Finding number digits
            FindDigits(line, first, firstNum, last, lastNum);
            //Finding text digits
            FindAlphaDigit(line, first, firstNum, last, lastNum);
            
            if(first != -1) {
                total += (first*10)+last;
                cout<<line<<": "<<((first*10)+last)<<endl;
            }
        }
        cout<<"Total : "<<total<<endl;
    }
    
}

void FindDigits(string line, int& first, size_t& firstPos, int& last, size_t& lastPos)
{
    
    for(int c=0; c<line.length(); c++){
        if(line[c]-'0' < 10){
            if(first == -1){ first = line[c]-'0'; firstPos = c;}
            if(c > lastPos || last == -1) {last = line[c]-'0'; lastPos = c;}
        }
    }
}

vector<size_t> FindOccurencesOf(string text, string substr)
{
    vector<size_t> occurrences{};
    size_t lastMatch = string::npos;
    do
    {
        lastMatch = text.find(substr, lastMatch + 1);
        if(lastMatch != string::npos)
        {
            occurrences.push_back(lastMatch);
        }else break;
    }while(lastMatch < text.length());
    return occurrences;
}

void FindAlphaDigit(string line, int& first, size_t& firstPos, int& last, size_t& lastPos)
{
    string digits[] = {"one", "two", "three", "four", "five","six","seven","eight","nine"};
    int current = 1;
    for(string d : digits)
    {
        vector<size_t> occurrences = FindOccurencesOf(line, d);
        if(!occurrences.empty() && firstPos > occurrences.front())
        {
            firstPos = occurrences.front();
            first = current;
        }
        if(!occurrences.empty() && lastPos < occurrences.back())
        {
            lastPos = occurrences.back();
            last = current;
        }
        current ++;
    }
}