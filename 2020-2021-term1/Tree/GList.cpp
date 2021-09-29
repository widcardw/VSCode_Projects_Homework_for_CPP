#include <iostream>
enum GListNodeType{ATOM, LIST};
template <class T>
struct GListNode{
    GListNodeType type;
    union{
        T data;
        GListNode* sublist;
    };
    GListNode<T>*next;
};

template <class T>
class GList{
    private:
    GListNode<T>* head;
};