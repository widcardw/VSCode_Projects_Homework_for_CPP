#include "BiTree.h"
#include <iostream>
// #include <stack>
template <class T>
void BiTree<T>::PreOrder(BiNode<T> *p)
{
    if (p == NULL)
        return;
    std::cout << p->data << std::endl;
    PreOrder(p->lchild);
    PreOrder(p->rchild);
}
template <class T>
void BiTree<T>::PreOrder()
{
    PreOrder(root);
}
template <class T>
void BiTree<T>::InOrder(BiNode<T> *p)
{
    if (p == NULL)
        return;
    InOrder(p->lchild);
    std::cout << p->data << std::endl;
    InOrder(p->rchild);
}
template <class T>
void BiTree<T>::InOrder()
{
    InOrder(root);
}
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *p)
{
    if (p == NULL)
        return;
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    std::cout << p->data << std::endl;
}
template <class T>
void BiTree<T>::PostOrder()
{
    PostOrder(root);
}
template <class T>
void BiTree<T>::LevelOrder()
{
    if (root == NULL)
        return;
    LinkQueue<BiNode<T> *> Q;
    Q.EnQueue(root);
    while (!Q.Empty())
    {
        BiNode<T> *p = Q.DeQueue();
        std::cout << p->data << std::endl;
        if (p->lchild != NULL)
            Q.EnQueue(p->lchild);
        if (p->rchild != NULL)
            Q.EnQueue(p->rchild);
    }
}
template <class T>
BiNode<T> *BiTree<T>::CreateByPre(std::vector<T> &pre, int &i)
{
    T e = pre.at(i);
    ++i;
    if (e == '*')
        return NULL;
    BiNode<T> *p = new BiNode<T>;
    p->data = e;
    p->lchild = CreateByPre(pre, i);
    p->rchild = CreateByPre(pre, i);
    return p;
}
template <class T>
BiTree<T>::BiTree(std::vector<T> &pre)
{
    int i = 0;
    CreateByPre(pre, i);
}
template <class T>
BiNode<T> *BiTree<T>::CreateByPreMid(std::vector<T> &pre, std::vector<T> &mid, int ipre, int imid, int n)
{
    if (n == 0)
        return NULL;
    int i;
    BiNode<T> *p = new BiNode<T>;
    p->data = pre.at(ipre);
    for (i = 0; i < n; ++i)
        if (pre.at(ipre) == mid.at(imid + i))
            break;
    p->lchild = CreateByPreMid(pre, mid, ipre + 1, imid, i);
    p->rchild = CreateByPreMid(pre, mid, ipre + i + 1, imid + i + 1, n - i - 1);
    return p;
}
template <class T>
BiTree<T>::BiTree(std::vector<T> &pre, std::vector<T> &mid)
{
    int n = pre.size();
    root = CreateByPreMid(pre, mid, 0, 0, n);
}
template <class T>
BiNode<T> *BiTree<T>::DestructByPre(BiNode<T> *p)
{
    if (p != NULL)
    {
        BiNode<T> *current = p;
        BiNode<T> *left = p->lchild;
        BiNode<T> *right = p->rchild;
        delete current;
        if (left)
            DestructByPre(left);
        if (right)
            DestructByPre(right);
    }
}
template <class T>
BiTree<T>::~BiTree()
{
    DestructByPre(root);
}
template <class T>
int BiTree<T>::Count(BiNode<T> *p)
{
    if (p == NULL)
        return 0;
    int left = Count(p->lchild);
    int right = Count(p->rchild);
    return 1 + left + right;
}
template <class T>
int BiTree<T>::Count()
{
    return Count(root);
}
template <class T>
int BiTree<T>::Height(BiNode<T> *p)
{
    if (p == NULL)
        return 0;
    int left = Height(p->lchild);
    int right = Height(p->rchild);
    if (left > right)
        return left + 1;
    return right + 1;
}
template <class T>
int BiTree<T>::Height()
{
    return Height(root);
}
template <class T>
BiNode<T> *BiTree<T>::SearchParent(BiNode<T> *p, BiNode<T> *child)
{
    if (p == NULL || child == NULL)
        return NULL;
    if (p->lchild == child || p->rchild == child)
        return p;
    BiNode<T> *q = SearchParent(p->lchild, child);
    if (q != NULL)
        return q;
    return SearchParent(p->rchild, child);
}
template <class T>
BiNode<T> *BiTree<T>::SearchParent(BiNode<T> *child)
{
    return SearchParent(root, child);
}
template <class T>
BiNode<T> *BiTree<T>::Search(BiNode<T> *p, T e)
{
    if (p == NULL)
        return NULL;
    if (p->data == e)
        return p;
    BiNode<T> *q = Search(p->lchild, e);
    if (q != NULL)
        return q;
    return Search(p->rchild, e);
}
template <class T>
BiNode<T> *BiTree<T>::Search(T e)
{
    return Search(root, e);
}
// template <class T>
// void BiTree<T>::FindPath(BiNode<T> *p, std::stack<T> &Q)
// {
//     Q.push(p->data);
//     if (p->lchild == NULL && p->rchild == NULL)
//     {
//         std::cout << Q.top();
//         Q.pop();
//     }
//     else
//     {
//         FindPath(p->lchild, Q);
//         FindPath(p->rchild, Q);
//         Q.pop();
//     }
// }
// template <class T>
// void BiTree<T>::FindPath()
// {
//     std::stack<T> Q;
//     this->FindPath(root, Q);
// }