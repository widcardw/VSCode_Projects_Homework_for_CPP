#ifndef _1D_LINE_H
#define _1D_LINE_H
#include "shape.h"
#include "1DPoint.h"
class C1DLine :public CShape1D
{
private:
	C1DPoint m_point1, m_point2;
public:
	C1DLine(double = 0, double = 1);            		//构造函数
	C1DLine(const C1DPoint&, const C1DPoint&);  	//构造函数
	virtual void MoveTo(double x); 					//平移
	virtual double GetLength()const; 				//计算长度
	virtual void show()const; 						//输出函数
	C1DPoint GetPoint(int index)const; 				//获取第一个坐标点
};
#endif
