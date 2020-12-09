// #include <iostreams>
#ifndef _BINODE_H
#define _BINODE_H

struct BiNode
{
    int key;
    BiNode *lchild, *rchild;
};

#endif

#ifndef _BISORTTREE_H
#define _BISORTTREE_H

class BiSortTree
{
    BiNode *root;
    void Insert(BiNode *&ptr, int k);
    BiNode *Search(BiNode *ptr, int k);
    void Delete(BiNode *&ptr, int k);
    void Free(BiNode *ptr);
    void InOrder(BiNode *p);
    void SilentInOrder(BiNode *r, BiNode *p, int &count);

public:
    BiSortTree(int a[], int n);
    ~BiSortTree();
    void Insert(int k);
    BiNode *Search(int k);
    void Delete(int k);
    // bool isBiSortTree();
    void InOrder();
    // void SilentInOrder(BiNode *p, int &count);
};

#endif