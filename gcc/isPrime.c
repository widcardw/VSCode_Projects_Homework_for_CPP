#include <stdio.h>
#include <math.h>
typedef enum bool
{
    true = 1,
    false = 0
} bool;
bool isPrime(int x);
int sum(int n);
int main()
{
    int n;
    printf("input num: ");
    scanf("%d", &n);
    // if (isPrime(n))
    //     printf("isPrime\n");
    // else
    //     printf("isNotPrime\n");
    printf("%d\n", sum(n));
    return 0;
}
bool isPrime(int x)
{
    int sqrt_x = sqrt(x), i;
    for (i = 2; i <= sqrt_x; ++i)
        if (x % i == 0)
            break;
    if (i > sqrt_x)
        return 1;
    else
        return 0;
}
int sum(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; ++i)
        s += i;
    return s; //当然,如果数据过大,会发生溢出,但并不会报错
}