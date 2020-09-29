#include <iostream>
#include "SeqStack.h"
#include "SeqStack.cpp"
using namespace std;
void chooseScene();
void gnrtRandSeqStack();
void inputTargetSeqStack();
int main()
{
    chooseScene();
    return 0;
}
void chooseScene()
{
    while (1)
    {
        system("cls");
        char ch;
        cout << "| 1. 生成随机有序数组      |" << endl;
        cout << "| 2. 键盘输入有序数组      |" << endl;
        cout << "| 5. 退出                  |" << endl;
        cout << "请选择: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            gnrtRandSeqStack();
            break;
        }
        case '2':
        {
            inputTargetSeqStack();
            break;
        }
        default:
            exit(0);
        }
    }
}
void gnrtRandSeqStack()
{
}
void inputTargetSeqStack()
{
}