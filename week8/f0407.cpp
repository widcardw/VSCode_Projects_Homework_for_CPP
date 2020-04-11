/********************************************************************
File name : f0407.cpp
Description : 基本数据类型到类类型的转换
********************************************************************/
#include <iostream>
using namespace std;
/*class define------------------------*/
class CMoney
{
private:
    int m_yuan, m_jiao, m_fen;

public:
    CMoney(double); //double 类型转换为 CMoney 类型函数
    CMoney(int, int, int);
    void display() const;
};
/*member function--------------------*/
CMoney::CMoney(int y, int j, int f)
{
    m_yuan = y;
    m_jiao = j;
    m_fen = f;
}
CMoney::CMoney(double x)
{
    m_yuan = (int)x;
    m_jiao = (int)(x * 10) - m_yuan * 10;
    m_fen = (int)(x * 100) - m_yuan * 100 - m_jiao * 10;
}
void CMoney::display() const
{
    cout << m_yuan << "元" << m_jiao << "角" << m_fen << "分";
}
void print(CMoney money)
{
    money.display();
    cout << endl;
}
int main()
{
    print(2.13);
    return 0;
}
//=========================================