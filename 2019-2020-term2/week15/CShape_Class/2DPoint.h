#ifndef  _2D_POINT_H
#define  _2D_POINT_H
#include "shape.h"
class C2DPoint :public CShape2D
{
private:
	double m_x, m_y;   									//坐标
public:
	C2DPoint(double x = 0, double y = 0);
	double GetX()const;
	double GetY()const;
	double GetDistance(const C2DPoint&)const;
	virtual void MoveToX(double); 						//沿X轴平移
	virtual void MoveToY(double); 						//沿Y轴平移
	virtual double GetArea()const;  						//计算面积
	virtual void show()const;

	/*friend function -------------*/
	friend int operator==(const C2DPoint&, const C2DPoint&);	//比较两个点是否相同
};
#endif 
