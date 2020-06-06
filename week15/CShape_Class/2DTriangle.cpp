#include <iostream>
#include <string>
#include "2DTriangle.h"
using namespace std;

/*member function --------------------------------------*/
C2DTriangle::C2DTriangle(double x1, double y1, double x2, double y2, 
		double x3, double y3): m_point1(x1, y1), m_point2(x2, y2),
		m_point3(x3,y3)
{
	if (((x1 - x2) / (y1 - y2)) == ((x2 - x3) / (y2 - y3)))
		throw string("Triangle");
}
C2DTriangle::C2DTriangle(const C2DPoint& point1, const C2DPoint& point2, 
						  const C2DPoint& point3): m_point1(point1), 
						  m_point2(point2), m_point3(point3)
{
	double x1 = m_point1.GetX() - m_point2.GetX();
	double y1 = m_point1.GetY() - m_point2.GetY();
	double x2 = m_point2.GetX() - m_point3.GetX();
	double y2 = m_point2.GetY() - m_point3.GetY();
	if ( x1 /y1  == x2/y2)
	{
		throw string("Triangle");
	}
}
C2DPoint C2DTriangle::GetPoint(int index) 	//获取点
{
	if (index == 0)
		return m_point1;
	else if (index == 1)
		return m_point2;
	else
		return m_point3;
}
void C2DTriangle::MoveToX(double x)  		//沿X轴平移
{
	m_point1.MoveToX(x);
	m_point2.MoveToX(x);
	m_point3.MoveToX(x);
}
void C2DTriangle::MoveToY(double y) 		//沿Y轴平移
{
	m_point1.MoveToY(y);
	m_point2.MoveToY(y);
	m_point3.MoveToY(y);
}
double C2DTriangle::GetArea()const  		//计算面积
{
	double s1, s2, s3;   					//三条边长
	s1 = m_point1.GetDistance(m_point2);
	s2 = m_point2.GetDistance(m_point3);
	s3 = m_point3.GetDistance(m_point1);
	double s = (s1 + s2 + s3) / 2;
	double area=sqrt(s*(s-s1)*(s-s2)*(s-s3));
	return area;
}
void C2DTriangle::show()const
{
	m_point1.show();
	cout << "---->";
	m_point2.show();
	cout << "---->";
	m_point3.show();
	cout << "---->";
	m_point1.show();
}
