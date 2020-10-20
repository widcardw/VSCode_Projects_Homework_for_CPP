/****************
 * linked_list.cpp
 * main function
 * ******************/
#include <iostream>
using namespace std;
#include "savings.h"
#include "checking.h"
#include "accountlist.h"
int main()
{
    Savings s1("101", 2000), s2("102", 4000);
    Checking c1("201"), c2("312", 10000);
    AccountList a;
    a.add(s1);
    a.add(s2);
    a.add(c1);
    a.add(c2);
    Account *p;
    if (p = a.find("101"))
        p->deposit(100);
    if (p = a.find("201"))
        p->deposit(2000);
    if (p = a.find("102"))
        p->withdrawal(2500);
    if (p = a.find("312"))
        p->withdrawal(2950);
    a.display();
    return 0;
}