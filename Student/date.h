#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private:
    int year_;
    int month_;
    int day_;

public:
    Date(int year, int month, int day);
    Date();
    Date(const Date &oneday);
    Date &operator=(const Date &oneday);
    void date_print();
    ~Date();
    friend std::istream &operator>>(std::istream &, Date &);
    friend std::ostream &operator<<(std::ostream &, Date &);
};

#endif