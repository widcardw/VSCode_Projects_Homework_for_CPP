/*******************************************************************
 * File:main.cpp
********************************************************************/
#include <iostream>
#include "cpoint.h"
using namespace std;
int main()
{
    CPoint dot_a, dot_b, dot_c;
    cout << "�����ĺ������������:" << endl;
    cin >> dot_a;
    cout << "A:" << dot_a << endl;
    cout << "ǰ����A:";
    dot_b = ++dot_a;
    cout << dot_a << endl;
    cout << "ǰ����A�Ľ��:" << dot_b << endl;
    cout << "������A:";
    dot_b = dot_a++;
    cout << dot_a << endl;
    cout << "������A�Ľ��(��B):" << dot_b << endl;

    dot_c = dot_a + dot_b;
    cout << "A+B:" << dot_c << endl;
    dot_c = dot_a + 2.5;
    cout << "A+(2.5,0):" << dot_c << endl;
    return 0;
}