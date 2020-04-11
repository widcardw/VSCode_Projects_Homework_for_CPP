/********************************************************************
File name : f0407.cpp
Description : �����������͵������͵�ת��
********************************************************************/
#include <iostream>
using namespace std;
/*class define------------------------*/
class CMoney
{
private:
    int m_yuan, m_jiao, m_fen;

public:
    CMoney(double); //double ����ת��Ϊ CMoney ���ͺ���
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
    cout << m_yuan << "Ԫ" << m_jiao << "��" << m_fen << "��";
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