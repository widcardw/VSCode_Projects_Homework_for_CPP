#include <iostream>
#include <string>
#include "cdate.h"
using namespace std;
const int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
CDate::CDate(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
{ /*m_year = year;
    m_month = month;
    m_day = day;*/
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
/*friend function****************/
inline bool IsLeap(int year)
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}
CDate operator+(CDate date, int num) //待完善
{
    date.m_day += num;
    while (date.m_day > month_days[date.m_month])
    {
        if ((2 == date.m_month) && (date.IsLeap())) //闰年2月
        {
            if (date.m_day > month_days[date.m_month] + 1) //如果大于29天
            {
                date.m_day -= month_days[date.m_month] + 1; //在已经加好的天数上减去29天
                ++date.m_month;                             //月份数加1
            }
            if (date.m_day == 29)
                break;
        }
        else
        {
            if (date.m_day > month_days[date.m_month]) //如果大于该月份的天数
            {
                date.m_day -= month_days[date.m_month]; //在已经加好的天数上减去该月份天数
                ++date.m_month;                         //月份数加1
            }
        }
        if (date.m_month > 12) //如果月份数大于12
        {
            date.m_month -= 12; //月份数减去12
            ++date.m_year;      //年份数加1
        }
    }
    return date;
}
int operator-(CDate date1, CDate date2)
{
    //int sum_days = 0; //总天数
    int y_days = 0; //相差多少年(整年的天数)
    int m_days = 0; //相差多少月(整月的天数)
    int flag = 0;   //flag == 0则date1>=date2否则date1<date2
    CDate temp;
    //排序保证date1>=date2
    if ((date1.m_year < date2.m_year) || (date1.m_month < date2.m_month) || (date1.m_day < date2.m_day))
    {
        temp = date1;
        date1 = date2;
        date2 = temp;
        flag = 1;
    }
    int i = date2.m_year + 1;
    while (i < date1.m_year) //计算年间差天数
    {
        y_days += IsLeap(i) ? 366 : 365;
        ++i;
    }
    int value1 = 0; //算出date1在这一年过了多少天
    for (i = 0; i < date1.m_month; ++i)
        value1 += month_days[i];
    value1 += date1.m_day; //基数,不管是不是闰年都有
    if (date1.IsLeap())    //如果是闰年,而且所在月份大于2月,则加一天
        value1 += date1.m_month > 2 ? 1 : 0;
    int value2 = 0; //同理
    for (i = 0; i < date2.m_month; ++i)
        value2 += month_days[i];
    value2 += date2.m_day;
    if (date2.IsLeap())
        value2 += date2.m_month > 2 ? 1 : 0;
    //如果年份相同, 则直接将两个value相减
    if (date1.m_year == date2.m_year)
        m_days = value1 - value2;
    else
        m_days = (date2.IsLeap()) ? (366 - value2 + value1) : (365 - value2 + value1);

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
std::istream &operator>>(std::istream &in, CDate &date)
{
    in >> date.m_year >> date.m_month >> date.m_day;
    return in;
}
std::ostream &operator<<(std::ostream &out, const CDate &date)
{
    out << date.m_year << "-" << date.m_month << "-" << date.m_day;
    return out;
}