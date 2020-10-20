#ifndef _CBOOK_H
#define _CBOOK_H
#include <string>
using namespace std;
class CBook
{
protected:
    string Isbn_, bookTitle_, Author_;
    double price_;
    bool isLend_;

public:
    CBook(string = "00000000", string = "noTitle", string = "noAuthor", double = 0, bool = false);
    CBook(const CBook &book);
    ~CBook();
    void show() const;
    void tempLend();
    void backStore();
    void setLend();
    void setBack();
    string rtn_title();
    string rtn_isbn();
    //friend std::ostream operator<<(std::ostream &out, const CBook &book);
    //friend std::istream operator>>(std::istream &in, const CBook &book);
};

class CommonBook : public CBook
{
private:
public:
    CommonBook(string = "00000000", string = "noTitle", string = "noAuthor", double = 0, bool = false);
};

class Magazine : public CBook
{
public:
    Magazine(string = "00000000", string = "noTitle", string = "noAuthor", double = 0, bool = false);
};

class Special : public CBook
{
public:
    Special(string = "00000000", string = "noTitle", string = "noAuthor", double = 0, bool = false);
    void copy() const;
};
#endif