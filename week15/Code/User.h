#ifndef _USER_H
#define _USER_H
#include <string>
#include "CBook.h"
using namespace std;
class User
{
protected:
    string name_, id_;
    int period_;
    int credit_;

public:
    User(string = "noName", string = "noId", int = 0, int = 0);
    User(const User &one);
    void Borrow(CommonBook &);
    void Return(CommonBook &);
};
class Reader : public User
{
private:
public:
    Reader(string = "noName", string = "noId", int = 0, int = 0);
};
class Librarian : public User
{
private:
public:
    Librarian(string = "noName", string = "noId", int = 0, int = 0);
    CBook AddBook(CBook &book);
    void RemoveBook(CBook &book);
};
#endif