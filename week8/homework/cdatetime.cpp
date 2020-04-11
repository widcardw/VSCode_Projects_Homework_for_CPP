#include <iostream>
#include "ctime.h"
#include "cdate.h"
#include "cdatetime.h"
using namespace std;
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