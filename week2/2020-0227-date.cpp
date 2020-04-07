#include <iostream>
#include <cstring>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
    int week;

public:
    Date(int y, int m, int d, int w)
    {
        year = y;
        month = m;
        day = d;
        week = w;
    }
    Date(){};
    string rtn_week(int w)
    {
        w = w % 7;
        switch (w)
        {
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 0:
            return "Sunday";
        }
    }
    void print()
    {
        cout << year << "-" << month << "-" << day << " " << rtn_week(week) << endl;
    }
    bool isLeapYear()
    {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return true;
        else
            return false;
    }
    int monthdays()
    {
        if (isLeapYear())
        {
            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return 29;
            default:
                return 31;
            }
        }
        else
        {
            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return 28;
            default:
                return 31;
            }
        }
    }
    Date add()
    {
        Date nextday;
        nextday.week = (week + 1) % 7;
        nextday.day = day + 1;
        nextday.month = month;
        nextday.year = year;
        if (nextday.day > monthdays())
        {
            nextday.day = 1;
            nextday.month++;
            if (nextday.month > 12)
            {
                nextday.month = 1;
                nextday.year++;
            }
        }
        return nextday;
    }
    Date sub()
    {
        Date yesterday;
        yesterday.day = day - 1;
        yesterday.month = month;
        yesterday.year = year;
        yesterday.week = (week - 1) % 7;
        if (yesterday.day == 0)
        {
            yesterday.month--;
            yesterday.day = yesterday.monthdays();
            if (month == 0)
            {
                yesterday.month = 12;
                yesterday.year--;
            }
        }
        return yesterday;
    }
};
int main()
{
    Date today(2020, 3, 1, 7);
    today.print();
    Date tomorrow = today.add();
    tomorrow.print();
    Date yesterday = today.sub();
    yesterday.print();
    system("pause");
    return 0;
}