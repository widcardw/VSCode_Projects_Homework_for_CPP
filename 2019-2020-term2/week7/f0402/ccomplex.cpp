#include <iostream>
#include "ccomplex.h"
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
