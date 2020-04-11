/********************************************************************
File name : datetime.cpp
Description : 日期时间类源文件
********************************************************************/
#include <iostream>
#include <string>
#include "cdatetime.h"
using namespace std;
/*globle const define-------------------------------------------*/
const int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
/*member function of class CDate -------------------------------*/
CDate::CDate(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}
CDate::CDate(const string &str)
{
    int index = 0;
    index = str.find("-", 0);               //找横线
    string str_temp = str.substr(0, index); //子串
    m_year = atoi(str_temp.c_str());        //转成c的str类型
    int index2 = str.find("-", index + 1);  //从上一个地方开始找
    str_temp = str.substr(index + 1, index2 - index - 1);
    m_month = atoi(str_temp.c_str());
    str_temp = str.substr(index2 + 1, str.length() - index2);
    m_day = atoi(str_temp.c_str());
}
CDate::CDate(const char *str)
{
    string str_bak = str;
    int index = 0;
    index = str_bak.find("-", 0);
    string str_temp = str_bak.substr(0, index);
    m_year = atoi(str_temp.c_str());
    int index2 = str_bak.find("-", index + 1);
    str_temp = str_bak.substr(index + 1, index2 - index - 1);
    m_month = atoi(str_temp.c_str());
    str_temp = str_bak.substr(index2 + 1, str_bak.length() - index2);
    m_day = atoi(str_temp.c_str());
}
void CDate::set_date(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}
int CDate::IsLeap() const
{
    if ((m_year % 400 == 0) || ((m_year % 4 == 0) && (m_year % 100 != 0)))
        return 1;
    else
        return 0;
}
/*friend function -----------------------------------*/
/*此函数为全局内联函数，用于判断某年是否为闰年 ---------*/
inline bool IsLeap(int year)
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}
CDate operator+(CDate date, int num)
{
    date.m_day += num;
    /*处理日的进位--------*/
    if ((2 == date.m_month) && (date.IsLeap())) //处理 2 月问题
    {
        if (date.m_day > month_days[date.m_month] + 1)
        {
            date.m_day -= month_days[date.m_month] + 1;
            ++date.m_month;
        }
    }
    else
    {
        if (date.m_day > month_days[date.m_month])
        {
            date.m_day -= month_days[date.m_month];
            ++date.m_month;
        }
    }
    /*处理月的进位---------*/
    if (date.m_month > 12)
    {
        date.m_month -= 12;
        ++date.m_year;
    }
    return date;
}
int operator-(CDate date1, CDate date2)
{
    int sum_days = 0, y_days = 0, m_days = 0;
    int flag = 0; //0--date1>=date2; 1--date1<date2
    CDate temp;
    /*先排序日期，保证 date1>=date2 -------------*/
    if ((date1.m_year < date2.m_year) || ((date1.m_year == date2.m_year) && (date1.m_month < date2.m_month)) || ((date1.m_year == date2.m_year) && (date1.m_month == date2.m_month) && (date1.m_day < date2.m_day)))
    {
        temp = date1;
        date1 = date2;
        date2 = temp;
        flag = 1;
    }
    int i = date2.m_year + 1;
    //计算年间差的天数
    while (i < date1.m_year)
    {
        y_days += IsLeap(i) ? 366 : 365;
        ++i;
    }
    //计算 date1 和 date2 本身的天数
    int value1 = 0;
    for (i = 0; i < date1.m_month; ++i)
    {
        value1 += month_days[i];
    }
    value1 += date1.m_day;
    if (date1.IsLeap())
    {
        value1 += date1.m_month > 2 ? 1 : 0;
    }
    int value2 = 0;
    for (i = 0; i < date2.m_month; ++i)
    {
        value2 += month_days[i];
    }
    value2 += date2.m_day;
    if (date2.IsLeap())
    {
        value1 += date2.m_month > 2 ? 1 : 0;
    }
    if (date1.m_year == date2.m_year)
    {
        m_days = value1 - value2;
    }
    else
    {
        m_days = (date2.IsLeap()) ? (366 - value2 + value1) : (365 - value2 + value1);
    }
    return flag == 0 ? (y_days + m_days) : -(y_days + m_days);
}
CDate &operator++(CDate &date) //前自增
{
    date = date + 1;
    return date;
}
CDate operator++(CDate &date, int) //后自增
{
    CDate temp(date);
    date = date + 1;
    return temp;
}
std::istream &operator>>(std::istream &in, CDate &date) //流提取运算符
{
    in >> date.m_year >> date.m_month >> date.m_day;
    return in;
}
std::ostream &operator<<(std::ostream &out, const CDate &date)
//流插入运算符
{
    out << date.m_year << "-" << date.m_month << "-" << date.m_day;
    return out;
}
/*member function of class CTime --------------------------------*/
CTime::CTime(int hour, int minute, int second) //构造函数
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}
CTime::CTime(const string &str) //构造函数
{
    int start_index;
    string str_temp;
    start_index = str.find(":", 0);
    str_temp = str.substr(0, start_index);
    m_hour = atoi(str_temp.c_str());
    int index = str.find(":", start_index + 1);
    str_temp = str.substr(start_index + 1, index - start_index);
    m_minute = atoi(str_temp.c_str());
    str_temp = str.substr(index + 1, str.length() - index);
    m_second = atoi(str_temp.c_str());
}
CTime::CTime(const char *pstr)
{
    string str;
    str = pstr;
    int start_index;
    string str_temp;
    start_index = str.find(":", 0);
    str_temp = str.substr(0, start_index);
    m_hour = atoi(str_temp.c_str());
    int index = str.find(":", start_index + 1);
    str_temp = str.substr(start_index + 1, index - start_index);
    m_minute = atoi(str_temp.c_str());
    str_temp = str.substr(index + 1, str.length() - index);
    m_second = atoi(str_temp.c_str());
}
void CTime::set_time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}
/*friend function ---------------------------------------*/
CTime operator+(CTime time, int num) //加法
{
    time.m_second += num;
    if (time.m_second >= 60) //秒进位处理
    {
        time.m_second -= 60;
        ++time.m_minute;
        if (time.m_minute >= 60) //分钟进位处理
        {
            time.m_minute -= 60;
            ++time.m_hour;
            time.m_hour %= 24; //小时进位处理
        }
    }
    return time;
}
int operator-(CTime time1, CTime time2) //减法
{
    int sum_second, hour_second, minute_second;
    int flag = 0; //0--time1>=time2;1--time1<time2
    CTime temp;

    //先保证 tiem1>time2
    if ((time1.m_hour < time2.m_hour) || ((time1.m_hour == time2.m_hour) && (time1.m_minute < time2.m_minute)) || ((time1.m_hour == time2.m_hour) && (time1.m_minute == time2.m_minute) && (time1.m_second < time2.m_second)))
    {
        temp = time1;
        time1 = time2;
        time2 = temp;
        flag = 1;
    }
    //计算小时的秒数
    hour_second = (time1.m_hour - time2.m_hour - 1) * 3600;
    minute_second = (60 - time2.m_minute) * 60 + time1.m_minute * 60;
    sum_second = hour_second + minute_second - time2.m_second + time1.m_second;
    return flag == 0 ? sum_second : -sum_second;
}
CTime &operator++(CTime &time) //前自增
{
    time = time + 1;
    return time;
}
CTime operator++(CTime &time, int) //后自增
{
    CTime temp(time);
    time = time + 1;
    return temp;
}
std::istream &operator>>(std::istream &in, CTime &time) //流提取运算符
{
    in >> time.m_hour >> time.m_minute >> time.m_second;
    return in;
}
std::ostream &operator<<(std::ostream &out, const CTime &time) //流插入运算符
{
    out << time.m_hour << ":" << time.m_minute << ":" << time.m_second;
    return out;
}
/*member function of class CDateTime ------------------------------*/
CDateTime::CDateTime(int year, int month, int day, int hour, int minute, int second)
    : m_date(year, month, day), m_time(hour, minute, second)
{
}
CDateTime::CDateTime(const CDate &date, const CTime &time) : m_date(date), m_time(time)
{
}
void CDateTime::set_date(int year, int month, int day) //设置日期函数
{
    m_date.set_date(year, month, day);
}
void CDateTime::set_time(int hour, int minute, int second) //设置时间函数
{
    m_time.set_time(hour, minute, second);
}
void CDateTime::add_date(int days) //增加天数
{
    m_date = m_date + days;
}
void CDateTime::add_time(int seconds) //增加秒数
{
    m_time = m_time + seconds;
}
/*friend function --------------------------------------*/
std::istream &operator>>(std::istream &in, CDateTime &date_time)
//流提取运算符
{
    in >> date_time.m_date >> date_time.m_time;
    return in;
}
std::ostream &operator<<(std::ostream &out, const CDateTime &date_time)
//流插入运算符
{
    out << date_time.m_date << ":" << date_time.m_time;
    return out;
}
//===================================================================