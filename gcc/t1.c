#include <stdio.h>
int lsbZero(int x) //最低有效位置零
{
    x = x >> 1;
    x = x << 1;
    return x;
}
int getByte(int x, int n)
{
    n <<= 3;
    x >>= n;        //让指定位置移动到最低一个字节
    x = x & (0xff); //用"&"来过滤高位
    return x;
}
int getByteNot(int x, int n)
{
    //x=1000 0111 0110 0101 0100 0011 0010 0001B //0x87654321 x
    //y=0000 0000 0000 0000 1111 1111 0000 0000B //0x0000ff00 y
    //r=1000 0111 0110 0101 1011 1100 0010 0001B //r=x^y
    //异或后其它位保留,指定位取反
    int y = 0;
    n <<= 3;
    y = (~((~0) << 8)) << n;
    x = x ^ y;
    return x;
}
int byteXor(int x, int y, int n)
{
    n <<= 3;
    x >>= n;
    y >>= n;
    x = x & (0xff);   //取x的指定字节
    y = y & (0xff);   //取y的指定字节
    return !!(x ^ y); //x^y,如果相同,则值为0,如果不同,则值不为0
}
int mul2OK(int x)
{
    // OF = (x_{n-1})(y_{n-1})(!Sum_{n-1})+(!x_{n-1})(!y_{n-1})(Sum_{n-1})
    // x_{n-1} == y_{n-1}
    int xx = x << 1; // x的两倍
    int xa = x >> 31, xb = xx >> 31;
    return !(xa ^ xb);
}
int main()
{
    int a = 0x87654321;
    int b = lsbZero(a);
    int c = 0x12344378;
    printf("a=%x\nc=%x\nlspZero(a)=%x\n\n", a, c, b);
    printf("getByte(a, i),i=0,1,2,3\n%x, %x, %x, %x\n\n",
           getByte(a, 0), getByte(a, 1), getByte(a, 2), getByte(a, 3));
    printf("getByteNot(a, i),i=0,1,2,3\n%x, %x, %x, %x\n\n",
           getByteNot(a, 0), getByteNot(a, 1), getByteNot(a, 2), getByteNot(a, 3));
    printf("byteXor(a, c, i),i=1,2\n%d, %d\n\n", byteXor(a, c, 1), byteXor(a, c, 2));
    printf("mul2OK(x), x=0x30000000,0x40000000\n%d, %d\n", mul2OK(0x30000000), mul2OK(0x40000000));
    return 0;
}
