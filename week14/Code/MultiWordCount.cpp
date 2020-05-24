/************************
 * file: MultiWordCount.cpp
 * 其中定义一个子函数完成对单个文本文件中汉字字频的统计，在主函数中调用成批文件处理函数以及具有汉字字频统计功能的子函数，
 * 完成对text1、text2和text3三个文本文件的汉字字频统计，并把统计结果输出到“多个文件汉字字频统计结果.txt”的文件中。
 * ***********************/
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

void WordCount(string s, map<string, int> &m)
{
    int a = 0;
    while (s.length() >= 3)
    {
        if (a = s.find_first_of(' '))
        {
            if (!m.count(s.substr(0, a)))
                m[s.substr(0, a)] = 1;
            else
                m[s.substr(0, a)]++;
            s.erase(0, a + 1);
        }
        else if (a = s.find_first_of('\n'))
        {
            if (!m.count(s.substr(0, a)))
                m[s.substr(0, a)] = 1;
            else
                m[s.substr(0, a)]++;
            s.erase(0, a + 1);
        }
    }
}
int main()
{
    map<string, int> m;
    for (int i = 1; i <= 3; ++i)
    {
        string file_name;
        stringstream ss;
        ss << "text" << i << ".txt";
        ss >> file_name;
        ifstream in;
        in.open(file_name.c_str());
        if (!in)
        {
            cerr << "Cannot open input file!" << endl;
            exit(-1);
        }
        string line;
        getline(in, line);
        in.close();
        WordCount(line, m);
    }
    ofstream out;
    out.open("多个文件汉字字频统计结果.txt");
    if (!out)
    {
        cerr << "Cannot open output file!" << endl;
        exit(-1);
    }
    for (map<string, int>::iterator j = m.begin(); j != m.end(); ++j)
        out << j->first << ": " << j->second << endl;
    out.close();
    cout << "Successfully processed files!" << endl;
    return 0;
}