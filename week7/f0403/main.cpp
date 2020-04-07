#include <iostream>
#include "f0403.h"
using namespace std;
int main()
{
    CMyString str("ABCDEFG"); //定义一个字符串对象
    cout << "Orignal string:" << endl;
    str.display();
    str[1] = '5'; //下标运算符作为左值
    cout << "Modified string:" << endl;
    str.display();
    cout << "No.1 char: " << str[1] << endl; //下标运算符作为右值
    CMyString str1(50);
    str1.display();
    str1 = str;
    str1.display();
    return 0;
}
