/*******************************************************************
 * File:cpoint.cpp
********************************************************************/
#include <iostream>
#include "cpoint.h"
using namespace std;

CPoint::CPoint(double x, double y)
{
    x_pos_ = x;
    y_pos_ = y;
}
inline void CPoint::set_x(double x)
{
    x_pos_ = x;
}
inline void CPoint::set_y(double y)
{
    y_pos_ = y;
}
void CPoint::display() const
{
    cout << "(" << x_pos_ << "," << y_pos_ << ")";
}
CPoint &operator++(CPoint &cdot)
{
    ++cdot.x_pos_;
    ++cdot.y_pos_;
    return cdot;
}
CPoint operator++(CPoint &cdot, int)
{
    CPoint temp(cdot);
    ++cdot.x_pos_;
    ++cdot.y_pos_;
    return temp;
}
CPoint operator+(const CPoint &d1, const CPoint &d2)
{
    CPoint temp(d1);
    temp.x_pos_ += d2.x_pos_;
    temp.y_pos_ += d2.y_pos_;
    return temp;
}
std::istream &operator>>(std::istream &in, CPoint &cdot)
{
    in >> cdot.x_pos_ >> cdot.y_pos_;
    return in;
}
std::ostream &operator<<(std::ostream &out, CPoint &cdot)
{
    out << "(" << cdot.x_pos_ << "," << cdot.y_pos_ << ")";
    return out;
}