#include <iostream>
#include "CFraction.h"
#include <cmath>
using namespace std;

int max_cmn_dvs(int a, int b)
{
    int max = abs(a) >= abs(b) ? abs(a) : abs(b);
    int min = abs(a) <= abs(b) ? abs(a) : abs(b);
    int temp;
    while (min)
    {
        temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}
int min_cmn_mtp(int a, int b)
{
    return abs(a * b) / max_cmn_dvs(a, b);
}

Fraction::Fraction(int up, int down) : m_up(up), m_down(down)
{
    if (down == 0)
    {
        cout << "分母不能为0!" << endl;
        exit(-1);
    }
    if (down < 0)
    {
        m_up = -up;
        m_down = -down;
    }
    int factor = max_cmn_dvs(m_down, m_up);
    while (factor > 1)
    {
        m_up /= factor;
        m_down /= factor;
        factor = max_cmn_dvs(m_down, m_up);
    }
}
Fraction::~Fraction() {}
inline void Fraction::set_up(int up)
{
    m_up = up;
}
inline void Fraction::set_down(int down)
{
    m_down = down;
}
void Fraction::display() const
{
    cout << m_up << "/" << m_down;
}
Fraction &operator++(Fraction &num)
{
    num.m_up += num.m_down;
    return num;
}
Fraction operator++(Fraction &num, int)
{
    Fraction temp(num);
    num.m_up += num.m_down;
    return temp;
}
Fraction &operator--(Fraction &num)
{
    num.m_up -= num.m_down;
    return num;
}
Fraction operator--(Fraction &num, int)
{
    Fraction temp(num);
    num.m_up -= num.m_down;
    return temp;
}
Fraction operator+(const Fraction &num1, const Fraction &num2)
{
    Fraction temp;
    temp.m_down = min_cmn_mtp(num1.m_down, num2.m_down);
    temp.m_up = num1.m_up * (temp.m_down / num1.m_down) + num2.m_up * (temp.m_down / num2.m_down);
    int factor = max_cmn_dvs(temp.m_down, temp.m_up);
    while (factor > 1)
    {
        temp.m_up /= factor;
        temp.m_down /= factor;
        factor = max_cmn_dvs(temp.m_down, temp.m_up);
    }
    return temp;
}
Fraction operator-(const Fraction &num1, const Fraction &num2)
{
    Fraction temp;
    temp.m_down = min_cmn_mtp(num1.m_down, num2.m_down);
    temp.m_up = num1.m_up * (temp.m_down / num1.m_down) - num2.m_up * (temp.m_down / num2.m_down);
    if (temp.m_up == 0)
    {
        temp.m_down = 1;
        return temp;
    }
    int factor = max_cmn_dvs(temp.m_down, temp.m_up);
    while (factor > 1)
    {
        temp.m_up /= factor;
        temp.m_down /= factor;
        factor = max_cmn_dvs(temp.m_down, temp.m_up);
    }
    return temp;
}
Fraction operator*(const Fraction &num1, const Fraction &num2)
{
    Fraction temp;
    temp.m_down = num1.m_down * num2.m_down;
    temp.m_up = num1.m_up * num2.m_up;
    int factor = max_cmn_dvs(temp.m_down, temp.m_up);
    while (factor > 1)
    {
        temp.m_up /= factor;
        temp.m_down /= factor;
        factor = max_cmn_dvs(temp.m_down, temp.m_up);
    }
    if (temp.m_down < 0)
    {
        temp.m_up *= -1;
        temp.m_down *= -1;
    }
    return temp;
}
Fraction operator/(const Fraction &num1, const Fraction &num2)
{
    if (num2.m_up == 0)
    {
        cout << "除数不能为0!" << endl;
        exit(-1);
    }
    Fraction temp;
    temp.m_down = num1.m_down * num2.m_up;
    temp.m_up = num1.m_up * num2.m_down;
    int factor = max_cmn_dvs(temp.m_down, temp.m_up);
    while (factor > 1)
    {
        temp.m_up /= factor;
        temp.m_down /= factor;
        factor = max_cmn_dvs(temp.m_down, temp.m_up);
    }
    if (temp.m_down < 0)
    {
        temp.m_up *= -1;
        temp.m_down *= -1;
    }
    return temp;
}
bool operator>(const Fraction &num1, const Fraction &num2)
{
    int temp1 = num1.m_up * num2.m_down;
    int temp2 = num2.m_up * num1.m_down;
    if (temp1 > temp2)
        return true;
    else
        return false;
}
bool operator<(const Fraction &num1, const Fraction &num2)
{
    int temp1 = num1.m_up * num2.m_down;
    int temp2 = num2.m_up * num1.m_down;
    if (temp1 < temp2)
        return true;
    else
        return false;
}
bool operator==(const Fraction &num1, const Fraction &num2)
{
    int temp1 = num1.m_up * num2.m_down;
    int temp2 = num2.m_up * num1.m_down;
    if (temp1 == temp2)
        return true;
    else
        return false;
}
std::istream &operator>>(std::istream &in, Fraction &num)
{
    if (num.m_down == 0)
    {
        cout << "分母不能为0!" << endl;
        exit(-1);
    }
    in >> num.m_up >> num.m_down;
    return in;
}
std::ostream &operator<<(std::ostream &out, Fraction &num)
{
    out << num.m_up << "/" << num.m_down;
    return out;
}