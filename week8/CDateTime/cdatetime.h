/********************************************************************
File name : datetime.h
Description : 日期时间类头文件
********************************************************************/
#ifndef _DATE_TIME_H
#define _DATE_TIME_H
#include <iostream>
#include <string>
/*class CDate define ------------------------------------------------*/
class CDate
{
private:
    int m_year, m_month, m_day; //年月日
public:
    CDate(int = 2000, int = 1, int = 1); //构造函数
    CDate(const std::string &);          //构造函数
    CDate(const char *);                 //构造函数
    void set_date(int, int, int);
    int IsLeap() const; //常成员函数
    /*friend function ---------------------------------------*/
    friend CDate operator+(CDate, int); //加法
    friend int operator-(CDate, CDate);
    friend CDate &operator++(CDate &);                        //前自增
    friend CDate operator++(CDate &, int);                    //后自增
    friend std::istream &operator>>(std::istream &, CDate &); //流提取运算符
    friend std::ostream &operator<<(std::ostream &, const CDate &);
    //流插入运算符
};
/*class CTime define ----------------------------------------*/
class CTime
{
private:
    int m_hour, m_minute, m_second;

public:
    CTime(int = 0, int = 0, int = 0); //构造函数
    CTime(const std::string &);       //构造函数
    CTime(const char *);
    void set_time(int, int, int);
    /*friend function ---------------------------------------*/
    friend CTime operator+(CTime, int);    //加法
    friend int operator-(CTime, CTime);    //减法
    friend CTime &operator++(CTime &);     //前自增
    friend CTime operator++(CTime &, int); //后自增
    friend std::istream &operator>>(std::istream &, CTime &);
    //流提取运算符
    friend std::ostream &operator<<(std::ostream &, const CTime &);
    //流插入运算符
};
/*class CDateTime define -------------------------------------*/
class CDateTime
{
private:
    CDate m_date;
    CTime m_time;

public:
    CDateTime(int = 2000, int = 01, int = 01, int = 0, int = 0, int = 0);
    CDateTime(const CDate &, const CTime &);
    void set_date(int, int, int); //设置日期函数
    void set_time(int, int, int); //设置时间函数
    void add_date(int);           //增加天数
    void add_time(int);           //增加秒数
    /*friend function --------------------------------------*/
    friend std::istream &operator>>(std::istream &, CDateTime &);
    //流提取运算符
    friend std::ostream &operator<<(std::ostream &, const CDateTime &);
    //流插入运算符
};
#endif
//===================================================================