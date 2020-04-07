/*******************************************************************
 * 我的一些问题:
 *  1.对于类的嵌套, 结构体与类的嵌套会搞不清, 例如链表的操作
 *  2.对于默认构造函数和友元函数的理解不是很透彻
 *******************************************************************
 * 定义一个二维平面的点类 CPoint，包含两个坐标属性，请完成如下功能：
 * (1)定义一个带默认参数值的构造函数，参数默认值都为 0。
 * (2)定义一个前自增运算符重载函数，要求实现 CPoint 对象的两个坐标分别加 1。
 * (3)定义一个后自增运算符重载函数，要求实现 CPoint 对象的两个坐标分别加 1。
 * (4)定义一个加法运算符重载函数，要求实现 CPoint 对象的两个坐标分别加上一个实数。
 * (5)定义一个流提取运算符重载函数。
 * (6)定义一个流插入运算符重载函数。
 * (7)编程 CPoint 类的测试程序。
 *******************************************************************
 * File:cpoint.h
********************************************************************/
#ifndef _CPOINT_H_
#define _CPOINT_H_
class CPoint
{
private:
    double x_pos_, y_pos_;

public:
    CPoint(double = 0, double = 0);                            //构造函数(1)
    void set_x(double);                                        //设置横坐标
    void set_y(double);                                        //设置纵坐标
    void display() const;                                      //常成员函数:打印
    friend CPoint &operator++(CPoint &);                       //前自增运算符重载(2)
    friend CPoint operator++(CPoint &, int);                   //后自增运算符重载(3)
    friend CPoint operator+(const CPoint &, const CPoint &);   //加法运算符(4)
    friend std::istream &operator>>(std::istream &, CPoint &); //流提取运算符(5)
    friend std::ostream &operator<<(std::ostream &, CPoint &); //流插入运算符(6)
};
#endif