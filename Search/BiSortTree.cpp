#include <iostream>
#include <iomanip>
#include "BiSortTree.h"

void BiSortTree::Insert(BiNode *&ptr, int k)
{
    if (ptr == NULL)
    {
        ptr = new BiNode;
        ptr->key = k;
        ptr->lchild = ptr->rchild = NULL;
    }
    else
    {
        if (k < ptr->key)
            Insert(ptr->lchild, k);
        else if (k > ptr->key)
            Insert(ptr->rchild, k);
    }
}
void BiSortTree::Insert(int k)
{
    Insert(root, k);
}

BiSortTree::BiSortTree(int a[], int n)
{
    root = NULL;
    for (int i = 0; i < n; ++i)
        Insert(root, a[i]);
}
void BiSortTree::Free(BiNode *ptr)
{
    if (ptr != NULL)
    {
        BiNode *current = ptr;
        BiNode *left = ptr->lchild;
        BiNode *right = ptr->rchild;
        delete current;
        if (left != NULL)
            Free(left);
        if (right != NULL)
            Free(right);
    }
}
BiSortTree::~BiSortTree()
{
    Free(root);
}
void BiSortTree::InOrder(BiNode *p)
{
    if (p == NULL)
        return;
    InOrder(p->lchild);
    std::cout << std::setw(6) << p->key;
    InOrder(p->rchild);
}
void BiSortTree::InOrder()
{
    InOrder(root);
    std::cout << std::endl;
}
BiNode *BiSortTree::Search(BiNode *ptr, int k)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->key == k)
        return ptr;
    else if (ptr->key < k)
        return Search(ptr->rchild, k);
    else
        return Search(ptr->lchild, k);
}
BiNode *BiSortTree::Search(int k)
{
    return Search(root, k);
}
void BiSortTree::Delete(BiNode *&ptr, int k)
{
    if (ptr != NULL)
    {
        BiNode *temp;
        if (k < ptr->key)
            Delete(ptr->lchild, k);
        else if (k > ptr->key)
            Delete(ptr->rchild, k);
        else
        {
            if (ptr->lchild != NULL && ptr->rchild != NULL)
            {
                temp = ptr->lchild;
                while (temp->rchild != NULL)
                    temp = temp->rchild;
                ptr->key = temp->key;
                Delete(ptr->lchild, temp->key);
            }
            else
            {
                temp = ptr;
                if (ptr->lchild == NULL)
                    ptr = ptr->rchild;
                else if (ptr->rchild == NULL)
                    ptr = ptr->lchild;
                delete temp;
            }
        }
    }
}
void BiSortTree::Delete(int k)
{
    Delete(root, k);
}
// void BiSortTree::SilentInOrder(BiNode *r, BiNode *p, int &count)
// {
//     if (r == NULL || r == p)
//     {
//         count++;
//         return;
//     }
//     SilentInOrder(r->lchild, p, count);
//     // count++;
//     std::cout << std::setw(6) << r->key;
//     SilentInOrder(r->rchild, p, count);
//     // count++;
// }
// void BiSortTree::SilentInOrder(BiNode *p, int &count)
// {
//     count = 0;
//     SilentInOrder(root, p, count);
//     // std::cout << std::endl;
// }