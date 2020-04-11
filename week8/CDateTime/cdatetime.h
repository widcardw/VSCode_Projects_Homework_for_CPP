/********************************************************************
File name : datetime.h
Description : ����ʱ����ͷ�ļ�
********************************************************************/
#ifndef _DATE_TIME_H
#define _DATE_TIME_H
#include <iostream>
#include <string>
/*class CDate define ------------------------------------------------*/
class CDate
{
private:
    int m_year, m_month, m_day; //������
public:
    CDate(int = 2000, int = 1, int = 1); //���캯��
    CDate(const std::string &);          //���캯��
    CDate(const char *);                 //���캯��
    void set_date(int, int, int);
    int IsLeap() const; //����Ա����
    /*friend function ---------------------------------------*/
    friend CDate operator+(CDate, int); //�ӷ�
    friend int operator-(CDate, CDate);
    friend CDate &operator++(CDate &);                        //ǰ����
    friend CDate operator++(CDate &, int);                    //������
    friend std::istream &operator>>(std::istream &, CDate &); //����ȡ�����
    friend std::ostream &operator<<(std::ostream &, const CDate &);
    //�����������
};
/*class CTime define ----------------------------------------*/
class CTime
{
private:
    int m_hour, m_minute, m_second;

public:
    CTime(int = 0, int = 0, int = 0); //���캯��
    CTime(const std::string &);       //���캯��
    CTime(const char *);
    void set_time(int, int, int);
    /*friend function ---------------------------------------*/
    friend CTime operator+(CTime, int);    //�ӷ�
    friend int operator-(CTime, CTime);    //����
    friend CTime &operator++(CTime &);     //ǰ����
    friend CTime operator++(CTime &, int); //������
    friend std::istream &operator>>(std::istream &, CTime &);
    //����ȡ�����
    friend std::ostream &operator<<(std::ostream &, const CTime &);
    //�����������
};
/*class CDateTime define -------------------------------------*/
class CDateTime
{
private:
    CDate m_date;
    CTime m_time;

public:
    CDateTime(int = 2000, int = 01, int = 01, int = 0, int = 0, int = 0);
    CDateTime(const CDate &, const CTime &);
    void set_date(int, int, int); //�������ں���
    void set_time(int, int, int); //����ʱ�亯��
    void add_date(int);           //��������
    void add_time(int);           //��������
    /*friend function --------------------------------------*/
    friend std::istream &operator>>(std::istream &, CDateTime &);
    //����ȡ�����
    friend std::ostream &operator<<(std::ostream &, const CDateTime &);
    //�����������
};
#endif
//===================================================================