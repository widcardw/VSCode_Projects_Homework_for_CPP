/********************************************************
 * File:date.h
*********************************************************/
#ifndef _DATE_H_
#define _DATE_H_
//#include <iostream>
//#include <string>
class CDate
{
private:
    int m_year, m_month, m_day;

public:
    CDate(int = 2000, int = 1, int = 1); //构造函数
    CDate(const std::string &);          //构造函数
    CDate(const char *);                 //构造函数
    void set_date(int, int, int);        //设置日期
    int IsLeap() const;                  //常成员函数:判断闰年
    /*friend function*********************/
    friend CDate operator+(CDate, int);    //加法
    friend int operator-(CDate, CDate);    //日期相减返回天数
    friend CDate &operator++(CDate &);     //前自增
    friend CDate operator++(CDate &, int); //后自增
    friend std::istream &operator>>(std::istream &, CDate &);
    friend std::ostream &operator<<(std::ostream &, const CDate &);
};
#endif