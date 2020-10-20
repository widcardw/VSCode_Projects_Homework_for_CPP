#include <iostream>
#include <cassert>
#include "course.h"
#include "date.h"
#include "stu.h"
#include "queue.h"
using namespace std;

void QueueInit(Queue *q)
{
    assert(q);
    q->front_ = q->back_ = NULL;
}
Node *BuyNode(QData data)
{
    Node *newnode = new Node;
    if (newnode == NULL)
        assert(0);
    newnode->data_ = data;
    newnode->pNext_ = NULL;
    return newnode;
}
void QueuePush(Queue *q, QData data)
{
    assert(q);
    Node *node = BuyNode(data);
    if (q->front_ == NULL)
        q->front_ = q->back_ = node;
    else
    {
        q->back_->pNext_ = node;
        q->back_ = node;
    }
}
void QueuePop(Queue *q)
{
    assert(q);
    if (q->front_ == NULL)
        return;
    Node *newhead = q->front_;
    if (q->front_->pNext_ == NULL)
        q->front_ = q->back_ = NULL;
    else
    {
        q->front_ = newhead->pNext_;
        free(newhead);
    }
}
int QueueSize(Queue *q)
{
    Node *pCur = q->front_;
    int count = 0;
    while (pCur != NULL)
    {
        pCur = pCur->pNext_;
        count++;
    }
    return count;
}
bool QueueEmpty(Queue *q)
{
    if (q->front_ == NULL)
        return true;
    return false;
}
void QueueDestroy(Queue *q)
{
    assert(q);
    if (q->front_ == NULL)
        return;
    Node *pCur = q->front_;
    while (pCur != NULL)
    {
        q->front_ = pCur->pNext_;
        free(pCur);
        pCur = NULL;
        pCur = q->front_;
    }
    q->front_ = q->back_ = NULL;
}