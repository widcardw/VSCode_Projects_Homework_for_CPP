#include <iostream>
#include "2DRectangle.h"
using namespace std;
/*member function -------------------------------------------------*/
C2DRectangle::C2DRectangle(double x1, double y1, double x2, double y2) 
 			:m_point1(x1, y1), m_point2(x2, y2)
{
	if ((x1 == x2) || (y1 == y2))
	{
		throw string("Rectangle");
	}
}
C2DRectangle::C2DRectangle(const C2DPoint& point1, 
const C2DPoint& point2) :m_point1(point1), m_point2(point1)
{
	if (m_point1 == m_point2)
	{
		throw string("Rectangle");
	}
}
C2DPoint C2DRectangle::GetPoint(int index)const 	//获取点
{
	return index == 0 ? m_point1 : m_point2;
}
void C2DRectangle::MoveToX(double x) 				//沿X轴平移
{
	m_point1.MoveToX(x);
	m_point2.MoveToX(x);
}
void C2DRectangle::MoveToY(double y) 				//沿Y轴平移
{
	m_point1.MoveToY(y);
	m_point2.MoveToY(y);
}
double C2DRectangle::GetArea()const  				//计算面积
{
	double d1 = m_point1.GetX() - m_point2.GetX();
	double d2 = m_point1.GetY() - m_point2.GetY();
	return  d1*d2;
}
void C2DRectangle::show()const
{
	m_point1.show();
	cout << "=====>";
	m_point2.show();
}
