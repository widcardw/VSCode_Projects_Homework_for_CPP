#ifndef _2D_CIRCLE_H
#define _2D_CIRCLE_H
#include "shape.h"
#include "2DPoint.h"
class C2DCircle:public CShape2D
{
private:
	C2DPoint m_point;  				//圆心坐标
	double m_r;        				//半径
public:
	C2DCircle(double = 0, double = 0, double = 1);
	C2DCircle(const C2DPoint&, double);
	C2DPoint GetPoint()const; 		//获取圆心坐标
	double GetRadius()const;  		//获取半径
	virtual void MoveToX(double); 	//沿X轴平移
	virtual void MoveToY(double); 	//沿Y轴平移
	virtual double GetArea()const;	//计算面积
	virtual void show()const;      	//显示圆信息，虚函数
};
#endif
