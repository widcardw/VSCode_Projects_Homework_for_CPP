#ifndef _DATE_TIME_H
#define _DATE_TIME_H
//#include "ctime.h"
//#include "cdate.h"
class CDateTime
{
private:
    CDate m_date;
    CTime m_time;

public:
    CDateTime(int = 2000, int = 1, int = 1, int = 0, int = 0, int = 0);
    CDateTime(const CDate &, const CTime &);
    void set_date(int, int, int);
    void set_time(int, int, int);
    void add_date(int);
    void add_time(int);

    friend std::istream &operator>>(std::istream &, CDateTime &);
    friend std::ostream &operator<<(std::ostream &, const CDateTime &);
};

#endif