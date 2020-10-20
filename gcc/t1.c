#include <stdio.h>
#include <stdlib.h>
int lsbZero(int x) //最低有效位置零
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
    case 1:
    case 2:
        y = (~((~0) << 8)) << (8 * n);
        x = x & y;
        x = x >> (8 * n);
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
    // 0000...000011111111<<(8*n)
    // 假设n=1
    // 构造y=0x0000ff00
    // 之后用x和y按位与,然后右移8*n位,得到0x000000XX
    // 返回值为int类型
    // 那么x如果是负数且取高位,会按照符号位扩展,得到的是0xffffff87
    // 用unsigned int就不会有这样的问题
    // 所以n=3分开写了
}
int getByteNot(int x, int n)
{
    //x=1000 0111 0110 0101 0100 0011 0010 0001B //0x87654321 x
    //y=0000 0000 0000 0000 1111 1111 0000 0000B //0x0000ff00 y
    //r=1000 0111 0110 0101 1011 1100 0010 0001B //r=x^y
    //异或后其它位保留,指定位取反
    int y = 0;
    switch (n)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        y = (~((~0) << 8)) << (8 * n);
        x = x ^ y;
        return x;
    default:
        printf("error\n");
        exit(-1);
    }
}
int byteXor(int x, int y, int n)
{
    if (getByte(x, n) == getByte(y, n))
        return 0;
    else
        return 1;
}
int mul2OK(int x)
{
    // OF = (x_{n-1})(y_{n-1})(!Sum_{n-1})+(!x_{n-1})(!y_{n-1})(Sum_{n-1})
    // x_{n-1} == y_{n-1}
    int xx = x << 1; // x的两倍
    int xa = x >> 31, xb = xx >> 31;
    if ((xa ^ xb) == 0)
        return 1;
    return 0;
}
int main()
{
    int a = 0x87654321;
    int b = lsbZero(a);
    int c = 0x12344378;
    printf("a原数:%x, 最低有效位置零:%x\n", a, b);
    printf("取第0,1,2,3字节:%x, %x, %x, %x\n",
           getByte(a, 0), getByte(a, 1), getByte(a, 2), getByte(a, 3));
    printf("第0,1,2,3字节取反:%x, %x, %x, %x\n",
           getByteNot(a, 0), getByteNot(a, 1), getByteNot(a, 2), getByteNot(a, 3));
    printf("a,c两数字节比较: %d, %d\n", byteXor(a, c, 2), byteXor(a, c, 1));
    printf("两倍后是否溢出: %d, %d\n", mul2OK(0x30000000), mul2OK(0x40000000));
    return 0;
}