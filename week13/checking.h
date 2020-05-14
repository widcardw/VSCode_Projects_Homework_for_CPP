/**************
 * checking.h
 * **************/
#ifndef _CHECKING_H
#define _CHECKING_H
#include "account.h"
enum REMIT
{
    remitByPost,
    remitByCable,
    other
}; //ÐÅ»ã, µç»ã, ÎÞ
class Checking : public Account
{
    REMIT remittance;

public:
    Checking(string acntNo, double balan = 0.0);
    void withdrawal(double amount);
    void display() const;
    void setRemit(REMIT re)
    {
        remittance = re;
    }
};
#endif