#ifndef _COMPLEX_H
#define _COMPLEX_H
class CComplex
{
private:
    double m_im, m_re;

public:
    CComplex(double = 0, double = 0);            //构造函数
    void set_re(double);                         //设置实部的函数
    void set_im(double);                         //设置虚部的函数
    void display() const;                        //常成员函数
    friend CComplex &operator++(CComplex &);     //前自增运算符重载函数
    friend CComplex operator++(CComplex &, int); //后自增运算符重载函数
    friend CComplex operator+(const CComplex &, const CComplex &);
    //加法运算符
    friend std::istream &operator>>(std::istream &, CComplex &);
    //流提取运算符
    friend std::ostream &operator<<(std::ostream &, CComplex &);
    //流插入运算符
};
#endif