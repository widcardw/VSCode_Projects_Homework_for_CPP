/*****************
 * accountlist.cpp
 * *******************/
#include <iostream>
#include <cassert>
#include "accountlist.h"
using std::cout;
void AccountList::add(Account &a)
{
    Node *pN = new Node(a);
    assert(pN);
    if (first_)
    {
        pN->next = first_;
        first_->prev = pN;
    }
    first_ = pN;
    size_++;
}
void AccountList::remove(string acntNo)
{
    for (Node *p = first_; p; p = p->next)
    {
        if ((p->acnt).getAcntNo() == acntNo)
        {
            if (p->prev)
                p->prev->next = p->next;
            if (p->next)
                p->next->prev = p->prev;
            if (p == first_)
                first_ = p->next;
            delete p;
            size_--;
            break;
        }
    }
}
Account *AccountList::find(string acntNo) const
{
    for (Node *p = first_; p; p = p->next)
        if ((p->acnt).getAcntNo() == acntNo)
            return &(p->acnt);
    return 0;
}
void AccountList::display() const
{
    std::cout << "There are " << size_ << " accounts.\n";
    for (Node *p = first_; p; p = p->next)
        (p->acnt).display();
}
AccountList::~AccountList()
{
    for (Node *p = first_; p = first_; delete (p))
        first_ = first_->next;
}