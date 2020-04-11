/********************************************************************
File name : datetime-driver.cpp
Description : 日期时间类测试程序文件
********************************************************************/
#include <iostream>
#include "cdatetime.h"
using namespace std;
int main()
{
    CDate date1, date2("2015-08-26");
    cout << "date1: " << date1 << endl;
    cout << "date2: " << date2 << endl;
    CDate date3 = date1 + 52;
    cout << "date3: " << date3 << endl;
    int num = date1 - date3;
    cout << "num: " << num << endl;
    cout << "date1++: " << date1++ << endl;
    cout << "date1: " << date1 << endl;
    cout << "++date1: " << ++date1 << endl;
    cout << "date1: " << date1 << endl;
    cout << "===============================\n";
    CTime time1, time2("9:23:34");
    cout << "time1: " << time1 << endl;
    cout << "time2: " << time2 << endl;
    CTime time3 = time1 + 82;
    cout << "time3: " << time3 << endl;
    num = time2 - time1;
    cout << "num: " << num << endl;
    cout << "time1++: " << time1++ << endl;
    cout << "time1: " << time1 << endl;
    cout << "++time1: " << ++time1 << endl;
    cout << "time1: " << time1 << endl;
    cout << "===============================\n";
    CDateTime datetime1, datetime2(2015, 8, 27, 10, 45, 35);
    cout << "datetime1: " << datetime1 << endl;
    cout << "datetime2: " << datetime2 << endl;
    datetime1.add_date(3);
    cout << "datetime1: " << datetime1 << endl;
    datetime1.add_time(100);
    cout << "datetime1: " << datetime1 << endl;
    datetime1.set_date(2010, 8, 27);
    cout << "datetime1: " << datetime1 << endl;
    datetime1.set_time(10, 48, 21);
    cout << "datetime1: " << datetime1 << endl;
    return 0;
}