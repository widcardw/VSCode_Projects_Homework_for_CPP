#include <iostream>
#include "ccomplex.h"
using namespace std;
int main()
{
    CComplex complex1(1, 2), complex2;
    cout << "complex1: ";
    complex1.display(); //��ʾ complex1
    cout << "\n ǰ���� complex1: ";
    complex2 = ++complex1;
    complex1.display();
    cout << "\n complex2�� ";
    complex2.display();
    cout << "\n ������ complex1:";
    complex2 = complex1++;
    complex1.display();
    cout << "\n complex2: ";
    complex2.display();
    cout << "\n";
    return 0;
}
