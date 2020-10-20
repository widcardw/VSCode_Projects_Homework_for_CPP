#ifndef _COMPLEX_H
#define _COMPLEX_H

class CComplex
{
private:
    double m_im, m_re;

public:
    CComplex(double = 0, double = 0);            //���캯��
    void set_re(double);                         //����ʵ���ĺ���
    void set_im(double);                         //�����鲿�ĺ���
    void display() const;                        //����Ա����
    friend CComplex &operator++(CComplex &);     //ǰ������������غ���
    friend CComplex operator++(CComplex &, int); //��������������غ���
};
#endif
