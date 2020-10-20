#pragma once

#ifndef _MATRIX_
#define _MATRIX_
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

#endif