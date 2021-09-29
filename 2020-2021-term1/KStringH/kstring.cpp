#include <iostream>
#include "kstring.h"
#include <cstring>
#include <cassert>
#pragma warning(disable : 4996)
using namespace std;
KString::KString(const char *myx) //构造函数
{
    assert(myx); //先判断这个指针是否为空
    if (!myx)
    {
        len = 0;
        str = new char[1]; //如果指针为空，则new一个内存空间
        *str = '\0';
    }
    else
    {
        len = strlen(myx);
        str = new char[len + 1]; //用new申请一个内存空间
        assert(str);             //判断内存是否申请成功
        strcpy(str, myx);        //将形参的内容复制给str
    }
}
KString::KString(const KString &myx) //复制构造函数
{
    len = myx.len;
    str = new char[myx.len + 1];
    assert(str);
    strcpy(str, myx.str);
}
int KString::length() //通过接口函数访问private变量len
{
    len = strlen(str);
    return len;
}
bool KString::iskong() const //判断字符串是否为空，若不为空则返回true，即为1
{
    if (len == 0)
        return true;
    else
        return false;
}
KString KString ::KStrcat(const KString &myx) //字符串拼接函数
{
    char *mystr = new char[len + myx.len + 1];
    assert(mystr);
    assert(myx.str);
    assert(mystr);
    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        *(mystr + i) = *(str + i); //先把原来的字符串存到mystr里
    }
    for (i = len; i < len + myx.len; i++, j++)
    {
        *(mystr + i) = *(myx.str + j);
    }
    *(mystr + len + myx.len) = '\0';
    KString tmp(mystr);
    delete[] mystr;
    return tmp;
}
void KString::KStrcpy(char *str1, const char *str2)
{
    assert(str1);
    assert(str2);
    int i = 0;
    while (*str2 != '\0')
    {
        *(str1 + i) = *(str2 + i);
        i++;
    }
    *(str1 + i) = '\0';
}
int KString::KStrcmp(const char *myx)
{
    assert(myx);
    if (len > strlen(myx))
    {
        for (int i = 0; i < strlen(myx); i++)
        {
            if (*(str + i) > *(myx + i))
                return 1;
            else if (*(str + i) < *(myx + i))
                return -1;
        }
        return 1;
    }
    else if (len < strlen(myx))
    {
        for (int i = 0; i < len; i++)
        {
            if (*(str + i) > *(myx + i))
                return 1;
            else if (*(str + i) < *(myx + i))
                return -1;
        }
        return -1;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (*(str + i) > *(myx + i))
                return 1;
            else if (*(str + i) < *(myx + i))
                return -1;
        }
        return 0;
    }
}
KString KString::KSubstr(int start, int len1)
{
    assert(start >= 0 && len1 > 0 && start + len1 <= len && start < len);
    assert(str);
    int j = 0;
    char *str1 = new char[len1 + 1];
    assert(str1);
    for (int i = start; i < start + len1; i++, j++)
    {
        *(str1 + j) = *(str + i);
    }
    *(str1 + len1) = '\0';
    KString tmp(str1);
    delete[] str1;
    return tmp;
}
KString &KString::operator=(const KString &myx) //赋值函数的重载
{
    if (this == &myx) //若相同则直接返回
        return *this;
    delete[] str; //若不相同，则将原来的字符串释放掉
    len = myx.len;
    str = new char[len + 1]; //重新申请一个内存空间
    assert(str);
    strcpy(str, myx.str); //将形参的内容复制给str
    return *this;
}
KString &KString::operator+=(const char *myx)
{
    char *temp = new char[len + 1]; //为字符串申请一个内存空间，这个temp作为中间变量
    strcpy(temp, str);              //将str的内容复制给temp
    len += strlen(myx);             //计算拼接之后的字符串的长度
    str = new char[len + 1];        //重新申请一个内存空间使得能够存放拼接后的字符串
    assert(str);
    strcpy(str, temp); //将原来的字符串复制给str
    strcat(str, myx);  //再将形参的字符串和原来的拼接起来
    delete[] temp;     //最后一定要将申请的空间释放掉
    return *this;
}
KString operator+(KString &myx1, KString &myx2) //将两个KString类的字符串拼接起来的重载
{
    KString temp;
    temp.len = myx1.len + myx2.len;
    temp.str = new char[temp.len + 1];
    assert(temp.str);
    strcpy(temp.str, myx1.str);
    strcat(temp.str, myx2.str);
    return temp;
}
KString operator+(KString &myx1, const char *myx2) //将KString类型和字符串拼接在一起的重载
{
    KString temp;
    temp.len = myx1.len + strlen(myx2);
    temp.str = new char[temp.len + 10];
    assert(temp.str);
    strcpy(temp.str, myx1.str);
    strcat(temp.str, myx2);
    return temp;
}
KString operator+(const char *myx1, KString &myx2) //将字符串和KString类里的字符串拼接起来的重载
{
    KString temp;
    temp.len = strlen(myx1) + myx2.len;
    temp.str = new char[temp.len + 1];
    assert(temp.str);
    strcpy(temp.str, myx1);
    strcat(temp.str, myx2.str);
    return temp;
}
bool KString::operator==(const KString &myx) //等号的重载
{
    if (len != myx.len)
        return false;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != myx.str[i])
            return false;
    }
    return true;
}
bool KString::operator!=(const KString &myx) //不等号的重载
{
    if (len != myx.len)
        return true;
    for (int i = 0; i < len; i++) //遍历str数组，看是否每个字符都相等
    {
        if (str[i] == myx.str[i])
            return false;
    }
    return true;
}
bool KString::operator>(const KString &myx) //大于号的重载
{
    if (str[0] > myx.str[0]) //先判断第一个字符是否一样，若大于则return true，就像求傅里叶系数里的a0一样单独算
        return true;
    int minlen; //先找出两个字符串中最小的长度
    if (len > myx.len)
        minlen = myx.len;
    else
        minlen = len;
    for (int i = 0; i < minlen; i++) //以最短的字符串为模版遍历数组
    {
        if (str[i] == myx.str[i])
            continue; //如果有两个字符相同，则进入下一轮循环继续比大小
        else if (str[i] > myx.str[i])
            return true;
        else
            return false;
    }
    if (len > myx.len) //如果出循环后，前minlen的字符串两者相同，str字符串比所要比较的字符串长，则返回true
        return true;
    return false;
}
bool KString::operator>=(const KString &myx) //原理同上大于号的重载
{
    if (str[0] >= myx.str[0])
        return true;
    int minlen;
    if (len > myx.len)
        minlen = myx.len;
    else
        minlen = len;
    for (int i = 0; i < minlen; i++)
    {
        if (str[i] >= myx.str[i])
            return true;
        else
            return false;
    }
    if (len >= myx.len)
        return true;
    return false;
}
bool KString::operator<=(const KString &myx) //小于号的重载和大于等于类似
{
    if (str[0] <= myx.str[0])
        return true;
    int minlen;
    if (len > myx.len)
        minlen = myx.len;
    else
        minlen = len;
    for (int i = 0; i < minlen; i++)
    {
        if (str[i] <= myx.str[i])
            return true;
        else
            return false;
    }
    if (len >= myx.len)
        return false;
    return true;
}
bool KString::operator<(const KString &myx) //小于号的重载也与大于号重载类似
{
    if (str[0] < myx.str[0])
        return true;
    int minlen;
    if (len > myx.len)
        minlen = myx.len;
    else
        minlen = len;
    for (int i = 0; i < minlen; i++)
    {
        if (str[i] == myx.str[i])
            continue;
        else if (str[i] < myx.str[i])
            return true;
        else
            return false;
    }
    if (len > myx.len)
        return false;
    return true;
}
istream &operator>>(istream &in, KString &myx) //流插入的重载
{
    in >> myx.str;
    myx.len = strlen(myx.str);
    return in;
}
ostream &operator<<(ostream &out, KString &myx) //流提取的重载
{
    out << myx.str;
    myx.len = strlen(myx.str);
    return out;
}
int KString::find(const char myx, int atfirst) //找到某个字符在str中的位置
{
    int i = atfirst;
    while (*(str + i) != '\0' && *(str + i) != myx)
    {
        i++;
    }
    if (i == len)
        i = -1;
    return i;
}
int KString::find(const char *myx, int firstc) //找到某个字符串在str中的位置，firstc为相对的起始位置
{
    int location = -1;                              //要返回的位置
    if (strlen(myx) != 0 && len - strlen(myx) >= 0) //字符串不为空且母串比所要查找的字符串长
    {
        for (int i = firstc; i < len - strlen(myx) + 1; i++) //从母串的某个位置开始遍历
        {
            int j;
            for (j = 0; j < strlen(myx); j++)
            {
                if (*(str + i + j) != *(myx + j))
                    break;
            }
            if (j == strlen(myx))
            {
                location = i;
                break;
            }
        }
    }
    return location;
}
bool KString::compare(const KString &myx) //第一个字符串大于第二个则返回true，否则返回false
{
    if (strcmp(str, myx.str))
        return true;
    else
        return false;
}
bool KString::compare(const char *myx) //第一个字符串大于第二个则返回true，否则返回false
{
    if (strcmp(str, myx))
        return true;
    else
        return false;
}
KString KString::upper() //将字符串全部转化为大写
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return *this;
}
KString KString::lower() //将字符串全部转化为小写
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return *this;
}
KString::~KString()
{
    delete[] str; //析构函数一定要记得释放掉字符串指针
}