#include <iostream>
#include "1DPoint.h"
using namespace std;
/*member function ------------------------------------------------*/
C1DPoint::C1DPoint(double x)
{
	m_x = x;
}
void C1DPoint::MoveTo(double x)
{
	m_x += x;
}
double C1DPoint::GetLength()const
{
	return 0;
}
double C1DPoint::GetX()const
{
	return m_x;
}
void C1DPoint::show()const
{
	cout << m_x;
}
double C1DPoint::GetDistance(const C1DPoint& point)const //计算两个点之间的距离
{
	return m_x - point.m_x;
}
/*friend function------------*/
int operator==(const C1DPoint& point1, const C1DPoint& point2)
{
	if (point1.m_x == point2.m_x)
		return 1;
	else
		return 0;
}
