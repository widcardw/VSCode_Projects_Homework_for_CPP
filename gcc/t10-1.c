#include <stdio.h>
int sum1(int n)
{
    int result;
    if (n <= 0)
        result = 0;
    else
        result = n + sum1(n - 1);
    return result;
}
void main()
{
    int z;
    z = sum1(3);
    printf("%d\n", z);
}
