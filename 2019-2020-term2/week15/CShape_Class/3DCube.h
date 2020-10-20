#ifndef  _3D_CUBE_H
#define  _3D_CUBE_H
#include "shape.h"
#include "3DPoint.h"
class C3DCube :public CShape3D
{
private:
	C3DPoint m_point1, m_point2;
public:
	C3DCube(double = 0, double = 0, double = 0, double = 1, double = 1, double = 1);
	C3DCube(const C3DPoint&, const C3DPoint&);
	C3DPoint GetPoint(int) const;
	virtual void MoveToX(double); 		//��X��ƽ��
	virtual void MoveToY(double); 		//��Y��ƽ��
	virtual void MoveToZ(double); 		//��Z��ƽ��
	virtual double GetArea()const;   	//�������
	virtual double GetVolume()const;	//�������
	virtual void show()const;
};
#endif 
