#include <iostream>
#include "2DLine.h"
using namespace std;
/*member function ------------------------------------------------*/
C2DLine::C2DLine(double x1, double y1, double x2, double y2) :m_point1(x1, y1),
 				 m_point2(x2, y2)
{
	if ((x1 == x2) && (y1 == y2))
		throw string("2DLine");    	//构建线段失败，抛出异常
}
C2DLine::C2DLine(const C2DPoint& point1, const C2DPoint& point2)
:m_point1(point1), m_point2(point2)
{
	if (point1 == point2)
		throw string("2DLine");  	//构建线段失败，抛出异常
}
C2DPoint C2DLine::GetPoint(int index) 
{
	return index == 0 ? m_point1 : m_point2;
}
double C2DLine::GetLength()const
{
	return m_point1.GetDistance(m_point2);
}
void C2DLine::MoveToX(double x) 	//沿X轴平移
{
	m_point1.MoveToX(x);
	m_point2.MoveToX(x);
}
void C2DLine::MoveToY(double y) 	//沿Y轴平移
{
	m_point1.MoveToY(y);
	m_point2.MoveToY(y);
}
double C2DLine::GetArea()const  	//计算面积
{
	return 0;
}
void C2DLine::show()const
{
	m_point1.show();
	cout << "--->";
	m_point2.show();
}
