#include <iostream>
#include "1DLine.h"
using namespace std;
/*member function ------------------------------------------------*/
C1DLine::C1DLine(double x1, double x2) :m_point1(x1), m_point2(x2)
{
	if (x1 == x2)
		throw string("1DLine");	//如果构成线的两个点相同，则不构成线，抛出异常
}
C1DLine::C1DLine(const C1DPoint& point1, const C1DPoint& point2) :
 				  m_point1(point1), m_point2(point2)
{
	if (point1 == point2)
		throw string("1DLine");	//如果构成线的两个点相同，则不构成线，抛出异常
}
void C1DLine::MoveTo(double x)
{
	m_point1.MoveTo(x);
	m_point2.MoveTo(x);
}
double C1DLine::GetLength()const
{
	return m_point2.GetDistance(m_point1);
}
C1DPoint C1DLine::GetPoint(int index)const
{
	return index == 0 ? m_point1 : m_point2;
}
void C1DLine::show()const
{
	m_point1.show();
	cout << "---->";
	m_point2.show();
}
