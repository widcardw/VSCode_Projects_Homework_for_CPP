#include <iostream>
#include "3DColumn.h"
using namespace std;

/*member function ------------------------------------------------*/
C3DColumn::C3DColumn(double x, double y, double z, double r, double h):
    					   m_point(x, y, z)
{
	m_r = r;
	m_high = h;
	if ((h == 0) || (r == 0))
		throw string("Column");
}
C3DColumn::C3DColumn(const C3DPoint& point, double r, double h) :m_point(point)
{
	m_r = r;
	m_high = h;
	if ((h == 0) || (r == 0))
		throw string("Column");
}
inline C3DPoint C3DColumn::GetPoint() const
{
	return m_point;
}
inline double C3DColumn::GetR()const
{
	return m_r;
}
double C3DColumn::GetHigh()const
{
	return m_high;
}
void C3DColumn::MoveToX(double x) 		//沿X轴平移
{
	m_point.MoveToX(x);
}
void C3DColumn::MoveToY(double y) 		//沿Y轴平移
{
	m_point.MoveToY(y);
}
void C3DColumn::MoveToZ(double z) 		//沿Z轴平移
{
	m_point.MoveToZ(z);
}
double C3DColumn::GetArea()const  		//计算面积
{
	double l = pi*2*m_r;
	double area = l*m_high + pi*m_r*m_r*2;
	return area;
}
double C3DColumn::GetVolume()const		//计算体积
{
	double s_area = pi*m_r*m_r;
	return s_area*m_high;
}
void C3DColumn::show()const
{
	m_point.show();
	cout << "---->:"<<m_r<<"== == == == > "<<m_high;
}
