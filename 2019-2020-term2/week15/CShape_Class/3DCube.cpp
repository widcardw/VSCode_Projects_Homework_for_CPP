#include <iostream>
#include "3DCube.h"
using namespace std;

/*member function ------------------------------------------------*/
C3DCube::C3DCube(double x1, double y1, double z1, double x2, double y2, double z2)
:m_point1(x1, y1, z1), m_point2(x2, y2, z2)
{
	if ((x1 == x2) || (y1 == y2) || (z1 == z2))
		throw string("Cube");
}
C3DCube::C3DCube(const C3DPoint& point1, const C3DPoint& point2)
: m_point1(point1), m_point2(point2)
{
	if (m_point1 == m_point2)
		throw string("Cube");
}
C3DPoint C3DCube::GetPoint(int index)const
{
	return index == 0?m_point1: m_point2;
}
void C3DCube::MoveToX(double x) 		//沿X轴平移
{
	m_point1.MoveToX(x);
	m_point2.MoveToX(x);
}
void C3DCube::MoveToY(double y) 		//沿Y轴平移
{
	m_point1.MoveToY(y);
	m_point2.MoveToY(y);
}
void C3DCube::MoveToZ(double z) 		//沿Z轴平移
{
	m_point1.MoveToZ(z);
	m_point2.MoveToZ(z);
}
double C3DCube::GetArea()const  		//计算面积
{
	/*计算表面积 ----*/
	double d1 = m_point1.GetX() - m_point2.GetX(); 
	double d2 = m_point1.GetY() - m_point2.GetY(); 
	double d3 = m_point1.GetZ() - m_point2.GetZ(); 
	
	double area = d1*d2 + d2*d3 + d3*d1;
	return 2 * area;
}
double C3DCube::GetVolume()const		//计算体积
{
	double d1 = m_point1.GetX() - m_point2.GetX();
	double d2 = m_point1.GetY() - m_point2.GetY();
	double d3 = m_point1.GetZ() - m_point2.GetZ();
	return d1*d2*d3;
}
void C3DCube::show()const
{
	m_point1.show();
	cout << "=======>";
	m_point2.show();
}
