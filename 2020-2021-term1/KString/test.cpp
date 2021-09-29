#include <iostream>
#include "kstring.h"
using namespace std;

void testFun()
{
    KString a("qwerty");
    KString b(a);
    b = b + "b";
    KString c = "c" + a;
    cout << a << "\n"
         << b << "\n"
         << c << endl;
    cout << (a <= b) << endl;
    c += "abc";
    cout << c << endl;
    KString d = a.Upper();
    cout << a << " " << d << endl;
}
int main()
{
    testFun();
    return 0;
}