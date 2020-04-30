#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void f(string s, map<string, int> &m)
{
    if (!s.length())
        return;
    int a = s.find_first_of(' ');
    if (!m.count(s.substr(0, a)))
        m[s.substr(0, a)] = 1;
    else
        m[s.substr(0, a)]++;
    f(s.substr(a + 1, s.length() - a), m);
}

int main()
{
    ifstream fin;
    fin.open("199801.txt");
    ofstream fout;
    fout.open("dic.txt");
    string s, temp;
    map<string, int> m;
    for (int k = 0; k < 10; ++k)
    {
        for (int j = 0; j < 100; ++j)
        {
            getline(fin, temp);
            temp.erase(0, temp.find_first_of(' '));
            s += temp;
        }
        f(s, m);
        s.clear();
    }
    /*for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << ":" << i->second << endl;*/
    for (auto i = m.begin(); i != m.end(); ++i)
        fout << i->first << ": " << i->second << endl;

    fin.close();
    fout.close();
    cout << "Successfully output" << endl;
    return 0;
}