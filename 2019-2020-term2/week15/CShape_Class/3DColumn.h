#ifndef  _3D_COLUMN_H
#define  _3D_COLUMN_H
#include "shape.h"
#include "3DPoint.h"
class C3DColumn:public CShape3D
{
private:
	C3DPoint m_point;
	double m_r, m_high;
public:
	C3DColumn(double = 0, double = 0, double = 0, double = 1, double = 1);
	C3DColumn(const C3DPoint&, double, double);
	C3DPoint GetPoint() const;
	double GetR()const;
	double GetHigh()const;
	virtual void MoveToX(double);  			//沿X轴平移
	virtual void MoveToY(double); 			//沿Y轴平移
	virtual void MoveToZ(double); 			//沿Z轴平移
	virtual double GetArea()const;  			//计算面积
	virtual double GetVolume()const;		//计算体积
	virtual void show()const;
};
#endif 
