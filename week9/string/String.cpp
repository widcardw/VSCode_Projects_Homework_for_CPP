#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
class String
{
public:
    String(const char *str = "");           //普通构造函数
    String(const String &other);            //复制构造函数
    ~String();                              //析构函数
    String &operator=(const String &other); //赋值函数
    void show()
    {
        cout << m_data << endl;
    }

private:
    char *m_data; //用于保存字符串
};
String::String(const char *s)
{
    m_data = new char[strlen(s) + 1];
    assert(m_data);
    strcpy(m_data, s);
}
String::String(const String &other)
{
    m_data = new char[strlen(other.m_data) + 1];
    assert(m_data);
    strcpy(m_data, other.m_data);
}
String::~String()
{
    delete[] m_data;
}
String &String::operator=(const String &other)
{
    if (this == &other)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(other.m_data) + 1];
    assert(m_data);
    strcpy(m_data, other.m_data);
    return *this;
}
int main()
{
    String str1("aa"), str2;
    str1.show();
    str2 = str1;
    str2.show();
    String str3(str2);
    str3.show();
    return 0;
}
