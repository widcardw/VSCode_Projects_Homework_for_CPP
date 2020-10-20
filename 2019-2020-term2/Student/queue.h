#ifndef _QUEUE_H
#define _QUEUE_H

typedef Student QData; //��ѧ���ඨ��ΪQData

typedef struct Node //����
{
    QData data_;
    struct Node *pNext_;
} Node;

typedef struct Queue //����ͷ��β
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