#ifndef _3D_RECTANGLE_H
#define _3D_RECTANGLE_H
#include "2DPoint.h"
class C2DRectangle :public CShape2D
{
private:
	C2DPoint m_point1, m_point2;
public:
	C2DRectangle(double = 0, double = 0, double = 1, double = 1);
	C2DRectangle(const C2DPoint&, const C2DPoint&);
	C2DPoint GetPoint(int)const;    		//��ȡ��
	virtual void MoveToX(double); 		//��X��ƽ��
	virtual void MoveToY(double); 		//��Y��ƽ��
	virtual double GetArea()const;  		//�������
	virtual void show()const;       		//��ʾ��Ϣ���麯��
};
#endif
