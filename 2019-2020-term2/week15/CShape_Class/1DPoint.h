#ifndef  _1D_POINT_H
#define  _1D_POINT_H

#include "shape.h"  

class C1DPoint : public CShape1D    
{
private:
	double m_x;  								//������
public:
	C1DPoint(double = 0);   						//���캯��
	virtual void MoveTo(double x); 				//ƽ��
	virtual double GetLength()const;			//���㳤��
	virtual void show()const; 					//�������
	double GetX()const; 							//��ȡx����
	double GetDistance(const C1DPoint&)const;	//����������֮��ľ���

	/*friend function------------*/
	friend int operator==(const C1DPoint&, const C1DPoint&);
 												//�Ƚ��������Ƿ���ͬ
};
#endif
