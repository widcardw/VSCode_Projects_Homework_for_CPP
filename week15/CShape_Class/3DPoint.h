#ifndef  _3D_POINT_H
#define  _3D_POINT_H
#include "shape.h"
class C3DPoint :public CShape3D
{
private:
	double m_x, m_y, m_z;
public:
	C3DPoint(double = 0, double = 0, double = 0);
	double GetX()const;
	double GetY()const;
	double GetZ()const;
	double GetDistance(const C3DPoint&)const;
	virtual void MoveToX(double); 		//��X��ƽ��
	virtual void MoveToY(double); 		//��Y��ƽ��
	virtual void MoveToZ(double); 		//��Z��ƽ��
	virtual double GetArea()const;  		//�������
	virtual double GetVolume()const;	//�������
	virtual void show()const;

	/*friend function -------------------*/
	friend int operator==(const C3DPoint&, const C3DPoint&);
};
#endif 
