#include <stdio.h>
struct record
{
    char a;
    char c;
    char e;
    char f;
    int b;
    int f;
    short d;
};
int main()
{
    struct record x1, x2;
    x1.a = 1;
    x1.c = 2;
    x1.e = 3;
    x1.f = 4;
    x1.b = 5;
    x1.f = 6;
    x1.d = 7;
    x2.a = 8;
    x2.c = 9;
    x2.e = 10;
    x2.f = 11;
    x2.b = 12;
    x2.f = 13;
    x2.d = 14;
    return 0;
}