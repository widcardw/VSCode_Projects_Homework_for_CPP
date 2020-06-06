#include <iostream>
#include <string>
#include "CBook.h"
using namespace std;
CBook::CBook(string isbn, string title, string author, double price, bool islend)
    : Isbn_(isbn), bookTitle_(title), Author_(author), price_(price), isLend_(islend) {}
CBook::CBook(const CBook &book)
{
    Isbn_ = book.Isbn_;
    bookTitle_ = book.bookTitle_;
    Author_ = book.Author_;
    price_ = book.price_;
    isLend_ = book.isLend_;
}
void CBook::show() const
{
    cout << Isbn_ << " " << bookTitle_ << " " << Author_ << " "
         << price_ << " isLend: " << isLend_ << endl;
}
CBook::~CBook() {}
/*std::ostream operator<<(std::ostream &out, const CBook &book)
{
    out << book.Isbn_ << " " << book.bookTitle_ << " "
        << book.Author_ << " " << book.price_ << " isLend: " << book.isLend_;
    return out;
}
std::istream operator>>(std::istream &in, const CBook &book)
{
    in >> book.Isbn_ >> book.bookTitle_ >> book.Author_ >> book.price_ >> book.isLend_;
    return in;
}*/
void CBook::tempLend()
{
    if (isLend_ == false)
        isLend_ = true;
    else
        cout << "This book has been Lended out." << endl;
}
void CBook::backStore()
{
    isLend_ = false;
}
void CBook::setLend()
{
    if (isLend_ == false)
        isLend_ = true;
    else
        cout << "This book has been Lended out." << endl;
}
void CBook::setBack()
{
    isLend_ = false;
}

CommonBook::CommonBook(string isbn, string title, string author, double price, bool islend)
    : CBook(isbn, title, author, price, islend) {}

Magazine::Magazine(string isbn, string title, string author, double price, bool islend)
    : CBook(isbn, title, author, price, islend) {}

Special::Special(string isbn, string title, string author, double price, bool islend)
    : CBook(isbn, title, author, price, islend) {}

void Special::copy() const
{
    cout << "Successfully copied!" << endl;
}
