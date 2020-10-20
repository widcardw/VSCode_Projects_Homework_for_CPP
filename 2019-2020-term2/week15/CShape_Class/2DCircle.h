#ifndef _2D_CIRCLE_H
#define _2D_CIRCLE_H
#include "shape.h"
#include "2DPoint.h"
class C2DCircle:public CShape2D
{
private:
	C2DPoint m_point;  				//Բ������
	double m_r;        				//�뾶
public:
	C2DCircle(double = 0, double = 0, double = 1);
	C2DCircle(const C2DPoint&, double);
	C2DPoint GetPoint()const; 		//��ȡԲ������
	double GetRadius()const;  		//��ȡ�뾶
	virtual void MoveToX(double); 	//��X��ƽ��
	virtual void MoveToY(double); 	//��Y��ƽ��
	virtual double GetArea()const;	//�������
	virtual void show()const;      	//��ʾԲ��Ϣ���麯��
};
#endif
