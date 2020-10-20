#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include <cstring>
#include<stdio.h>

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

struct cmp_str
{
    bool operator()(char *a, char *b)const
    {
        return std::strcmp(a, b) < 0;
    }
};

inline void StringCopy(std::map<char*, long, cmp_str>& wordMap, std::pair< std::map<char*, long>::iterator, bool>& ret, char*& target, char*& val, int& start, int& finish)
{
    if (finish - start > 0)
    {
        if (target != nullptr)
            delete target;
        target = new char[finish - start + 1];
        strcpy(target, val + start);
        ret = wordMap.insert(std::make_pair(target, 1));
        if (!ret.second)
        {
            wordMap[target] += 1;
        }
        else
        {
            target = nullptr;
        }
    }
    start = finish + 1;
}

inline void handleWords(std::map<char*, long, cmp_str>& wordMap, std::pair< std::map<char*, long>::iterator, bool>& ret, char*& trueWord, char*& word)
{
    int index = 0;
    for (int i = 0; i < 50; i++)
    {
        if (word[i] == '\0')
        {
            StringCopy(wordMap, ret, trueWord, word, index, i);
            break;
        }
        else
        {
            if (word[i] < 65 || (word[i] > 90 && word[i] < 97) || word[i] >122)
            {
                word[i] = '\0';
                StringCopy(wordMap, ret, trueWord, word, index, i);
            }
            else if (word[i] > 64 && word[i] < 91)
            {
                word[i] += 32;
            }
        }
    }
}

bool cmp_by_value(const std::pair<char*, long>& v1, const std::pair<char*, long>& v2)
{
    if (v1.second == v2.second)
        return v1.first < v2.first;
    else
        return v1.second > v2.second;
}

int main(int argc, char* argv[])
{
    //_CrtSetBreakAlloc(259);
    char path[100];
    if (argc > 1)
    {
        std::strcpy(path, argv[1]) ;
    }
    else
    {
        printf("%s\n", "Please input path:");
        scanf("%s", path);
    }
    std::map<char*, long, cmp_str> wordMap;
    std::pair< std::map<char*, long>::iterator, bool> ret;
    std::ifstream file;
    file.open(path);
    if (!file)
    {
        printf("%s\n", "The path is incorrect.");
    }
    else
    {
        char* word = new char[50];
        char* trueWord = nullptr;
        while (!file.eof())
        {
            if (file.getline(word, 50, ' ').good())
                handleWords(wordMap, ret, trueWord, word);
            else
            {
                handleWords(wordMap, ret, trueWord, word);
                break;
            }
        }
        if (trueWord != nullptr)
            delete trueWord;
        if (word != nullptr)
            delete word;
        file.close();

        std::vector<std::pair<char*, long> >wordArray(wordMap.begin(), wordMap.end());
        sort(wordArray.begin(), wordArray.end(), cmp_by_value);
        int len = std::min(int(wordArray.size()), 10);
        int size = wordArray.size();
        for (int i = 0; i < size; i++)
        {
            if (i < len)
            {
                printf("% -15s", wordArray[i].first);
                printf("%d\n", wordArray[i].second);
            }
            delete wordArray[i].first;
            wordArray[i].first = nullptr;
        }
        wordArray.clear();
        wordMap.clear();
    }
    system("pause");
    return 0;
    //_CrtDumpMemoryLeaks();
}
