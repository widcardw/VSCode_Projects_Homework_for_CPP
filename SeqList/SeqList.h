#ifndef _SEQLIST_H
#define _SEQLIST_H
#include <iostream>
template <class T, int MaxSize>
class SeqList;
template <class T, int MaxSize>
SeqList<T, MaxSize> mergeTwoSortedList(SeqList<T, MaxSize> &arr1,
                                       SeqList<T, MaxSize> &arr2);
template <class T, int MaxSize>
class SeqList
{
    T data[MaxSize];
    int length;

public:
    SeqList();                  //无参构造函数
    SeqList(T a[], int n);      //有参构造函数
    int ListLength();           //求线性表长度
    T Get(int pos);             //按位查找
    int Locate(T item);         //按值查找
    void PrintSeqList();        //遍历打印
    void Insert(int i, T item); //在第i的位置插入
    T Delete(int i);            //删除第i个元素
    T deleteMin();              //删除最小元素
    void Sort();                //排序(快速排序)
    void Insertion_sort();      //插入排序
    void half_sort_1();         //二分之后的插入排序
    void half_sort_2();         //二分之后的插入排序
    friend SeqList<T, MaxSize> mergeTwoSortedList<>(SeqList<T, MaxSize> &arr1,
                                                    SeqList<T, MaxSize> &arr2);
};
#endif