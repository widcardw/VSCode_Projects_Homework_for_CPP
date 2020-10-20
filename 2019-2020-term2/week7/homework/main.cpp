/*******************************************************************
 * File:main.cpp
********************************************************************/
#include <iostream>
#include "cpoint.h"
using namespace std;
int main()
{
    CPoint dot_a, dot_b, dot_c;
    cout << "输入点的横坐标和纵坐标:" << endl;
    cin >> dot_a;
    cout << "A:" << dot_a << endl;
    cout << "前自增A:";
    dot_b = ++dot_a;
    cout << dot_a << endl;
    cout << "前自增A的结果:" << dot_b << endl;
    cout << "后自增A:";
    dot_b = dot_a++;
    cout << dot_a << endl;
    cout << "后自增A的结果(即B):" << dot_b << endl;

    dot_c = dot_a + dot_b;
    cout << "A+B:" << dot_c << endl;
    dot_c = dot_a + 2.5;
    cout << "A+(2.5,0):" << dot_c << endl;
    return 0;
}