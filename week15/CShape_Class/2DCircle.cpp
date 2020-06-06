#include <iostream>
#include "2DCircle.h"
using namespace std;
/*member function -------------------------------------------------*/
C2DCircle::C2DCircle(double x, double y, double r):m_point(x,y)
{
	if (0 == r)
		throw string("Circle"); 			//����뾶Ϊ0���򲻹���Բ���׳��쳣
	m_r = r;
}
C2DCircle::C2DCircle(const C2DPoint& point, double r) : m_point(point)
{
	if (0 == r)
		throw string("error");  			//����뾶Ϊ0���򲻹���Բ���׳��쳣
	m_r = r;
}
C2DPoint C2DCircle::GetPoint()const 	//��ȡԲ������
{
	return m_point;
}
double C2DCircle::GetRadius()const  	//��ȡ�뾶
{
	return m_r;
}
void C2DCircle::MoveToX(double x) 		//��X��ƽ��
{
	m_point.MoveToX(x);
}
void C2DCircle::MoveToY(double y) 		//��Y��ƽ��
{
	m_point.MoveToY(y);
}
double C2DCircle::GetArea()const  		//�������
{
	return pi*m_r*m_r;
}
void C2DCircle::show()const
{
	m_point.show();
	cout << "-----" << m_r;
}
