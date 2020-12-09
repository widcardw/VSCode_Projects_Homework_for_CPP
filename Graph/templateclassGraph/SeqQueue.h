#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H

template <class T, int MaxSize>
class SeqQueue
{
private:
    T data[MaxSize];
    int front, rear;

public:
    SeqQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    bool Empty();
};

#endif