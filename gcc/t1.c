#include <stdio.h>
#include <stdlib.h>
int lsbZero(int x)
{
    x = x >> 4;
    x = x << 4;
    return x;
}
int getByte(int x, int n)
{
    int y = 0;
    switch (n)
    {
    case 0:
        y = ~((~0) << (8 * n));
        x = x & y;
        return x;
    case 1:
    case 2:
        y = ~((~0) << (8 * n)) << (8 * (n - 1));
        x = x & y;
        x = x >> (8 * (n - 1));
        return x;
    case 3:
        x = x >> 24;
        y = ~((~0) << 8);
        x = x & y;
        return x;
    default:
        printf("error\n");
        exit(-1);
    }
    // 0000...000011111111<<(8*(n-1))
    // 假设n=1
    // 构造y=0x0000ff00
    // 之后用x和y按位与,然后右移8*n位
    // 返回值为int类型
    // 那么x如果是负数,会按照符号位扩展,得到的是0xffffff87
    // 用unsigned int就不会有这样的问题
    // 所以采用了逐个分开写的方法
}
int getByteNot(int x, int n)
{
    //1000 0111 0110 0101 0100 0011 0010 0001
    //0000 0000 0000 0000 1111 1111 0000 0000
}
int main()
{
    int a = 0x87654321;
    int b = lsbZero(a);
    int c = getByte(a, 3);
    printf("%x, %x, %x\n", a, b, c);
    return 0;
}