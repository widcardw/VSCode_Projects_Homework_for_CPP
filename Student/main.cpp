#include <iostream>
#include "stu.h"
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    ifstream fin("stu.txt");
    if (!fin)
    {
        cout << "Cannot open the file!" << endl;
        exit(1);
    }
    int num;
    fin >> num;
    Student *stu;
    stu = new Student[num];
    for (int i = 0; i < num; ++i)
    {
        fin >> stu[i];
        cout << stu[i] << endl;
    }
    return 0;
}