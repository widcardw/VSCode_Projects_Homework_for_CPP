#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
using namespace std;
//���������ݵ�����
typedef int QDataType;
//��������������һ����ָ�������
typedef struct QNode
{
    struct QNode *_pNext;
    QDataType _data;
} QNode;
//�����ͷ�ڵ��β�ڵ�
typedef struct Queue
{
    QNode *_front;
    QNode *_back;
} Queue;
//�¶���һ���ڵ㲢�Ըýڵ�����ݽ��и�ֵ
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
//����������������г�ʼ��
void QueueInit(Queue *q)
{
    assert(q);
    q->_front = q->_back = NULL;
}
//�¶���ڵ㣬��ֵ����ʹ_backָ������β�ڵ�
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
//��������ɾ�������ͷ�ڵ�
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
//������������һ���ڵ������
QDataType QueueBack(Queue *q)
{
    if (q->_front == NULL)
        return NULL;
    return q->_back->_data;
}
//��������ڵ�ĸ���
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
//�ж������Ƿ�Ϊ��
int QueueEmpty(Queue *q)
{
    if (q->_front == NULL)
        return 1;
    return -1;
}
//ɾ������
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