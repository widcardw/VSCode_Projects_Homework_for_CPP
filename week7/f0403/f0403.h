#ifndef _MYSTRING_H
#define _MYSTRING_H
/*class define----------------------------------------------------*/
class CMyString
{
private:
    unsigned int m_size; //字符串的最大长度-1
    char *mp_data;       //指向存放数据的内存空间
public:
    CMyString(unsigned int = 0);             //构造函数
    CMyString(const char *pstr);             //构造函数
    ~CMyString();                            //析构函数
    char &operator[](int);                   //下标运算符重载函数
    int length() const;                      //返回当前数组中元素个数
    int capacity() const;                    //返回数组的最大元素个数
    void display() const;                    //显示字符串函数
    CMyString &operator=(const CMyString &); //赋值运算符重载
};

#endif
