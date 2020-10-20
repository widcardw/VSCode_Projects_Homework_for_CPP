#include <iostream>
#include <string>
#include "User.h"
#include "CBook.h"
using namespace std;

User::User(string name, string id, int day, int credit)
    : name_(name), id_(id), period_(day), credit_(credit) {}
User::User(const User &one)
{
    name_ = one.name_;
    id_ = one.id_;
    period_ = one.period_;
    credit_ = one.credit_;
}
void User::Borrow(CommonBook &book)
{
    if (credit_ > 0)
    {
        book.setLend();
        period_ = 1;
        cout << id_ << ' ' << name_ << " borrowed " << book.rtn_isbn() << ' ' << book.rtn_title() << endl;
    }
    else
    {
        cout << "Your credit is too low! You are not allowed to borrow books! " << endl;
    }
}
void User::Return(CommonBook &book)
{
    book.setBack();
    if (period_ > 90)
    {
        cout << "You have missed the deadline of returning books!" << endl;
        credit_--;
        cout << "Your credit is " << credit_ << endl;
        return;
    }
    cout << id_ << ' ' << name_ << " returned " << book.rtn_isbn() << ' ' << book.rtn_title() << endl;
}

Reader::Reader(string name, string id, int day, int credit)
    : User(name, id, day, credit) {}

Librarian::Librarian(string name, string id, int day, int credit)
    : User(name, id, day, credit) {}
CBook Librarian::AddBook(CBook &book)
{
    CBook one(book);
    return one;
}
void Librarian::RemoveBook(CBook &book)
{
}