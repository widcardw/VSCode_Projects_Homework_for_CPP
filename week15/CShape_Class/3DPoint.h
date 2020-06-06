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
	virtual void MoveToX(double); 		//沿X轴平移
	virtual void MoveToY(double); 		//沿Y轴平移
	virtual void MoveToZ(double); 		//沿Z轴平移
	virtual double GetArea()const;  		//计算面积
	virtual double GetVolume()const;	//计算体积
	virtual void show()const;

	/*friend function -------------------*/
	friend int operator==(const C3DPoint&, const C3DPoint&);
};
#endif 
