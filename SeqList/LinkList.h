#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class LinkList;
template <class T>
void Merge(LinkList<T> &l1, LinkList<T> &l2);

template <class T>
class LinkList
{
    Node<T> *head;

public:
    LinkList();
    LinkList(T a[], int n);
    ~LinkList();
    int ListLength();
    T Get(int pos);
    int Locate(T item);
    void PrintLinkList();
    void Insert(int i, T item);
    T Delete(int i);
    void Invert();
    void Sort();
    friend void Merge<>(LinkList<T> &l1, LinkList<T> &l2);
};
#endif