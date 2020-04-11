#ifndef _CTIME_H_
#define _CTIME_H_
//#include <iostream>
//#include <string>
class CTime
{
private:
    int m_hour, m_minute, m_second;

public:
    CTime(int = 0, int = 0, int = 0);
    CTime(const std::string &);
    CTime(const char *);
    void set_time(int, int, int);
    /*friend function*******************/
    friend CTime operator+(CTime, int);    //加法
    friend int operator-(CTime, CTime);    //减法
    friend CTime &operator++(CTime &);     //前自增
    friend CTime operator++(CTime &, int); //后自增
    friend std::istream &operator>>(std::istream &, CTime &);
    friend std::ostream &operator<<(std::ostream &, const CTime &);
};
#endif