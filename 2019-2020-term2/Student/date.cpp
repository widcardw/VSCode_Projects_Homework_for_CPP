#include <iostream>
#include "date.h"
using namespace std;
Date::Date(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}
Date::Date() {}
Date::Date(const Date &oneday)
{
    year_ = oneday.year_;
    month_ = oneday.month_;
    day_ = oneday.day_;
}
Date &Date::operator=(const Date &oneday)
{
    if (this == &oneday)
        return *this;
    year_ = oneday.year_;
    month_ = oneday.month_;
    day_ = oneday.day_;
    return *this;
}
void Date::date_print()
{
    cout << year_ << "-" << month_ << "-" << day_;
}
Date::~Date() {}
std::istream &operator>>(std::istream &in, Date &oneday)
{
    in >> oneday.year_ >> oneday.month_ >> oneday.day_;
    return in;
}
std::ostream &operator<<(std::ostream &out, Date &oneday)
{
    out << oneday.year_ << "-" << oneday.month_ << "-" << oneday.day_;
    return out;
}