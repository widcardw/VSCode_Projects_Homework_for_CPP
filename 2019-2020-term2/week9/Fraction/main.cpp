#include <iostream>
#include "CFraction.h"
#include <cmath>
using namespace std;

int main()
{
    Fraction a, b, a1;
    cin >> a >> b;
    ++a;
    cout << "++a���: " << a << endl;
    a1 = a++;
    cout << "a++����ֵ: " << a1 << ", a��ֵ: " << a << endl;
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