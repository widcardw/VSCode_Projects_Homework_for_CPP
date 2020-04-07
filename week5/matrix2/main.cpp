#include <iostream>
#include <cassert>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;

class Matrix
{
private:
    int row_size; //成员变量: 矩阵行数
    int col_size; //成员变量: 矩阵列数
    int *m;       //成员变量: 矩阵内的元素

public:
    void set(int, int);              //函数：重置矩阵
    void remove();                   //函数：删除矩阵
    int Row_Size();                  //函数：返回矩阵行数
    int Col_Size();                  //函数：返回矩阵列数
    int &elem(int, int);             //函数：返回对应行和列的元素
    ~Matrix();                       //析构函数
    Matrix multiply_mm(Matrix &m_1); //函数：矩阵相乘
    void display();                  //函数：输出打印矩阵
    Matrix &operator=(Matrix &m_1);  //函数：operator=
};
int main()
{
    ifstream fin("in.txt");
    if (!fin)
    {
        cout << "Cannot open the file!" << endl;
        exit(1);
    }
    int x, y, i, j;
    fin >> x >> y;
    Matrix ma;
    ma.set(x, y);
    for (i = 0; i < x; ++i)
        for (j = 0; j < y; ++j)
            fin >> ma.elem(i, j);
    fin >> x >> y;
    Matrix mb;
    mb.set(x, y);
    for (i = 0; i < x; ++i)
        for (j = 0; j < y; ++j)
            fin >> mb.elem(i, j);
    Matrix mc = ma.multiply_mm(mb);
    mc.display();
    system("pause");
    return 0;
}
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
            std::cout << elem(i, j) << "  ";
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