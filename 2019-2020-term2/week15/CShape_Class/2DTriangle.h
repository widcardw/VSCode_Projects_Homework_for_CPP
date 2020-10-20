#ifndef _2D_TRIANGLE_H
#define _2D_TRIANGLE_H
#include "2DPoint.h"
class C2DTriangle :public CShape2D
{
private:
	C2DPoint m_point1, m_point2, m_point3;
public:
	C2DTriangle(double = 0, double = 0, double = 1, double = 1, double = 2,
 				double = 2);
	C2DTriangle(const C2DPoint& point1, const C2DPoint& point2, const
 				C2DPoint& point3);
	C2DPoint GetPoint(int); 				//获取点
	virtual void MoveToX(double); 		//沿X轴平移
	virtual void MoveToY(double); 		//沿Y轴平移
	virtual double GetArea()const;  		//计算面积
	virtual void show()const;
};
#endif 
