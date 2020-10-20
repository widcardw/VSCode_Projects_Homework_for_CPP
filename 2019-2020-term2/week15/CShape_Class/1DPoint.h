#ifndef  _1D_POINT_H
#define  _1D_POINT_H

#include "shape.h"  

class C1DPoint : public CShape1D    
{
private:
	double m_x;  								//点坐标
public:
	C1DPoint(double = 0);   						//构造函数
	virtual void MoveTo(double x); 				//平移
	virtual double GetLength()const;			//计算长度
	virtual void show()const; 					//输出函数
	double GetX()const; 							//获取x坐标
	double GetDistance(const C1DPoint&)const;	//计算两个点之间的距离

	/*friend function------------*/
	friend int operator==(const C1DPoint&, const C1DPoint&);
 												//比较两个点是否相同
};
#endif
