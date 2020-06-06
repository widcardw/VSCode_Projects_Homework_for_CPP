#include <iostream>
#include <string>
//#include "CBook.h"
#include "User.h"
using namespace std;

int main()
{
    CommonBook CB_1 = CommonBook("0102aaaa", "Romeo and Juliet", "Shakespare", 30, false);
    CommonBook CB_2 = CommonBook("0102aaab", "1984", "Gerrge Orwell", 35, false);
    CommonBook CB_3 = CommonBook("0102aaac", "Hamlet", "Shakespare", 31, false);
    Magazine M_1 = Magazine("0x01aaaa", "YiLin01", "ChangChunPublisher", 6, false);
    Magazine M_2 = Magazine("0x01aaab", "YiLin02", "ChangChunPublisher", 6, false);
    Special S_1 = Special("0S01aaaa", "AAA", "noAuthor", 60, false);

    Reader LuRenJia = Reader("LuRenJia", "13010101", 0, 10);
    Librarian LiHua = Librarian("LiHua", "13100105", 0, 10);
    LuRenJia.Borrow(CB_1);
    LuRenJia.Return(CB_1);
    return 0;
}