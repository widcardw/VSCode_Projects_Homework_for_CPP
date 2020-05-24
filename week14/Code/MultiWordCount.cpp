/************************
 * file: MultiWordCount.cpp
 * ���ж���һ���Ӻ�����ɶԵ����ı��ļ��к�����Ƶ��ͳ�ƣ����������е��ó����ļ��������Լ����к�����Ƶͳ�ƹ��ܵ��Ӻ�����
 * ��ɶ�text1��text2��text3�����ı��ļ��ĺ�����Ƶͳ�ƣ�����ͳ�ƽ�������������ļ�������Ƶͳ�ƽ��.txt�����ļ��С�
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
    out.open("����ļ�������Ƶͳ�ƽ��.txt");
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