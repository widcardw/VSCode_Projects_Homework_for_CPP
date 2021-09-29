#include <iostream>
#include <iomanip>
#include "LinkList.h"
template <class T>
LinkList<T>::LinkList()
{
    head = new Node<T>;
    head->next = NULL;
}
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
    head = new Node<T>;
    Node<T> *rear = head;
    for (int i = 0; i < n; ++i)
    {
        Node<T> *s = new Node<T>;
        s->data = a[i];
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
}
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *p = head, *q = head;
    while (p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
template <class T>
int LinkList<T>::ListLength()
{
    int num = 0;
    Node<T> *p = head;
    while (p)
    {
        p = p->next;
        num++;
    }
    return num;
}
template <class T>
T LinkList<T>::Get(int pos)
{
    Node<T> *p = head->next;
    int j = 0;
    while (p && j < pos)
    {
        p = p->next;
        ++j;
    }
    if (!p || j >= pos)
    {
        std::cerr << "查找位置非法!" << std::endl;
        exit(1);
    }
    return p->data;
}
template <class T>
int LinkList<T>::Locate(T item)
{
    Node<T> *p = head->next;
    int j = 0;
    while (p && p->data != item)
    {
        p = p->next;
        ++j;
    }
    if (p)
        return j;
    return -1;
}
template <class T>
void LinkList<T>::PrintLinkList()
{
    Node<T> *p = head->next;
    int i = 0;
    while (p)
    {
        std::cout << std::setw(4) << p->data;
        ++i;
        p = p->next;
        if (i % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
template <class T>
void LinkList<T>::Insert(int i, T item)
{
    Node<T> *p = head;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p)
    {
        std::cerr << "插入位置非法" << std::endl;
        exit(1);
    }
    Node<T> *s = new Node<T>;
    s->data = item;
    s->next = p->next;
    p->next = s;
}
template <class T>
T LinkList<T>::Delete(int i)
{
    Node<T> *p = head;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || !p->next)
    {
        std::cerr << "删除位置非法" << std::endl;
        exit(1);
    }
    Node<T> *q = p->next;
    T x = q->data;
    p->next = q->next;
    delete q;
    return x;
}
template <class T>
void LinkList<T>::Invert()
{
    Node<T> *p = head->next, *q;
    head->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}
template <class T>
void LinkList<T>::Sort()
{
    if (head->next == NULL || head->next->next == NULL)
        return;
    Node<T> *p, *prep, *temp, *ptail = NULL;
    while (head->next != ptail)
    {
        prep = head;
        p = head->next;
        while (p->next != ptail)
        {
            if (p->data > p->next->data)
            {
                temp = p->next;
                prep->next = p->next;
                p->next = p->next->next;
                prep->next->next = p;
                p = temp;
            }
            p = p->next;
            prep = prep->next;
        }
        ptail = p;
    }
    // r->next->next = NULL;
    // while (p != NULL)
    // {
    //     q = p;
    //     p = p->next;
    //     r = head;
    //     while (q->data < r->next->data)
    //         r = r->next;
    //     if (r == head)
    //     {
    //         q->next = r->next;
    //         r->next = q;
    //     }
    //     else
    //     {
    //         q->next = r->next->next;
    //         r->next->next = q;
    //     }
    // }
}
template <class T>
void Merge(LinkList<T> &l1, LinkList<T> &l2)
{
    Node<T> *p1 = l1.head->next, *p2 = l2.head->next, *p3 = l1.head;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    if (p1 != NULL)
        p3->next = p1;
    if (p2 != NULL)
        p3->next = p2;
    delete l2.head;
    l2.head = NULL;
}