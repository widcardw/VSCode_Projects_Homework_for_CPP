#include <iostream>
#include "f0403.h"
#include <cassert>
#include <cstring>
using namespace std;
/*member function define-----------------------------------------*/
CMyString::CMyString(unsigned int size)
{
    m_size = size;
    if (size > 0)
    {
        mp_data = new char[size];
        assert(mp_data);
        strcpy(mp_data, "");
    }
    else
    {
        mp_data = 0; //将指针赋值为空
    }
}
CMyString::CMyString(const char *pstr)
{
    m_size = strlen(pstr) + 20; //为字符串类对象预留 20 个字符空间
    mp_data = new char[m_size]; //申请内存空间
    assert(mp_data);
    strcpy(mp_data, pstr); //复制字符串内容到 mp_data
}
CMyString::~CMyString()
{
    if (mp_data != 0)
        delete[] mp_data;
}
inline int CMyString::length() const
{
    return strlen(mp_data);
}
inline int CMyString::capacity() const
{
    return m_size;
}
char &CMyString::operator[](int index)
{
    assert(index < strlen(mp_data));
    return mp_data[index];
}
void CMyString::display() const
{
    cout << mp_data << endl;
}
CMyString &CMyString::operator=(const CMyString &obj)
{
    if (this == &obj)
        return *this;
    if (mp_data != 0)
        delete[] mp_data;
    mp_data = new char[obj.m_size];
    assert(mp_data);
    m_size = obj.m_size;
    strcpy(mp_data, obj.mp_data);
    return *this;
}
