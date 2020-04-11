/********************************************************
 * File:date.h
*********************************************************/
#ifndef _DATE_H_
#define _DATE_H_
//#include <iostream>
//#include <string>
class CDate
{
private:
    int m_year, m_month, m_day;

public:
    CDate(int = 2000, int = 1, int = 1); //���캯��
    CDate(const std::string &);          //���캯��
    CDate(const char *);                 //���캯��
    void set_date(int, int, int);        //��������
    int IsLeap() const;                  //����Ա����:�ж�����
    /*friend function*********************/
    friend CDate operator+(CDate, int);    //�ӷ�
    friend int operator-(CDate, CDate);    //���������������
    friend CDate &operator++(CDate &);     //ǰ����
    friend CDate operator++(CDate &, int); //������
    friend std::istream &operator>>(std::istream &, CDate &);
    friend std::ostream &operator<<(std::ostream &, const CDate &);
};
#endif