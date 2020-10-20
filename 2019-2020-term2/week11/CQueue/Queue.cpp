//将前面讲过的用链表构建堆栈和队列的题目，用类的继承实现，确保堆栈和队列类中只能使用对堆栈和队列进行的操作。

#include <iostream>
//#include <string>
using namespace std;

typedef int QData;
class Node
{
protected:
public:
    QData item_;
    Node *next;
    Node();
    Node(const QData item);
    void setItem(const QData item);
    QData getItem();
};
Node::Node()
{
    item_ = 0;
    next = NULL;
}
Node::Node(const QData item)
{
    item_ = item;
    next = NULL;
}
void Node::setItem(const QData item)
{
    item_ = item;
}
QData Node::getItem()
{
    return item_;
}

class List : public Node
{
    Node *front_;
    Node *back_;
    int size_;
    Node *PtrTo(int Position) const;

public:
    List();
    ~List();
    void push(QData data);
    void pop();
    int ListLength() const;
    bool ListEmpty() const;
    void traversal() const;
    void ListDelete(int Position, bool &success);
    void ListInsert(int NewPosition, QData &NewItem, bool &success);
};
List::List() : size_(0), front_(NULL), back_(NULL) {}
bool List::ListEmpty() const
{
    return bool(size_ == 0);
}
int List::ListLength() const
{
    return size_;
}
void List::ListDelete(int Position, bool &success)
{
    Node *cur;
    success = bool((Position >= 1) && (Position <= size_));
    if (success)
    {
        size_--;
        if (Position == 1)
        {
            cur = front_;
            front_ = front_->Node::next;
        }
        else
        {
            Node *Prev = PtrTo(Position - 1);
            cur = Prev->Node::next;
            Prev->Node::next = cur->Node::next;
        }
        delete cur;
        cur = NULL;
    }
}
List::~List()
{
    bool success;
    while (!ListEmpty())
        ListDelete(1, success);
}
void List::pop()
{
    bool success;
    ListDelete(1, success);
}
void List::ListInsert(int NewPosition, QData &NewItem, bool &success)
{
    int NewLength = ListLength() + 1;
    success = bool((NewPosition >= 1) && (NewPosition <= NewLength));
    if (success)
    {
        Node *Newptr = new Node;
        success = bool(Newptr != NULL);
        if (success)
        {
            size_ = NewLength;
            Newptr->Node::item_ = NewItem;
            if (NewPosition == 1)
            {
                Newptr->Node::next = front_;
                front_ = Newptr;
            }
            else
            {
                Node *Prev = PtrTo(NewPosition - 1);
                Newptr->Node::next = Prev->Node::next;
                Prev->Node::next = Newptr;
            }
        }
    }
}
void List::push(QData item)
{
    bool success;
    ListInsert(1, item, success);
}
void List::traversal() const
{
    Node *cur = front_;
    while (cur != back_)
    {
        cout << cur->Node::item_ << "  ";
        cur = cur->Node::next;
    }
    cout << endl;
}
Node *List::PtrTo(int Position) const
{
    if ((Position < 1) || (Position > ListLength()))
        return NULL;
    else
    {
        Node *cur = front_;
        for (int skip = 1; skip < Position; ++skip)
            cur = cur->next;
        return cur;
    }
}
int main()
{
    List la;
    la.push(1);
    la.push(2);
    la.push(3);
    la.traversal();
    la.pop();
    la.traversal();
    return 0;
}