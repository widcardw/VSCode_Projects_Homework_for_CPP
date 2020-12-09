#include <stdio.h>
unsigned sum1(unsigned n)
{
    unsigned y = 0;
    unsigned i = 0;
    while (i <= n)
    {
        y += i;
        i++;
    }
    return y;
}
int sum2(int n)
{
    int y = 0;
    int i = 0;
    while (i <= n)
    {
        y += i;
        i++;
    }
    return y;
}
int main()
{
    unsigned n1 = 0x16a0b;
    int n2 = 0x16a0b;
    unsigned s1 = sum1(n1);
    int s2 = sum2(n2);
    printf("%u, %d, %u, %d\n", n1, n2, s1, s2);
    return 0;
}
