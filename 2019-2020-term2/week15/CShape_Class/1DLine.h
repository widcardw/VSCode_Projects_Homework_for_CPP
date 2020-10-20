#ifndef _1D_LINE_H
#define _1D_LINE_H
#include "shape.h"
#include "1DPoint.h"
class C1DLine :public CShape1D
{
private:
	C1DPoint m_point1, m_point2;
public:
	C1DLine(double = 0, double = 1);            		//���캯��
	C1DLine(const C1DPoint&, const C1DPoint&);  	//���캯��
	virtual void MoveTo(double x); 					//ƽ��
	virtual double GetLength()const; 				//���㳤��
	virtual void show()const; 						//�������
	C1DPoint GetPoint(int index)const; 				//��ȡ��һ�������
};
#endif
