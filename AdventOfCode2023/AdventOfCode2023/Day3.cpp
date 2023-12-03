#include "Day3.h"

int FindNumberAt(string line, size_t position)
{
    int number = 0;
    if(ParsingUtility::IsDigit(line[position]) == -1) return 0;
    
    while(position > 0 && (ParsingUtility::IsDigit(line[position]) != -1))
    {
        position --;
    }
    if(ParsingUtility::IsDigit(line[position]) == -1) position ++;
    do
    {
        number = number * 10 + ParsingUtility::IsDigit(line[position]);
        position ++;
    }
    while(position < line.length() && ParsingUtility::IsDigit(line[position]) != -1);
    return max(number, 0);
}

bool IsSymbol(char c)
{
    return c!= '.' && ParsingUtility::IsDigit(c) == -1;
}

bool IsValid(string& top, string& mid, string& bot, size_t column)
{
    for(int c = column-1; c <= column + 1; c ++)
    {
        if(IsSymbol(top[c]) || IsSymbol(mid[c]) || IsSymbol(bot[c])) return true;
    }
    
    return false;
}

void Day3::RunFirst()
{
    std::vector<string> rows{};
    string line;
    while(getline(inputFile, line))
    {
        rows.push_back(line);
    }
    int total = 0; bool skip = false;
    for(size_t r = 0; r < rows.size(); r++)
    {
        for(size_t c = 0; c < rows[r].length(); c++)
        {
            int num = ParsingUtility::IsDigit(rows[r][c]);
            if(num != -1)
            {
                if(!skip && IsValid(
                    r>0?rows[r-1]: rows[r],
                    rows[r],
                    r<rows.size()-1?rows[r+1]: rows[r],
                    c))
                {
                    total += FindNumberAt(rows[r], c);
                    skip = true;
                }
            }else if(skip) skip = false;
        }
    }
    cout<<"Total : "<< total << endl;
    
}

void Day3::RunSecond()
{
    
}
