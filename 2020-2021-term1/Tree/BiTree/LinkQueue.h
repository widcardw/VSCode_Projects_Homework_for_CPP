#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#include <iostream>
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class LinkQueue
{
    Node<T> *front, *rear;

public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
};
#endif