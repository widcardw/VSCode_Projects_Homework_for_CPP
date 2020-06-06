#ifndef  _2D_POINT_H
#define  _2D_POINT_H
#include "shape.h"
class C2DPoint :public CShape2D
{
private:
	double m_x, m_y;   									//����
public:
	C2DPoint(double x = 0, double y = 0);
	double GetX()const;
	double GetY()const;
	double GetDistance(const C2DPoint&)const;
	virtual void MoveToX(double); 						//��X��ƽ��
	virtual void MoveToY(double); 						//��Y��ƽ��
	virtual double GetArea()const;  						//�������
	virtual void show()const;

	/*friend function -------------*/
	friend int operator==(const C2DPoint&, const C2DPoint&);	//�Ƚ��������Ƿ���ͬ
};
#endif 
