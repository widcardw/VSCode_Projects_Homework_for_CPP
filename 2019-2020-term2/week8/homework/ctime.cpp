#include <iostream>
#include <string>
#include "ctime.h"
using namespace std;
CTime::CTime(int hour, int minute, int second) //: m_hour(hour), m_minute(minute), m_second(second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
    temp_day = 0;
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
int CTime::rtn_tmp_day()
{
    return temp_day;
}
CTime operator+(CTime time, int num)
{
    time.m_second += num;
    while (time.m_second >= 60)
    {
        time.m_second -= 60;
        ++time.m_minute;
        if (time.m_minute >= 60)
        {
            time.m_minute -= 60;
            ++time.m_hour;
        }
    } //问题:如何做到小时进位到天
    //time.m_hour %= 24;
    while (time.m_hour >= 24)
    {
        ++time.temp_day;
        time.m_hour -= 24;
    }
    return time;
}
int operator-(CTime time1, CTime time2) //减法
{
    int sum_second, hour_second, minute_second;
    int flag = 0; //0--time1>=time2;1--time1<time2
    CTime temp;

    //先保证 time1>time2
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