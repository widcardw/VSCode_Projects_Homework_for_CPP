#include <iostream>
#include "kstring.h"
#include <cstring>
#include <cassert>

KString::KString(const char *p)
{
    m_len = strlen(p);
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, p);
}
KString::KString(const KString &p)
{
    m_len = p.m_len;
    m_str = new char[m_len + 1];
    assert(m_str);
    strcpy(m_str, p.m_str);
}
KString::~KString()
{
    delete[] m_str;
}
int KString::length() const
{
    return m_len;
}
bool KString::isEmpty() const
{
    return m_len == 0 ? true : false;
}
KString &KString::operator=(const KString &p)
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
KString &KString::operator+=(const KString &p)
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
std::ostream &operator<<(std::ostream &out, KString &p)
{
    out << p.m_str;
    return out;
}
std::istream &operator>>(std::istream &in, KString &p)
{
    in >> p.m_str;
    return in;
}
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
int KString::Compare(const KString &p)
{
    return strcmp(m_str, p.m_str);
}
int KString::Compare(const char *p)
{
    return strcmp(m_str, p);
}
KString KString::Upper()
{
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] >= 'a' && m_str[i] <= 'z')
            m_str[i] -= 32;
    }
    return *this;
}
KString KString::Lower()
{
    for (int i = 0; i < m_len; ++i)
    {
        if (m_str[i] >= 'A' && m_str[i] <= 'Z')
            m_str[i] += 32;
    }
    return *this;
}