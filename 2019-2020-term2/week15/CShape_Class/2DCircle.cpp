#include <iostream>
#include "2DCircle.h"
using namespace std;
/*member function -------------------------------------------------*/
C2DCircle::C2DCircle(double x, double y, double r):m_point(x,y)
{
	if (0 == r)
		throw string("Circle"); 			//如果半径为0，则不构成圆，抛出异常
	m_r = r;
}
C2DCircle::C2DCircle(const C2DPoint& point, double r) : m_point(point)
{
	if (0 == r)
		throw string("error");  			//如果半径为0，则不构成圆，抛出异常
	m_r = r;
}
C2DPoint C2DCircle::GetPoint()const 	//获取圆心坐标
{
	return m_point;
}
double C2DCircle::GetRadius()const  	//获取半径
{
	return m_r;
}
void C2DCircle::MoveToX(double x) 		//沿X轴平移
{
	m_point.MoveToX(x);
}
void C2DCircle::MoveToY(double y) 		//沿Y轴平移
{
	m_point.MoveToY(y);
}
double C2DCircle::GetArea()const  		//计算面积
{
	return pi*m_r*m_r;
}
void C2DCircle::show()const
{
	m_point.show();
	cout << "-----" << m_r;
}
