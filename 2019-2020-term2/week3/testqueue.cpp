#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
using namespace std;
//������������
typedef int QDataInt;
typedef double QDataDou;
//��������
typedef struct QNodeI
{
    struct QNodeI *_pNext;
    QDataInt _data;
} QNodeI;
typedef struct QNodeD
{
    struct QNodeD *_pNext;
    QDataDou _data;
} QNodeD;
//�����࣬������data������Ϊdouble����
class QUEUE
{
private:
    QNodeD *_front; //ָ��ͷ�ڵ�
    QNodeD *_back;  //ָ��β�ڵ�

public:
    QUEUE(){};
    //��QUEUE��һϵ�к���������
    void QueueInit() //��ʼ��
    {
        _front = NULL;
        _back = NULL;
    }
    void QueuePush(QDataDou data); //�����½ڵ�
    void QueuePop();               //ɾ��ͷ�ڵ�
    QDataDou QueueFront();         //����ͷ�ڵ�����
    QDataDou QueueBack();          //����β�ڵ�����
    int QueueSize();               //��������ڵ����
    int QueueEmpty();              //�ж������Ƿ�Ϊ��
    //void QueueCopy();              //��������
    void QueueDestroy(); //ɾ������
    ~QUEUE()             //��������
    {
        if (_front == NULL)
            return;
        QNodeD *pCur = _front;
        while (pCur != NULL)
        {
            _front = pCur->_pNext;
            delete pCur;
            pCur = _front;
        }
        _front = _back = NULL;
        cout << "QUEUE destruct complete!" << endl;
    }
};

//����������������data������Ϊint����
typedef struct Queue
{
    QNodeI *_front; //ָ��ͷ�ڵ�
    QNodeI *_back;  //ָ��β�ڵ�
} Queue;
//��Queue��һϵ�к���������
void QueueInit(Queue *q);                //��ʼ��
void QueuePush(Queue *q, QDataInt data); //�����½ڵ�
void QueuePop(Queue *q);                 //ɾ��ͷ�ڵ�
QDataInt QueueFront(Queue *q);           //����ͷ�ڵ�����
QDataInt QueueBack(Queue *q);            //����β�ڵ�����
int QueueSize(Queue *q);                 //��������ڵ����
int QueueEmpty(Queue *q);                //�ж������Ƿ�Ϊ��
void QueueDestroy(Queue *q);             //ɾ������
QNodeI *BuyNode(QDataInt data)
{
    QNodeI *newnode = new QNodeI;
    if (newnode == NULL)
    {
        assert(0);
    }
    newnode->_data = data;
    newnode->_pNext = NULL;
    return newnode;
}
void QueueInit(Queue *q)
{
    assert(q);
    q->_front = q->_back = NULL;
}
void QueuePush(Queue *q, QDataInt data)
{
    assert(q);
    QNodeI *node = BuyNode(data);
    if (q->_front == NULL)
        q->_front = q->_back = node;
    else
    {
        q->_back->_pNext = node;
        q->_back = node;
    }
}
void QUEUE::QueuePush(QDataDou data)
{
    QNodeD *newnode = new QNodeD;
    assert(newnode);
    newnode->_data = data;
    newnode->_pNext = NULL;
    if (_front == NULL)
        _front = _back = newnode;
    else
    {
        _back->_pNext = newnode;
        _back = newnode;
    }
}
void QueuePop(Queue *q)
{
    assert(q);
    if (q->_front == NULL)
        return;
    QNodeI *newhead = q->_front;
    if (q->_front->_pNext == NULL)
        q->_front = q->_back = NULL;
    else
        q->_front = newhead->_pNext;
    free(newhead);
}
void QUEUE::QueuePop()
{
    if (_front == NULL)
        return;
    QNodeD *newhead = _front;
    if (_front->_pNext == NULL)
        _front = _back = NULL;
    else
        _front = newhead->_pNext;
    delete newhead;
}
QDataInt QueueFront(Queue *q)
{
    if (q->_front == NULL)
        return NULL;
    return q->_front->_data;
}
QDataDou QUEUE::QueueFront()
{
    if (_front == NULL)
        return NULL;
    return _front->_data;
}
QDataInt QueueBack(Queue *q)
{
    if (q->_front == NULL)
        return NULL;
    return q->_back->_data;
}
QDataDou QUEUE::QueueBack()
{
    if (_front == NULL)
        return NULL;
    return _back->_data;
}
int QueueSize(Queue *q)
{
    assert(q);
    QNodeI *pCur = q->_front;
    int count = 0;
    while (pCur != NULL)
    {
        pCur = pCur->_pNext;
        count++;
    }
    return count;
}
int QUEUE::QueueSize()
{
    QNodeD *pCur = _front;
    int count = 0;
    while (pCur != NULL)
    {
        pCur = pCur->_pNext;
        count++;
    }
    return count;
}
int QueueEmpty(Queue *q)
{
    assert(q);
    if (q->_front == NULL)
        return 1;
    return -1;
}
int QUEUE::QueueEmpty()
{
    if (_front == NULL)
        return 1;
    return -1;
}
void QueueDestroy(Queue *q)
{
    assert(q);
    if (q->_front == NULL)
        return;
    QNodeI *pCur = q->_front;
    while (pCur != NULL)
    {
        q->_front = pCur->_pNext;
        free(pCur);
        pCur = NULL;
        pCur = q->_front;
    }
    q->_front = q->_back = NULL;
}
void QUEUE::QueueDestroy()
{
    if (_front == NULL)
        return;
    QNodeD *pCur = _front;
    while (pCur != NULL)
    {
        _front = pCur->_pNext;
        delete pCur;
        pCur = _front;
    }
    _front = _back = NULL;
}
//����
void TestQueue()
{
    Queue s;
    QueueInit(&s);
    cout << "QueueSize=" << QueueSize(&s) << "\tQueueEmpty=" << QueueEmpty(&s) << endl;
    QueuePush(&s, 1);
    QueuePush(&s, 2);
    QueuePush(&s, 3);
    QueuePush(&s, 4);
    cout << "QueueSize=" << QueueSize(&s) << "\tQueueBack=" << QueueBack(&s) << endl;
    QueuePop(&s);
    QueuePop(&s);
    cout << "QueueSize=" << QueueSize(&s) << "\tQueueFront=" << QueueFront(&s) << endl;
    QueueDestroy(&s);
    cout << "QueueSize=" << QueueSize(&s) << "\tQueueEmpty=" << QueueEmpty(&s) << endl;
}
void TESTQUEUE()
{
    QUEUE s;
    s.QueueInit();
    cout << "QUEUESize=" << s.QueueSize() << "\tQUEUEEmpty=" << s.QueueEmpty() << endl;
    s.QueuePush(1.1);
    s.QueuePush(2.2);
    s.QueuePush(3.3);
    s.QueuePush(4.4);
    cout << "QUEUESize=" << s.QueueSize() << "\tQUEUEBack=" << s.QueueBack() << endl;
    s.QueuePop();
    s.QueuePop();
    cout << "QUEUESize=" << s.QueueSize() << "\tQUEUEFront=" << s.QueueFront() << endl;
}
int main()
{
    TestQueue();
    TESTQUEUE();
    //system("pause");
    return 0;
}