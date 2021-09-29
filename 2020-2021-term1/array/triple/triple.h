#include <iostream>
#include <vector>
#include <iomanip>
#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H
template <class T>
struct Triple
{
    int r, c;
    T elem;
};
template <class T>
class SparseMatrix
{
    std::vector<Triple<T>> trilist;
    int rows, cols, num;

public:
    SparseMatrix();
    SparseMatrix(Triple<T> *tlist, int rs, int cs, int n);
    ~SparseMatrix();
    void trans(SparseMatrix &B);
    void trans2(SparseMatrix &B);
    // SparseMatrix &plus(SparseMatrix &B);
    // SparseMatrix &mult(SparseMatrix &B);
    void print();
};
template <class T>
SparseMatrix<T>::SparseMatrix()
{
    trilist.resize(0);
    rows = 0;
    cols = 0;
    num = 0;
}
template <class T>
SparseMatrix<T>::SparseMatrix(Triple<T> *tlist, int rs, int cs, int n)
{
    rows = rs;
    cols = cs;
    num = n;
    Triple<T> temp;
    for (int i = 0; i < num; ++i)
    {
        temp = {(tlist + i)->r, (tlist + i)->c, (tlist + i)->elem};
        trilist.push_back(temp);
    }
}
template <class T>
SparseMatrix<T>::~SparseMatrix()
{
    trilist.clear();
}
template <class T>
void SparseMatrix<T>::print()
{
    int k = 0;
    // for (auto it = trilist.begin(); it != trilist.end(); ++it)
    // {
    //     std::cout << std::setw(4) << it->elem;
    // }
    // std::cout << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (k < num && i == trilist.at(k).r && j == trilist.at(k).c)
            {
                std::cout << std::setw(4) << trilist.at(k).elem;
                k++;
            }
            else
            {
                std::cout << std::setw(4) << 0;
            }
        }
        std::cout << std::endl;
    }
}
template <class T>
void SparseMatrix<T>::trans(SparseMatrix<T> &B)
{
    B.rows = this->rows;
    B.cols = this->cols;
    B.num = this->num;
    B.trilist.resize(num);
    if (num == 0)
        return;
    int q = 0;
    for (int col = 0; col < cols; ++col)
        for (int p = 0; p < num; ++p)
            if (trilist.at(p).c == col)
            {
                B.trilist.at(q).r = trilist.at[p].c;
                B.trilist.at(q).c = trilist.at[p].r;
                B.trilist.at(q).elem = trilist.at[p].elem;
                ++q;
            }
}
template <class T>
void SparseMatrix<T>::trans2(SparseMatrix<T> &B)
{
    int col, t, p, q;
    B.rows = this->cols;
    B.cols = this->rows;
    B.num = this->num;
    B.trilist.resize(num);
    if (num == 0)
        return;
    int *cnum = new int[cols];
    int *cpot = new int[cols];
    for (col = 0; col < cols; ++col)
        cnum[col] = 0;
    for (t = 0; t < num; ++t)
        ++cnum[trilist.at(t).c];
    cpot[0] = 0;
    for (col = 1; col < cols; ++col)
        cpot[col] = cpot[col - 1] + cnum[col - 1];
    for (p = 0; p < num; ++p)
    {
        col = trilist.at(p).c;
        q = cpot[col];
        B.trilist.at(q).r = trilist.at(p).c;
        B.trilist.at(q).c = trilist.at(p).r;
        B.trilist.at(q).elem = trilist.at(p).elem;
        ++cpot[col];
    }
    delete[] cnum;
    delete[] cpot;
}
#endif