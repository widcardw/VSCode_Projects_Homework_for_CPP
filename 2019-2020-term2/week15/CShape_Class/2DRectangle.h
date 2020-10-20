#ifndef _3D_RECTANGLE_H
#define _3D_RECTANGLE_H
#include "2DPoint.h"
class C2DRectangle :public CShape2D
{
private:
	C2DPoint m_point1, m_point2;
public:
	C2DRectangle(double = 0, double = 0, double = 1, double = 1);
	C2DRectangle(const C2DPoint&, const C2DPoint&);
	C2DPoint GetPoint(int)const;    		//获取点
	virtual void MoveToX(double); 		//沿X轴平移
	virtual void MoveToY(double); 		//沿Y轴平移
	virtual double GetArea()const;  		//计算面积
	virtual void show()const;       		//显示信息，虚函数
};
#endif
