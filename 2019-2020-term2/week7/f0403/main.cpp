#include <iostream>
#include "f0403.h"
using namespace std;
int main()
{
    CMyString str("ABCDEFG"); //����һ���ַ�������
    cout << "Orignal string:" << endl;
    str.display();
    str[1] = '5'; //�±��������Ϊ��ֵ
    cout << "Modified string:" << endl;
    str.display();
    cout << "No.1 char: " << str[1] << endl; //�±��������Ϊ��ֵ
    CMyString str1(50);
    str1.display();
    str1 = str;
    str1.display();
    return 0;
}
