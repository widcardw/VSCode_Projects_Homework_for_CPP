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
	virtual void MoveToX(double); 		//沿X轴平移
	virtual void MoveToY(double); 		//沿Y轴平移
	virtual void MoveToZ(double); 		//沿Z轴平移
	virtual double GetArea()const;   	//计算面积
	virtual double GetVolume()const;	//计算体积
	virtual void show()const;
};
#endif 
