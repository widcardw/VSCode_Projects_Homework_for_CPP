#include "flipArray.h"
#include <cmath>
#include <iomanip>

template <class T>
mMatrix<T>::mMatrix(int r, T d[][])
{
    this->row = r;
    data = new T[row * (row + 1) / 2];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            data[i * (i + 1) / 2 + j] = d[i][j];
        }
    }
}
template <class T>
mMatrix<T>::mMatrix(const mMatrix<T> &m1)
{
    if (data != NULL)
        delete[] data;
    data = new T[m1.row * (m1.row + 1) / 2];
    for (int i = 0; i < m1.row; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            data[i * (i + 1) / 2 + j] = m1.data[i * (i + 1) / 2 + j];
        }
    }
}
template <class T>
mMatrix<T>::~mMatrix()
{
    delete[] data;
}
template <class T>
void mMatrix<T>::print()
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (j <= i)
                std::cout << std::setw(4) << data[i * (i + 1) / 2 + j];
            else
                std::cout << std::setw(4) << 0;
        }
        std::cout << std::endl;
    }
}