#ifndef  _SHAPE_H
#define  _SHAPE_H
#include <math.h>
const double pi = 3.14158;    	//定义全局常量pi
class CShape                   	//图形类是一个抽象基类，为派生类提供统一界面
{
public:
	virtual void show()const = 0;    		//纯虚函数
};

class CShape1D : public CShape     			//一维图形类以图形类为基类
{
public:
	virtual void MoveTo(double) = 0; 		//平移
	virtual double GetLength()const = 0; 	//计算长度
};


class CShape2D :public CShape        		//二维图形类以图形类为基类
{
public:
	virtual void MoveToX(double) = 0; 		//沿X轴平移
	virtual void MoveToY(double) = 0; 		//沿Y轴平移
	virtual double GetArea()const = 0;  	//计算面积
};

class CShape3D :public CShape        		//三维图形类以图形类为基类
{
public:
	virtual void MoveToX(double) = 0; 		//沿X轴平移
	virtual void MoveToY(double) = 0; 		//沿y轴平移
	virtual void MoveToZ(double) = 0; 		//沿Z轴平移
	virtual double GetArea()const = 0;		//计算面积
	virtual double GetVolume()const = 0;		//计算体积
};
#endif
