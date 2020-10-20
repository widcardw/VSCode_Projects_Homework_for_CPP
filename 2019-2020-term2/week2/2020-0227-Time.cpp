/*
����һ��ʱ����Time��ӵ��ʱ����3�����ݳ�Ա��
��Ա�����������캯��������������ʱ�����ֵ��
Add����Ϊ���ֵ��1��Print���Դ�ӡ��ǰ�����ֵ
*/

#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    Time(){};
    void Print()
    {
        cout << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
    }
    void init_time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    Time Add()
    {
        Time next;
        next.hour = hour;
        next.minute = minute;
        next.second = second + 1;
        if (next.second >= 60)
        {
            next.second = 0;
            next.minute++;
            if (next.minute >= 60)
            {
                next.minute = 0;
                next.hour++;
            }
        }
        return next;
    }
};
int main()
{
    Time now(16, 9, 50);
    now.Print();
    Time nexts = now.Add();
    nexts.Print();
    system("pause");
    return 0;
}