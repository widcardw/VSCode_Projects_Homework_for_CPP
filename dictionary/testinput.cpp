#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("199801.txt");
    string s1;
    s1 = fin.get();
    cout << s1 << endl;
    fin.close();
    return 0;
}