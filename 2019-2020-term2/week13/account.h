/************************
 * account.h
***************************/

#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <string>
using std::string;
class Account
{
protected:
    string acnt_;
    double balance_;

public:
    Account(string acntNo, double balan = 0.0);
    virtual void display() const;
    double getBalan() const
    {
        return balance_;
    }
    void deposit(double amount)
    {
        balance_ += amount;
    }
    bool operator==(const Account &a)
    {
        return acnt_ == a.acnt_;
    }
    string getAcntNo()
    {
        return acnt_;
    }
    virtual void withdrawal(double amount) = 0;
};

#endif