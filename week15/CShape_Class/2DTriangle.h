#ifndef _2D_TRIANGLE_H
#define _2D_TRIANGLE_H
#include "2DPoint.h"
class C2DTriangle :public CShape2D
{
private:
	C2DPoint m_point1, m_point2, m_point3;
public:
	C2DTriangle(double = 0, double = 0, double = 1, double = 1, double = 2,
 				double = 2);
	C2DTriangle(const C2DPoint& point1, const C2DPoint& point2, const
 				C2DPoint& point3);
	C2DPoint GetPoint(int); 				//��ȡ��
	virtual void MoveToX(double); 		//��X��ƽ��
	virtual void MoveToY(double); 		//��Y��ƽ��
	virtual double GetArea()const;  		//�������
	virtual void show()const;
};
#endif 
