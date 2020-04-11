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
    friend CTime operator+(CTime, int);    //�ӷ�
    friend int operator-(CTime, CTime);    //����
    friend CTime &operator++(CTime &);     //ǰ����
    friend CTime operator++(CTime &, int); //������
    friend std::istream &operator>>(std::istream &, CTime &);
    friend std::ostream &operator<<(std::ostream &, const CTime &);
};
#endif