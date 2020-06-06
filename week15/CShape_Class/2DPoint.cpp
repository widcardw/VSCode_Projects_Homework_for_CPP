#include <iostream>
#include "2DPoint.h"
using namespace std;
/*member function--------------------------------------------------*/
C2DPoint::C2DPoint(double x, double y)
{
	m_x = x;
	m_y = y;
}
double C2DPoint::GetX()const
{
	return m_x;
}
double C2DPoint::GetY()const
{
	return m_y;
}
double C2DPoint::GetDistance(const C2DPoint& point)const
{
	return sqrt(((m_x - point.m_x)*(m_x - point.m_x)) + ((m_y - 
				   point.m_y)*(m_y - point.m_y)));
}
void C2DPoint::MoveToX(double x)
{
	m_x += x;
}
void C2DPoint::MoveToY(double y)
{
	m_y += y;
}
double C2DPoint::GetArea()const
{
	return 0;
}
void C2DPoint::show()const
{
	cout << "(" << m_x << "," << m_y << ")";
}
/*friend function -------------*/
int operator==(const C2DPoint& point1, const C2DPoint& point2)
{
	if ((point1.m_x == point2.m_x) && (point1.m_y == point2.m_y))
		return 1;
	else
		return 0;
}
