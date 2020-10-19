#include <iostream>
#include "SeqStack.h"
#include "SeqStack.cpp"
using namespace std;
const int MAXSIZE = 100;
void test();
char Precede(char pre_op, char ch)
{
    char result[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '#'},
        {'>', '>', '>', '>', '#', '>', '>'},
        {'<', '<', '<', '<', '<', '#', '='}};
    int a, b;
    switch (pre_op)
    {
    case '+':
        a = 0;
        break;
    case '-':
        a = 1;
        break;
    case '*':
        a = 2;
        break;
    case '/':
        a = 3;
        break;
    case '(':
        a = 4;
        break;
    case ')':
        a = 5;
        break;
    case '@':
        a = 6;
        break;
    default:
        cerr << "error" << endl;
        exit(1);
    }
    switch (ch)
    {
    case '+':
        b = 0;
        break;
    case '-':
        b = 1;
        break;
    case '*':
        b = 2;
        break;
    case '/':
        b = 3;
        break;
    case '(':
        b = 4;
        break;
    case ')':
        b = 5;
        break;
    case '@':
        b = 6;
        break;
    default:
        cerr << "error" << endl;
        exit(1);
    }
    return result[a][b];
}
double Operate(double a, char pre_op, double b)
{
    switch (pre_op)
    {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        if (a == 0)
        {
            cerr << "除零错误" << endl;
            exit(1);
        }
        return b / a;
    }
}
double Expression_Eval()
{
    SeqStack<char, 100> OPTR;
    SeqStack<double, 100> OPND;
    char pre_op;
    OPTR.Push('@');
    char ch = getchar();
    double a, b;
    double num = 0;
    while (ch != '@' || OPTR.Top() != '@')
    {
        if (ch == ' ')
            ch = getchar();
        num = 0;
        if (ch >= '0' && ch <= '9')
        {
            while (ch >= '0' && ch <= '9')
            {
                num *= 10;
                num += ch - '0';
                ch = getchar();
            }
            if (ch == '.')
            {
                ch = getchar();
                double count = 10;
                while (ch >= '0' && ch <= '9')
                {
                    num += (ch - '0') / count;
                    count *= 10;
                    ch = getchar();
                }
            }
            OPND.Push(num);
        }
        else
        {
            pre_op = OPTR.Top();
            switch (Precede(pre_op, ch))
            {
            case '<':
                OPTR.Push(ch);
                ch = getchar();
                break;
            case '=':
                OPTR.Pop();
                ch = getchar();
                break;
            case '>':
                a = OPND.Pop();
                b = OPND.Pop();
                pre_op = OPTR.Pop();
                OPND.Push(Operate(a, pre_op, b));
                break;
            }
        }
    }
    return OPND.Top();
}
int main()
{
    test();
    return 0;
}
void test()
{
    cout << "Please input formula: " << endl;
    cout << Expression_Eval() << endl;
}
