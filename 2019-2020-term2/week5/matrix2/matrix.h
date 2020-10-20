#pragma once

#ifndef _MATRIX_
#define _MATRIX_
class Matrix
{
private:
    int row_size; //��Ա����: ��������
    int col_size; //��Ա����: ��������
    int *m;       //��Ա����: �����ڵ�Ԫ��

public:
    void set(int, int);              //���������þ���
    void remove();                   //������ɾ������
    int Row_Size();                  //���������ؾ�������
    int Col_Size();                  //���������ؾ�������
    int &elem(int, int);             //���������ض�Ӧ�к��е�Ԫ��
    ~Matrix();                       //��������
    Matrix multiply_mm(Matrix &m_1); //�������������
    void display();                  //�����������ӡ����
    Matrix &operator=(Matrix &m_1);  //������operator=
};

#endif