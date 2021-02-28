#include <iostream>
#include <iomanip>
#include <cstring>
#include "hashmap.h"
#include <cstdio>
#include <iomanip>

HashMap::HashMap()
{
    for (int i = 0; i < 41; ++i)
    {
        hashlist[i].searchTimes = hashlist[i].keynum = 0;
        hashlist[i].keyword[0] = '\0';
    }
}

bool HashMap::isLetter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool HashMap::isKeyWord(char *word)
{
    for (int i = 0; i < 32; ++i)
        if (strcmp(word, KeyWords[i]) == 0)
            return true;
    return false;
}

int HashMap::GetHashKey(char *word)
{
    int key = (word[0] * 100 + word[strlen(word) - 1]) % 41;
    // std::cout << std::setw(10) << word << std::setw(3) << key;
    return key;
}

int HashMap::SearchProperSeat(char *word)
{
    int key = GetHashKey(word);
    for (int i = key; i < 41; ++i)  // 从得到的HashKey处开始查找
    {
        if (strcmp(hashlist[i].keyword, word) == 0)  // 如果当前词已经在哈希表里(查找长度已经存在),且匹配成功
            return i;
        else if (strlen(hashlist[i].keyword) == 0)   // 如果哈希表的这个索引为空
        {
            hashlist[i].searchTimes = i - key  + 1;  // 计算存入这个单元的关键词的查找长度
            return i;
        }
    }
    for (int j = 0; j < key; ++j)  // 已经到达表尾,再从表头开始查找
    {
        if (strcmp(hashlist[j].keyword, word) == 0)  // 如果当前词已经在哈希表里(查找长度已经存在),且匹配成功
            return j;
        else if (strlen(hashlist[j].keyword) == 0)   // 如果哈希表的这个索引为空
        {
            hashlist[j].searchTimes = 41 - key + j + 1;  // 计算存入这个单元的关键词的查找长度
            return j;
        }
    }
    return -1;  // 哈希表满,查找失败
}

bool HashMap::insertNode(char *word)
{
    int seat = SearchProperSeat(word);
    if (seat < 0) return false;
    if (hashlist[seat].keynum < 1)
        strcpy(hashlist[seat].keyword, word);
    hashlist[seat].keynum++;
    return true;
}

void HashMap::CreateHashMapFromFile(FILE *in)
{
    char ch; char word[10] = "";
    ch = fgetc(in);
    while (!feof(in))
    {
        int i = 0;
        while (!isLetter(ch) && !feof(in))
        {    
            ch = fgetc(in);
        }
        while (isLetter(ch) && !feof(in))
        {
            if (i >= 10)
            {
                while (isLetter(ch) && !feof(in))
                {
                    ch = fgetc(in);
                }
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
        if (isKeyWord(word))
            insertNode(word);
    }
}

void HashMap::PrintList(std::ostream &out)
{
    out << std::setw(3) << 'n' 
        << std::setw(10) << "keyword"
        << std::setw(8) << "search"
        << std::setw(8) << "num"
        << std::endl;
    for (int i = 0; i < 41; ++i)
    {
        out << std::setw(3) << i 
            << std::setw(10) << hashlist[i].keyword
            << std::setw(8) << hashlist[i].searchTimes
            << std::setw(8) << hashlist[i].keynum
            << std::endl;
    }
}

int HashMap::CalSearchLen()
{
    int sum = 0;
    for (int i = 0; i < 41; ++i)
    {
        sum += hashlist[i].keynum * hashlist[i].searchTimes;
    }
    return sum;
}