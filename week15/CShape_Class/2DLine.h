#ifndef  _2D_LINE_H
#define  _2D_LINE_H
#include "shape.h"
#include "2DPoint.h"
class C2DLine :public CShape2D
{
private:
	C2DPoint m_point1, m_point2;
public:
	C2DLine(double = 0, double = 0, double = 0, double = 0);
	C2DLine(const C2DPoint&, const C2DPoint&);
	C2DPoint GetPoint(int);  
	double GetLength()const; 
	virtual void MoveToX(double); 		//��X��ƽ��
	virtual void MoveToY(double);		//��Y��ƽ��
	virtual double GetArea()const;  		//�������
	virtual void show()const;      		//��ʾ����Ϣ���麯��
};
#endif
