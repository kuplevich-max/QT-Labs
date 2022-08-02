#include "utils.h"

Utils::Utils()
{

}

bool Utils::hasChar(wchar_t* str, wchar_t c)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return true;
        i++;
    }
    return false;
}

bool Utils::hasChar(QString str, char c)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == c)
            return true;
    }
    return false;
}

bool Utils::isNumber(QString s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(i == 0 && s[i] == '-')
            continue;
        if(s[i] == '.')
            continue;
        if(!s[i].isDigit())
            return false;
    }
    return true;
}
