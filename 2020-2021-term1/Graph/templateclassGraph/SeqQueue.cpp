#include <iostream>
#include "SeqQueue.h"

template <class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
    front = rear = 0;
}
template <class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
    if ((rear + 1) % MaxSize == front)
    {
        std::cerr << "上溢" << std::endl;
        exit(-1);
    }
    rear = (rear + 1) % MaxSize;
    data[rear] = x;
}
template <class T, int MaxSize>
T SeqQueue<T, MaxSize>::DeQueue()
{
    if (rear == front)
    {
        std::cerr << "下溢" << std::endl;
        exit(-1);
    }
    front = (front + 1) % MaxSize;
    return data[front];
}
template <class T, int MaxSize>
T SeqQueue<T, MaxSize>::GetQueue()
{
    if (rear == front)
    {
        std::cerr << "下溢" << std::endl;
        exit(-1);
    }
    int temp = (front + 1) % MaxSize;
    return data[temp];
}
template <class T, int MaxSize>
bool SeqQueue<T, MaxSize>::Empty()
{
    return rear == front;
}