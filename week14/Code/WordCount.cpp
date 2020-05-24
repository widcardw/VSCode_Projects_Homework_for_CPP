/***************************
 * file: WordCount.cpp
 * �ó������Ҫ����Ϊͳ�������ļ�����һ�ļ��еĺ��ֳ��ֵ�Ƶ��(Ӣ�ĵ����ڴ˴�����Ϊһ�����ֽ���ͳ��)
 * ����ͳ�ƽ�����뵽�ļ���Ϊ�������ļ�������Ƶͳ�ƽ��.txt�����ļ��С�
 * ******************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
void process(string line, map<string, int> &m)
{
    int a = 0;
    while (line.length() >= 3)
    {
        if (line.find_first_of(' ') != line.npos)
        {
            a = line.find_first_of(' ');
            if (!m.count(line.substr(0, a)))
                m[line.substr(0, a)] = 1;
            else
                m[line.substr(0, a)]++;
            line.erase(0, a + 1);
            //cout << line << endl;
        }
        else if (line.find_first_of('\n') != line.npos)
        {
            a = line.find_first_of('\n');
            if (!m.count(line.substr(0, a)))
                m[line.substr(0, a)] = 1;
            else
                m[line.substr(0, a)]++;
            line.erase(0, a + 1);
            //cout << line << endl;
        }
        //cout << line.length() << endl;
        //��Ϊ���ʣ���ַ�������2���Ծ�ֱ�Ӱ�while����д>=3��
    }
}
int main()
{
    ofstream out;
    out.open("�����ļ�������Ƶͳ�ƽ��.txt");
    if (!out)
    {
        cerr << "Cannot open output file!" << endl;
        exit(-1);
    }
    for (int i = 1; i <= 3; ++i)
    {
        map<string, int> m;
        string b(".txt");
        string file_name;
        stringstream ss;
        ss << "text" << i << b;
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
        process(line, m);
        in.close();
        out << "text" << i << ".txt\n"
            << "\n";
        for (map<string, int>::iterator j = m.begin(); j != m.end(); ++j)
        {
            out << j->first << ": " << j->second << endl;
        }
        out << '\n'
            << endl;
        cout << "Successfully processed "
             << "text" << i << ".txt" << endl;
        m.clear();
    }
    out.close();
    return 0;
}