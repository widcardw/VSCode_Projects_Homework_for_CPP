#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
using namespace std;
//链表内数据的类型
typedef int QDataType;
//定义链表，包含下一个的指针和数据
typedef struct QNode
{
    struct QNode *_pNext;
    QDataType _data;
} QNode;
//链表的头节点和尾节点
typedef struct Queue
{
    QNode *_front;
    QNode *_back;
} Queue;
//新定义一个节点并对该节点的数据进行赋值
QNode *BuyNode(QDataType data)
{
    QNode *newnode = new QNode;
    if (newnode == NULL)
    {
        assert(0);
    }
    newnode->_data = data;
    newnode->_pNext = NULL;
    return newnode;
}
//传入链表，对链表进行初始化
void QueueInit(Queue *q)
{
    assert(q);
    q->_front = q->_back = NULL;
}
//新定义节点，赋值，并使_back指向链表尾节点
void QueuePush(Queue *q, QDataType data)
{
    assert(q);
    QNode *node = BuyNode(data);
    if (q->_front == NULL)
    {
        q->_front = q->_back = node;
    }
    else
    {
        q->_back->_pNext = node;
        q->_back = node;
    }
}
//传入链表，删除链表的头节点
void QueuePop(Queue *q)
{
    assert(q);
    if (q->_front == NULL)
        return;
    QNode *newhead = q->_front;
    if (q->_front->_pNext == NULL)
    {
        q->_front = q->_back = NULL;
    }
    else
    {
        q->_front = newhead->_pNext;
        free(newhead);
    }
}
//返回链表的最后一个节点的数据
QDataType QueueBack(Queue *q)
{
    if (q->_front == NULL)
        return NULL;
    return q->_back->_data;
}
//计算链表节点的个数
int QueueSize(Queue *q)
{
    QNode *pCur = q->_front;
    int count = 0;
    while (pCur != NULL)
    {
        pCur = pCur->_pNext;
        count++;
    }
    return count;
}
//判断链表是否为空
int QueueEmpty(Queue *q)
{
    if (q->_front == NULL)
        return 1;
    return -1;
}
//删除链表
void QueueDestroy(Queue *q)
{
    assert(q);
    if (q->_front == NULL)
        return;
    QNode *pCur = q->_front;
    while (pCur != NULL)
    {
        q->_front = pCur->_pNext;
        free(pCur);
        pCur = NULL;
        pCur = q->_front;
    }
    q->_front = q->_back = NULL;
}
void QueueTest()
{
    Queue s;
    QueueInit(&s);
    cout << "QueueEmpty: " << QueueEmpty(&s) << "\tsize=" << QueueSize(&s) << endl;
    QueuePush(&s, 1);
    QueuePush(&s, 2);
    QueuePush(&s, 3);
    QueuePush(&s, 4);
    cout << "QueueEmpty: " << QueueEmpty(&s) << "\tsize=" << QueueSize(&s) << endl;
    QueuePop(&s);
    QueuePop(&s);
    cout << "QueueEmpty: " << QueueEmpty(&s) << "\tsize=" << QueueSize(&s) << endl;
    QueueDestroy(&s);
    cout << "QueueEmpty: " << QueueEmpty(&s) << "\tsize=" << QueueSize(&s) << endl;
}
int main()
{
    QueueTest();
    system("pause");
    return 0;
}