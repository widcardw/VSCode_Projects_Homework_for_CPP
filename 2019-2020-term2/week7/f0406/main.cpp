#include <iostream>
#include "f0406.h"
using namespace std;
int main()
{
    CComplex complex1, complex2, complex3;
    cout << "������һ������: " << endl;
    cin >> complex1;
    cout << "complex1: " << complex1 << endl; //��ʾ complex1
    cout << "ǰ���� complex1:";
    complex2 = ++complex1;
    cout << complex1 << endl;
    cout << "ǰ���� complex1 �Ľ��:";
    cout << complex2 << endl;
    cout << "������ complex1:";
    complex2 = complex1++;
    cout << complex1 << endl;
    cout << "������ complex1 �Ľ��: ";
    cout << complex2 << endl;
    complex3 = complex1 + complex2;
    cout << "complex1 + complex2 : " << complex3 << endl;
    complex3 = complex1 + 2.1;
    cout << "complex1+2.1: " << complex3 << endl;
    complex3 = 2.5 + complex1;
    cout << "2.5+complex1: " << complex3 << endl;
    return 0;
}
