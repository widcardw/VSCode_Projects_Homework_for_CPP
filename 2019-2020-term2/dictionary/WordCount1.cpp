#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

void Func1(string line, map<string, int> &m)
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
    }
}

int main()
{
    ifstream fin;
    fin.open("199801.txt");
    if (!fin)
    {
        cerr << "Cannot open input file!" << endl;
        exit(-1);
    }
    ofstream fout;
    fout.open("dict.txt");
    if (!fout)
    {
        cerr << "Cannot open output file!" << endl;
        exit(-1);
    }
    string s;
    map<string, int> m;
    for (int i = 0; i < 300; ++i)
    {
        getline(fin, s); //error
        if (s.length() >= 15)
        {
            s.erase(0, s.find_first_of(' ') + 1);
            Func1(s, m);
        }
        else
        {
            s = fin.get();
        }
    }
    for (auto i = m.begin(); i != m.end(); ++i)
        fout << i->first << ": " << i->second << endl;

    m.clear();
    //cout << "Successfully processed!" << endl;
    fin.close();
    fout.close();
    return 0;
}