#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *str;
    int m_len;

public:
    MyString(const char *p = "");
    MyString(const MyString &p); //copy constructor
    ~MyString();
    MyString &operator=(const MyString &p);
    void print();
    int strcompare(const MyString &p);
    MyString substr(int begin, int len);
    MyString strcate(const MyString &p);
    int subchar(const char p);
    int substrloc(const MyString &p);
};

MyString::MyString(const char *p)
{
    m_len = strlen(p);
    str = new char[m_len + 1];
    assert(str);
    strcpy(str, p);
}
MyString::MyString(const MyString &p)
{
    m_len = p.m_len;
    str = new char[m_len + 1];
    assert(str);
    strcpy(str, p.str);
}
MyString::~MyString()
{
    delete[] str;
}
MyString &MyString::operator=(const MyString &p)
{
    if (this == &p)
        return *this;
    delete[] str;
    m_len = strlen(p.str);
    str = new char[m_len + 1];
    assert(str);
    strcpy(str, p.str);
    return *this;
}
void MyString::print()
{
    cout << str << endl;
}
int MyString::strcompare(const MyString &p)
{
    return strcmp(str, p.str);
}
MyString MyString::substr(int begin, int len)
{
    assert(begin >= 0 && len >= 1 && begin < m_len && begin + len <= m_len);
    char *p = new char[m_len + 1];
    strcpy(p, str);
    p[begin + len] = '\0';
    MyString temp(p + begin);
    delete[] p;
    return temp;
}
MyString MyString::strcate(const MyString &p)
{
    char *newstr = new char[m_len + p.m_len + 1];
    assert(newstr);
    int i;
    for (i = 0; i < m_len; i++)
    {
        *(newstr + i) = *(str + i);
    }
    for (i = 0; i < p.m_len; i++)
    {
        *(newstr + m_len + i) = *(p.str + i);
    }
    *(newstr + m_len + p.m_len) = '\0';
    MyString temp(newstr);
    delete[] newstr;
    return temp;
}
int MyString::subchar(const char c)
{
    assert(c);
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == c)
            return i;
        i++;
    }
    return -1;
}
int MyString::substrloc(const MyString &p)
{
    int loc = -1;
    assert(p.m_len != 0 && m_len - p.m_len > 0);
    for (int i = 0; i < m_len - p.m_len; i++)
    {
        int j;
        for (j = 0; j < p.m_len; j++)
            if (*(str + i + j) != *(p.str + j))
                break;
        if (j == p.m_len)
        {
            loc = i;
            break;
        }
    }
    return loc;
}
int main()
{
    MyString a("agvgvkhbkjhbj"), b;
    b = a;
    a.print();
    b.print();
    MyString c = a.substr(2, 3);
    c.print();
    MyString d = "gfedcba";
    cout << a.strcompare(d) << endl;
    a.strcate(d).print();
    cout << a.subchar('d') << endl;
    return 0;
}