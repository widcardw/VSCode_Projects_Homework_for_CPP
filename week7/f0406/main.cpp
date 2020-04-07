#include <iostream>
#include "f0406.h"
using namespace std;
int main()
{
    CComplex complex1, complex2, complex3;
    cout << "请输入一个复数: " << endl;
    cin >> complex1;
    cout << "complex1: " << complex1 << endl; //显示 complex1
    cout << "前自增 complex1:";
    complex2 = ++complex1;
    cout << complex1 << endl;
    cout << "前自增 complex1 的结果:";
    cout << complex2 << endl;
    cout << "后自增 complex1:";
    complex2 = complex1++;
    cout << complex1 << endl;
    cout << "后自增 complex1 的结果: ";
    cout << complex2 << endl;
    complex3 = complex1 + complex2;
    cout << "complex1 + complex2 : " << complex3 << endl;
    complex3 = complex1 + 2.1;
    cout << "complex1+2.1: " << complex3 << endl;
    complex3 = 2.5 + complex1;
    cout << "2.5+complex1: " << complex3 << endl;
    return 0;
}
