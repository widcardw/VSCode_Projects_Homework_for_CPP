#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include "binary.h"

BinMap::BinMap()
{
    for (int i = 0; i < 32; ++i)
    {
        binlist[i].keynum = binlist[i].searchtimes = 0;
        strcpy(binlist[i].keyword, KeyWords[i]);
        int len = GetSearchLength(KeyWords[i]);
        binlist[i].searchtimes = len;
    }
}

bool BinMap::isLetter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool BinMap::isKeyWord(char *word)
{
    int low = 0, mid, high = 31;
    int sign = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        sign = strcmp(word, KeyWords[mid]);
        if (sign == 0) return true;
        else if (sign > 0) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int BinMap::GetSearchLength(char *word)
{
    int low = 0, mid, high = 31;
    int st = 0, sign = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        sign = strcmp(word, KeyWords[mid]);
        if (sign == 0)
        {
            st++; return st;
        }
        else if (sign > 0)
        {
            low = mid + 1; st++;
        }
        else 
        {
            high = mid - 1; st++;
        }
    }
    return -1;
}

int BinMap::BinarySearch(char *word)
{
    int low = 0, high = 31, mid;
    int st = 0, sign = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        sign = strcmp(word, KeyWords[mid]);
        if (sign == 0) 
        {
            binlist[mid].keynum++;
            // st++;
            // binlist[mid].searchtimes = st;
            return mid;
        }
        else if (sign > 0)
        {
            low = mid + 1; 
            // st++;
        }
        else
        {
            high = mid - 1; 
            // st++;
        }
    }
    return -1;
}

void BinMap::PrintList(std::ostream& out)
{
    out << std::setw(3) << 'n' 
        << std::setw(10) << "keyword"
        << std::setw(8) << "search"
        << std::setw(8) << "num"
        << std::endl;
    for (int i = 0; i < 32; ++i)
    {
        out << std::setw(3) << i 
            << std::setw(10) << binlist[i].keyword
            << std::setw(8) << binlist[i].searchtimes
            << std::setw(8) << binlist[i].keynum
            << std::endl;
    }
}

void BinMap::CreateMapFromFile(FILE* in)
{
    char ch = fgetc(in); char word[10];
    while (!feof(in))
    {
        int i = 0;
        while (!isLetter(ch) && !feof(in))
            ch = fgetc(in);
        while (isLetter(ch) && !feof(in))
        {
            if (i >= 10)
            {
                while (isLetter(ch) && !feof(in))
                    ch = fgetc(in);
                i = 0;
                break;
            }
            else
            {
                word[i++] = ch;
                ch = fgetc(in);
            }
        }
        word[i] = '\0';
        // if (isKeyWord(word))
        BinarySearch(word);
    }
}

int BinMap::CalSearchLen()
{
    int sum = 0;
    for (int i = 0; i < 32; ++i)
    {
        sum += binlist[i].keynum * binlist[i].searchtimes;
    }
    return sum;
}