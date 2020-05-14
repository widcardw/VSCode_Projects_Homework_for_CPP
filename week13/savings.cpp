#include <iostream>
#include "savings.h"
void Savings::display() const
{
    std::cout << "Savings ";
    Account::display();
}
void Savings::withdrawal(double amount)
{
    if (balance_ < amount)
        std::cout << "Insufficient funds withdrawal: " << amount << "\n";
    else
        balance_ -= amount;
}