#include <iostream>
#include "kstring.h"
#include <cstring>
#include <cassert>

// 一些算法还可以优化,例如字符串的查找匹配可以采用KMP
// 字符串的遍历采用二分法(雾),或者构造这个字符串类的迭代器等等

KString::KString(const char *p) //构造函数
{
    m_len = strlen(p);
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, p);
}
KString::KString(const KString &p) //复制构造函数
{
    m_len = p.m_len;
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, p.m_str);
}
KString::~KString() //析构函数
{
    delete[] m_str; //删除new的m_str
}
int KString::length() const //获取字符串长度
{
    return m_len;
}
bool KString::isEmpty() const //判断字符串是否为空
{
    return m_len == 0 ? true : false;
}
KString &KString::operator=(const KString &p) //赋值号的重载,采用成员函数的方式
{
    if (this == &p)
        return *this;
    delete[] m_str;
    m_len = p.m_len;
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, p.m_str);
    return *this;
}
KString &KString::operator+=(const KString &p) //字符串拼接符号+=的重载,采用成员函数方式,适用于KString的数据类型
{
    char *tmp = new char[m_len + 1];
    strcpy(tmp, m_str);
    m_len += p.m_len;
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, tmp);
    strcat(m_str, p.m_str);
    delete[] tmp;
    return *this;
}

//字符串拼接符号+=的重载,采用成员函数方式
//适用于const char*的数据类型,即可以采用a += "string";的方式进行拼接
KString &KString::operator+=(const char *p)
{
    char *tmp = new char[m_len + 1];
    strcpy(tmp, m_str);
    m_len += strlen(p);
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, tmp);
    strcat(m_str, p);
    delete[] tmp;
    return *this;
}
//+号重载,采用友元函数,可进行拼接操作,如
// KString a("a"), b("b"), c;
// c = a + b;
KString operator+(KString &p1, KString &p2)
{
    KString temp;
    temp.m_len = p1.m_len + p2.m_len;
    temp.m_str = new char[temp.m_len + 1];
    assert(temp.m_str);
    strcpy(temp.m_str, p1.m_str);
    strcat(temp.m_str, p2.m_str);
    return temp;
}
//+号重载,采用友元函数,可进行拼接操作,如
// KString a("a"), c;
// c = a + "abc";
KString operator+(KString &p1, const char *p2)
{
    KString temp;
    temp.m_len = p1.m_len + strlen(p2);
    temp.m_str = new char[temp.m_len + 1];
    assert(temp.m_str);
    strcpy(temp.m_str, p1.m_str);
    strcat(temp.m_str, p2);
    return temp;
}
//+号重载,采用友元函数,可进行拼接操作,如
// KString a("a"), c;
// c = "abc" + a;
KString operator+(const char *p1, KString &p2)
{
    KString temp;
    temp.m_len = strlen(p1) + p2.m_len;
    temp.m_str = new char[temp.m_len + 1];
    assert(temp.m_str);
    strcpy(temp.m_str, p1);
    strcat(temp.m_str, p2.m_str);
    return temp;
}
//判断两个字符串是否完全一样
bool KString::operator==(const KString &p)
{
    if (m_len != p.m_len)
        return false;
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] != p.m_str[i])
            return false;
    }
    return true;
}
//判断两个字符串是否不一样
bool KString::operator!=(const KString &p)
{
    if (m_len != p.m_len)
        return true;
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] != p.m_str[i])
            return true;
    }
    return false;
}
//字符串的比较,按照[字符的ASCII码>字符串长度]的级别比较
bool KString::operator>(const KString &p)
{
    int min_len = m_len < p.m_len ? m_len : p.m_len;
    for (int i = 0; i < min_len; ++i)
    {
        if (m_str[i] == p.m_str[i])
            continue;
        else if (m_str[i] > p.m_str[i])
            return true;
        else
            return false;
    }
    if (m_len > p.m_len)
        return true;
    return false;
}
bool KString::operator>=(const KString &p)
{
    return !((*this) < p);
}
bool KString::operator<=(const KString &p)
{
    return !((*this) > p);
}
bool KString::operator<(const KString &p)
{
    int min_len = m_len < p.m_len ? m_len : p.m_len;
    for (int i = 0; i < min_len; ++i)
    {
        if (m_str[i] == p.m_str[i])
            continue;
        else if (m_str[i] < p.m_str[i])
            return true;
        else
            return false;
    }
    if (m_len < p.m_len)
        return true;
    return false;
}
//输出流符号重载
std::ostream &operator<<(std::ostream &out, KString &p)
{
    out << p.m_str;
    return out;
}
//输入流符号重载
std::istream &operator>>(std::istream &in, KString &p)
{
    in >> p.m_str;
    return in;
}
//查找单个字符
int KString::find(const char c, int startPosition) const
{
    int i = startPosition;
    while (*(m_str + i) != '\0' && *(m_str + i) != c)
    {
        i++;
    }
    if (i == m_len)
        i = -1;
    return i;
}
//查找字符串(待完善,因为可以采用KMP等算法进行优化)
int KString::find(const char *p, int startPosition) const
{
    int loc = -1;
    assert(strlen(p) != 0 && m_len - strlen(p) >= 0);
    for (int i = startPosition; i < m_len - strlen(p) + 1; ++i)
    {
        int j;
        for (j = 0; j < strlen(p); ++j)
            if (*(m_str + i + j) != *(p + j))
                break;
        if (j == strlen(p))
        {
            loc = i;
            break;
        }
    }
    return loc;
}
//字符串的比较
int KString::Compare(const KString &p)
{
    return strcmp(m_str, p.m_str);
}
int KString::Compare(const char *p)
{
    return strcmp(m_str, p);
}
//将字符串中的小写转成大写
KString KString::Upper()
{
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] >= 'a' && m_str[i] <= 'z')
            m_str[i] -= 32;
    }
    return *this;
}
//将字符串中的大写转小写
KString KString::Lower()
{
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] >= 'A' && m_str[i] <= 'Z')
            m_str[i] += 32;
    }
    return *this;
}