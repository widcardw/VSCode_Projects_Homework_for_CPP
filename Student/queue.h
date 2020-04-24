#ifndef _QUEUE_H
#define _QUEUE_H

typedef Student QData; //将学生类定义为QData

typedef struct Node //链表
{
    QData data_;
    struct Node *pNext_;
} Node;

typedef struct Queue //链表头和尾
{
    Node *front_;
    Node *back_;
} Queue;

void QueueInit(Queue *q);
Node *BuyNode(QData data);
void QueuePush(Queue *q, QData data);
void QueuePop(Queue *q);
int QueueSize(Queue *q);
bool QueueEmpty(Queue *q);
void QueueDestroy(Queue *q);
#endif