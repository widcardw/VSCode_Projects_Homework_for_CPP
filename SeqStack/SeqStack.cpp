#include <iostream>
#include "SeqStack.h"
template <class T, int MaxSize>
SeqStack<T, MaxSize>::SeqStack()
{
    top = -1;
}
template <class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x)
{
    if (top >= MaxSize - 1)
    {
        std::cerr << "上溢" << std::endl;
        exit(-1);
    }
    top++;
    data[top] = x;
}
template <class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop()
{
    if (top <= -1)
    {
        std::cerr << "下溢" << std::endl;
        exit(-1);
    }
    T x = data[top];
    top--;
    return x;
}
template <class T, int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
    if (top <= -1)
    {
        std::cerr << "下溢" << std::endl;
        exit(-1);
    }
    return data[top];
}
template <class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty()
{
    if (top <= -1)
        return true;
    return false;
}