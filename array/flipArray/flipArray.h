#ifndef _FLIPARRAY_H
#define _FLIPARRAY_H
#include <iostream>

template <class T>
class mMatrix
{
private:
    int row;
    T *data;

public:
    mMatrix(int r, T d[][]);
    mMatrix(const mMatrix &m1);
    ~mMatrix();
    void print();
};
#endif