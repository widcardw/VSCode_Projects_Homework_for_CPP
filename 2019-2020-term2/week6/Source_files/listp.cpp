#include "listp.h"
#include <stddef.h>
#include <cassert>
using namespace std;
struct listNode
{
    listItemType Item_;
    ptrType Next_;
};

listClass::listClass() : Size_(0), Head_(NULL) {}
listClass::listClass(const listClass &L) : Size_(L.Size_)
{
    if (L.Head_ == NULL)
        Head_ = NULL;
    else
    {
        Head_ = new listNode;
        assert(Head_ != NULL);
        Head_->Item_ = L.Head_->Item_;
        ptrType NewPtr = Head_;
        for (ptrType OriPtr = L.Head_->Next_; OriPtr != NULL; OriPtr = OriPtr->Next_)
        {
            NewPtr->Next_ = new listNode;
            assert(NewPtr->Next_ != NULL);
            NewPtr = NewPtr->Next_;
            NewPtr->Item_ = OriPtr->Item_;
        }
        NewPtr->Next_ = NULL;
    }
}
listClass::~listClass()
{
    bool Success;
    while (!ListIsEmpty())
        ListDelete(1, Success);
}
int listClass::ListLength() const
{
    return Size_;
}
bool listClass::ListIsEmpty() const
{
    return bool(Size_ == 0);
}
ptrType listClass::PtrTo_(int Position) const
{
    if ((Position < 1) || (Position > ListLength()))
        return NULL;
    else
    {
        ptrType Cur = Head_;
        for (int skip = 1; skip < Position; ++skip)
            Cur = Cur->Next_;
        return Cur;
    }
}
void listClass::ListDelete(int Position, bool &Success)
{
    ptrType Cur;
    Success = bool((Position >= 1) && (Position <= Size_));
    if (Success)
    {
        Size_--;
        if (Position == 1)
        {
            Cur = Head_;
            Head_ = Head_->Next_;
        }
        else
        {
            ptrType Prev = PtrTo_(Position - 1);
            Cur = Prev->Next_;
            Prev->Next_ = Cur->Next_;
        }
        delete Cur;
        Cur = NULL;
    }
}
void listClass::ListInsert(int NewPosition, listItemType &NewItem, bool &Success)
{
    int NewLenth = ListLength() + 1;
    Success = bool((NewPosition >= 1) && (NewPosition <= NewLenth));
    if (Success)
    {
        ptrType NewPtr = new listNode;
        Success = bool(NewPtr != NULL);
        if (Success)
        {
            Size_ = NewLenth;
            NewPtr->Item_ = NewItem;
            if (NewPosition == 1)
            {
                NewPtr->Next_ = Head_;
                Head_ = NewPtr;
            }
            else
            {
                ptrType Prev = PtrTo_(NewPosition - 1);
                NewPtr->Next_ = Prev->Next_;
                Prev->Next_ = NewPtr;
            }
        }
    }
}
void listClass::ListRetrieve(int Position, listItemType &DataItem, bool &Success) const
{
    Success = bool((Position >= 1) && (Position <= Size_));
    if (Success)
    {
        ptrType Cur = PtrTo_(Position);
        DataItem = Cur->Item_;
    }
}
void listClass::push(listItemType &DataItem)
{
    bool success;
    ListInsert(1, DataItem, success);
}
void listClass::pop()
{
    bool success;
    ListDelete(1, success);
}
void listClass::top(listItemType &DataItem)
{
    bool success;
    ListRetrieve(1, DataItem, success);
}
void listClass::orderInsert(listItemType NewItem)
{
    bool Success;
    int NewLength = Size_ + 1;
    if (NewLength == 1)
        ListInsert(1, NewItem, Success);
    else
    {
        int i;
        listItemType item;
        for (i = 1; i < NewLength; ++i)
        {
            ListRetrieve(i, item, Success);
            if (NewItem > item)
            {
                ListInsert(i, NewItem, Success);
                break;
            }
        }
        if (i == NewLength)
            ListInsert(i, NewItem, Success);
    }
}