/******************
 * accountlist.h
 * *****************/
#ifndef _ACCOUNTLIST_H
#define _ACCOUNTLIST_H
#include "account.h"
class Node
{
public:
    Account &acnt;
    Node *next, *prev;
    Node(Account &a) : acnt(a), next(0), prev(0) {}
    bool operator==(const Node &n) const
    {
        return acnt == n.acnt;
    }
};
class AccountList
{
    int size_;
    Node *first_;

public:
    AccountList() : first_(0), size_(0) {}
    Node *getFirst() const
    {
        return first_;
    }
    int getSize() const
    {
        return size_;
    }
    void add(Account &a);
    void remove(string acntNo);
    Account *find(string acntNo) const;
    bool isEmpty() const
    {
        return !size_;
    }
    void display() const;
    ~AccountList();
};
#endif