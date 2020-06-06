#include <iostream>
#include "3DPoint.h"
using namespace std;
/*member function ------------------------------------------------*/
C3DPoint::C3DPoint(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}
double C3DPoint::GetX()const
{
	return m_x;
}
double C3DPoint::GetY()const
{
	return m_y;
}
double C3DPoint::GetZ()const
{
	return m_z;
}
double C3DPoint::GetDistance(const C3DPoint& point)const
{
	return sqrt((m_x - point.m_x)*(m_y - point.m_y)*(m_z - point.m_z));
}
void C3DPoint::MoveToX(double x) 		//沿X轴平移
{
	m_x += x;
}
void C3DPoint::MoveToY(double y) 		//沿Y轴平移
{
	m_y += y;
}
void C3DPoint::MoveToZ(double z)
{
	m_z += z;
}
double C3DPoint::GetArea()const  		//计算面积
{
	return 0;
}
double C3DPoint::GetVolume()const		//计算体积
{
	return 0;
}
void C3DPoint::show()const
{
	cout << "(" << m_x << "," << m_y << "," << m_z << ")";
}

/*friend function -------------------*/
int operator==(const C3DPoint& point1, const C3DPoint& point2)
{
	if ((point1.m_x == point2.m_x) 
	    && (point1.m_y == point2.m_y) 
	    && (point1.m_z == point2.m_z))
		return 1;
	else
		return 0;
}
