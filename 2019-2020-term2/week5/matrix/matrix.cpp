#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Matrix;
class Vector;

class Matrix
{
private:
    int *m;
    int row_size, column_size;
    friend Vector multiply_mv_f(Matrix &m, Vector &v);

public:
    void set(int, int); //设定矩阵大小
    void remove()       //删除矩阵
    {
        delete[] m;
    }
    int RowSize();       //返回矩阵行数
    int ColumnSize();    //返回矩阵列数
    int &elem(int, int); //返回矩阵对应坐标的元素值
    ~Matrix()            //析构函数
    {
        delete[] m;
    }
    Vector multiply_mv(Vector &v);   //矩阵乘向量
    Matrix multiply_mm(Matrix &m_1); //矩阵相乘
    void display();                  //打印矩阵
};
int Matrix::RowSize()
{
    return row_size;
}
int Matrix::ColumnSize()
{
    return column_size;
}
void Matrix::set(int i, int j)
{
    row_size = i;
    column_size = j;
    if (i <= 0 || j <= 0)
    {
        cerr << "Bad Matrix size.\n";
        exit(1);
    }
    m = new int[i * j];
    assert(m);
}
int &Matrix::elem(int i, int j)
{
    if (i < 0 || row_size <= i || j < 0 || column_size <= j)
    {
        cerr << "Matrix index out of range.\n";
        exit(1);
    }
    return m[i * row_size + j];
}
Matrix Matrix::multiply_mm(Matrix &m_1)
{
    if (column_size != m_1.row_size)
    {
        cerr << "Bad multiply Matrix with Matrix.\n";
        exit(1);
    }
    Matrix m_2;
    m_2.set(row_size, m_1.column_size);
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < m_1.column_size; ++j)
        {
            m_2.elem(i, j) = 0;
            for (int k = 0; k < row_size; ++k)
                m_2.elem(i, j) += elem(i, k) * m_1.elem(k, j);
        }
    }
    return m_2;
}
void Matrix::display()
{
    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < column_size; ++j)
            cout << setw(4) << elem(i, j);
        cout << "\n";
    }
}

class Vector
{
private:
    int *v_arr;
    int v_size;

public:
    friend Vector multiply_mv_f(Matrix &m, Vector &v);
    friend Matrix;
    void remove()
    {
        delete[] v_arr;
    }
    int size()
    {
        return v_size;
    }
    friend Vector Matrix::multiply_mv(Vector &v);
    void set(int);
    void display();
    int &operator[](int);
    int &elem(int);
    Vector()
    {
        v_size = 0;
        v_arr = NULL;
    }
    ~Vector()
    {
        if (v_size != 0)
            delete[] v_arr;
    }
    Vector &operator=(Vector &v_new)
    {
        if (this != &v_new)
        {
            if (v_size != 0)
                delete[] v_arr;
            set(v_new.v_size);
            //this->v_size = v_size;
            for (int i = 0; i < v_size; ++i)
                v_arr[i] = v_new.v_arr[i];
        }
        return *this;
    }
    Vector(Vector &v_new)
    {
        set(v_new.v_size);
        for (int i = 0; i < v_size; ++i)
            v_arr[i] = v_new.v_arr[i];
    }
};
void Vector::set(int s)
{
    v_size = s;
    if (s <= 0)
    {
        cerr << "Bad Vector size.\n";
        exit(0);
    }
    v_arr = new int[s];
    assert(v_arr);
}
int &Vector::operator[](int i)
{
    if (i < 0 || i >= v_size)
    {
        cerr << "Vector index out of range.\n";
        exit(1);
    }
    return v_arr[i];
}
int &Vector::elem(int i)
{
    if (i < 0 || i >= v_size)
    {
        cerr << "Vector index out of range.\n";
        exit(1);
    }
    return v_arr[i];
}
void Vector::display()
{
    for (int i = 0; i < v_size; ++i)
        cout << setw(5) << v_arr[i];
    cout << "\n";
}
Vector multiply(Matrix &m, Vector &v)
{
    if (m.ColumnSize() != v.size())
    {
        cerr << "Bad multiply Matrix with Vector.\n";
        exit(1);
    }
    Vector r;
    r.set(m.RowSize());
    for (int i = 0; i < m.RowSize(); ++i)
    {
        r[i] = 0;
        for (int j = 0; j < m.ColumnSize(); ++j)
            r[i] += m.elem(i, j) * v[j];
    }
    return r;
}

Vector Matrix::multiply_mv(Vector &v)
{
    if (column_size != v.size())
    {
        cerr << "Bad multiply Matrix with Vector.\n";
        exit(1);
    }
    Vector r;
    r.set(row_size);
    for (int i = 0; i < row_size; ++i)
    {
        r.v_arr[i] = 0;
        for (int j = 0; j < column_size; ++j)
            r.v_arr[i] += m[i * column_size + j] * v.v_arr[j];
    }
    return r;
}
int main()
{
    ifstream in("in.txt");
    if (!in)
    {
        cout << "Cannot open the file!" << endl;
        exit(1);
    }
    int x, y;
    in >> x >> y;
    Matrix ma;
    ma.set(x, y);
    int i, j;
    for (i = 0; i < x; ++i)
        for (j = 0; j < y; ++j)
            in >> ma.elem(i, j);
    in >> x;
    Vector ve;
    ve.set(x);
    for (i = 0; i < x; ++i)
        in >> ve[i];
    Vector vx;
    double t_start = clock();
    for (i = 0; i < 10; ++i)
        vx = ma.multiply_mv(ve);
    vx.display();
    cout << clock() - t_start << endl;
    in.close();
    return 0;
}