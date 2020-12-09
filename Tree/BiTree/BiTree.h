#include <iostream>
#include <vector>
#ifndef _BITREE_H
#define _BITREE_H
#include "LinkQueue.cpp"
template <class T>
struct BiNode
{
    T data;
    BiNode<T> *lchild;
    BiNode<T> *rchild;
};

template <class T>
class BiTree
{
private:
    BiNode<T> *root;
    void PreOrder(BiNode<T> *p);
    void InOrder(BiNode<T> *p);
    void PostOrder(BiNode<T> *p);
    BiNode<T> *CreateByPre(std::vector<T> &pre, int &i);
    BiNode<T> *CreateByPreMid(std::vector<T> &pre, std::vector<T> &mid, int ipre, int imid, int n);
    BiNode<T> *DestructByPre(BiNode<T> *p);
    int Count(BiNode<T> *p);
    int Height(BiNode<T> *p);
    BiNode<T> *Search(BiNode<T> *p, T e);
    BiNode<T> *SearchParent(BiNode<T> *p, BiNode<T> *child);
    // void FindPath(BiNode<T> *p, std::stack<T> &Q);

public:
    BiTree() { root = NULL; }
    BiTree(std::vector<T> &pre);
    BiTree(std::vector<T> &pre, std::vector<T> &mid);
    BiTree(BiTree<T> &tree);
    ~BiTree();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
    int Count();
    int Height();
    BiNode<T> *Search(T e);
    BiNode<T> *SearchParent(BiNode<T> *child);
    // void FindPath();
};
#endif