#include <iostream>
#include "f0406.h"
using namespace std;
/*member function ------------------------------------------------*/
CComplex::CComplex(double re, double im)
{
    m_re = re;
    m_im = im;
}
inline void CComplex::set_re(double re)
{
    m_re = re;
}
inline void CComplex::set_im(double im)
{
    m_im = im;
}
void CComplex::display() const
{
    cout << m_re << "+" << m_im << "i";
}
/*friend function--------------------------------------------------*/
CComplex &operator++(CComplex &cobj)
{
    ++cobj.m_re;
    return cobj;
}
CComplex operator++(CComplex &cobj, int)
{
    CComplex temp(cobj); //先保存原来对象到 temp 中
    ++cobj.m_re;
    return temp;
}
CComplex operator+(const CComplex &c1, const CComplex &c2)
{
    CComplex temp(c1); //用 c1 复制构造临时对象 temp
    temp.m_re += c2.m_re;
    temp.m_im += c2.m_im;
    return temp;
}
std::istream &operator>>(std::istream &in, CComplex &obj)
{
    in >> obj.m_re >> obj.m_im;
    return in;
}
std::ostream &operator<<(std::ostream &out, CComplex &obj)
{
    out << obj.m_re << "+" << obj.m_im << "i";
    return out;
}
