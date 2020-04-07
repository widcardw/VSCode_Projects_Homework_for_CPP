#include <iostream>
#include <cassert>
#include <iomanip>
#include "matrix.h"
void Matrix::set(int row, int col)
{
    row_size = row;
    col_size = col;
    if (row <= 0 || col <= 0)
    {
        std::cerr << "Bad Matrix size.\n";
        exit(1);
    }
    m = new int[row * col];
    assert(m);
}
void Matrix::remove()
{
    delete[] m;
}
int Matrix::Row_Size()
{
    return row_size;
}
int Matrix::Col_Size()
{
    return col_size;
}
int &Matrix::elem(int i, int j)
{
    if (i < 0 || row_size <= i || j < 0 || col_size <= j)
    {
        std::cerr << "Matrix index out of range.\n";
        exit(1);
    }
    return m[i * row_size + j];
}
Matrix::~Matrix()
{
    delete[] m;
}
void Matrix::display()
{
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < col_size; ++j)
            std::cout << std::setw(5) << elem(i, j);
        std::cout << '\n';
    }
}
Matrix Matrix::multiply_mm(Matrix &m_1)
{
    if (col_size != m_1.row_size)
    {
        std::cerr << "Bad multiply Matrix with Matrix.\n";
        exit(1);
    }
    Matrix m_2;
    m_2.set(row_size, m_1.col_size);
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < m_1.col_size; ++j)
        {
            m_2.elem(i, j) = 0;
            for (int k = 0; k < col_size; ++k)
                m_2.elem(i, j) += elem(i, k) * m_1.elem(k, j);
        }
    }
    return m_2;
}
Matrix &Matrix::operator=(Matrix &m_1)
{
    if (this != &m_1)
    {
        if (row_size != 0 || col_size != 0)
            delete[] m;
        set(m_1.row_size, m_1.col_size);
        for (int i = 0; i < row_size; ++i)
            for (int j = 0; j < col_size; ++j)
                elem(i, j) = m_1.elem(i, j);
    }
    return *this;
}