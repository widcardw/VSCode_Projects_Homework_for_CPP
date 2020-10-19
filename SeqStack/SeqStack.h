//#program once
#ifndef _SEQSTACK_H
#define _SEQSTACK_H
template <class T, int MaxSize>
class SeqStack
{
    T data[MaxSize];
    int top;

public:
    SeqStack();
    void Push(T x);
    T Pop();
    T Top();
    bool Empty();
};
#endif