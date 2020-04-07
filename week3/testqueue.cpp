#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
using namespace std;
//定义数据类型
typedef int QDataInt;
typedef double QDataDou;
//定义链表
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
//定义类，该类中data的数据为double类型
class QUEUE
{
private:
    QNodeD *_front; //指向头节点
    QNodeD *_back;  //指向尾节点

public:
    QUEUE(){};
    //对QUEUE类一系列函数的声明
    void QueueInit() //初始化
    {
        _front = NULL;
        _back = NULL;
    }
    void QueuePush(QDataDou data); //创建新节点
    void QueuePop();               //删除头节点
    QDataDou QueueFront();         //返回头节点数据
    QDataDou QueueBack();          //返回尾节点数据
    int QueueSize();               //返回链表节点个数
    int QueueEmpty();              //判断链表是否为空
    //void QueueCopy();              //复制链表
    void QueueDestroy(); //删除链表
    ~QUEUE()             //链表析构
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

//定义链表，该链表中data的数据为int类型
typedef struct Queue
{
    QNodeI *_front; //指向头节点
    QNodeI *_back;  //指向尾节点
} Queue;
//对Queue的一系列函数的声明
void QueueInit(Queue *q);                //初始化
void QueuePush(Queue *q, QDataInt data); //创建新节点
void QueuePop(Queue *q);                 //删除头节点
QDataInt QueueFront(Queue *q);           //返回头节点数据
QDataInt QueueBack(Queue *q);            //返回尾节点数据
int QueueSize(Queue *q);                 //返回链表节点个数
int QueueEmpty(Queue *q);                //判断链表是否为空
void QueueDestroy(Queue *q);             //删除链表
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
//测试
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