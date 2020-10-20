#include <iostream>
#include "CFraction.h"
#include <cmath>
using namespace std;

int main()
{
    Fraction a, b, a1;
    cin >> a >> b;
    ++a;
    cout << "++a输出: " << a << endl;
    a1 = a++;
    cout << "a++返回值: " << a1 << ", a的值: " << a << endl;
    a1 = a + b;
    cout << "a+b=" << a1 << endl;
    a1 = a * b;
    cout << "a*b=" << a1 << endl;
    a1 = a / b;
    cout << "a/b=" << a1 << endl;
    if (a > b)
        cout << "a > b" << endl;
    else if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a == b" << endl;
    return 0;
}