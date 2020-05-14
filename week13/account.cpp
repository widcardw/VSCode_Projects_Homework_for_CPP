/**************
 * account.cpp
 * *****************/
#include <iostream>
#include "account.h"
Account::Account(string acntNo, double balan)
    : acnt_(acntNo), balance_(balan) {}
void Account::display() const
{
    std::cout << "Account:" + acnt_ + " = " << balance_ << "\n";
}
