#include <iostream>
#include "SeqList.h"
#include <iomanip>
using namespace std;
template <class T, int MaxSize>
SeqList<T, MaxSize>::SeqList()
{
    //data = NULL;
    length = 0;
}
template <class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
    if (n > MaxSize)
    {
        std::cerr << "参数非法" << std::endl;
        exit(1);
    }
    length = n;
    int i;
    for (i = 0; i < length; ++i)
        data[i] = a[i];
    for (i; i < MaxSize; ++i)
        data[i] = 0;
}
template <class T, int MaxSize>
int SeqList<T, MaxSize>::ListLength()
{
    return length;
}
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Get(int pos)
{
    if (pos < 0 || pos >= length)
    {
        std::cerr << "查找位置非法" << std::endl;
        exit(1);
    }
    return data[pos];
}
template <class T, int MaxSize>
int SeqList<T, MaxSize>::Locate(T item)
{
    for (int i = 0; i < length; ++i)
        if (item == data[i])
            return i;
    return -1;
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList()
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << setw(4) << data[i];
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Insert(int i, T item)
{
    if (length >= MaxSize)
    {
        std::cerr << "上溢" << std::endl;
        exit(1);
    }
    if (i < 0 || i > length)
    {
        std::cerr << "插入位置非法" << std::endl;
        exit(1);
    }
    int j;
    for (j = length; j >= i; --j)
        data[j + 1] = data[j];
    data[i] = item;
    ++length;
}
template <class T, int MaxSize>
T SeqList<T, MaxSize>::Delete(int i)
{
    if (length == 0)
    {
        std::cerr << "下溢" << std::endl;
        exit(1);
    }
    if (i < 0 || i >= length)
    {
        std::cerr << "删除位置非法" << std::endl;
        exit(1);
    }
    T temp = data[i];
    for (int j = i; j < length; ++j)
        data[j] = data[j + 1];
    data[length] = 0;
    length--;
    return temp;
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Insertion_sort()
{
    int i, j;
    T temp;
    for (i = 1; i < length; ++i)
    {
        temp = data[i];
        for (j = i; j > 0 && temp < data[j - 1]; --j)
        {
            data[j] = data[j - 1];
        }
        data[j] = temp;
    }
}
template <class T, int MaxSize>
void istst(T *arr, int left, int right)
{
    int i, j;
    T temp;
    for (i = left; i < right; ++i)
    {
        temp = *(arr + i);
        for (j = i; j > left && temp < *(arr + j - 1); --j)
            *(arr + j) = *(arr + j - 1);
        *(arr + j) = temp;
    }
}
template <class T, int MaxSize>
void swapElement(T *arr, int left, int right)
{
    T temp = *(arr + left);
    *(arr + left) = *(arr + right);
    *(arr + right) = temp;
}
template <class T, int MaxSize>
void set_3_smp_mid_to_bgn(T *arr, int left, int right)
{
    if (arr[(right - left) / 2] > arr[right - 1])
        swapElement<T, MaxSize>(arr, (right - left) / 2, (right - 1));
    if (arr[left] > arr[right - 1])
        swapElement<T, MaxSize>(arr, left, (right - 1));
    if (arr[(right - left) / 2] > arr[left])
        swapElement<T, MaxSize>(arr, (right - left) / 2, left);
}
template <class T, int MaxSize>
void quickSort_1(T *arr, int length)
{
    if (length <= 8)
    {
        istst<T, MaxSize>(arr, 0, length);
        return;
    }
    int low = 0, high = length;
    set_3_smp_mid_to_bgn<T, MaxSize>(arr, 0, length);
    T temp = arr[0];
    while (true)
    {
        while (arr[++low] < temp && low < length - 1)
            ;
        while (arr[--high] > temp)
            ;
        if (low >= high)
            break;
        swapElement<T, MaxSize>(arr, low, high);
    }
    swapElement<T, MaxSize>(arr, 0, high);
    quickSort_1<T, MaxSize>(arr, high);
    quickSort_1<T, MaxSize>(arr + high + 1, length - high - 1);
}
template <class T, int MaxSize>
void quickSort_2(T *arr, int length)
{
    if (length <= 8)
    {
        istst<T, MaxSize>(arr, 0, length);
        return;
    }
    int low = 0, high = length;
    int left = 0, right = length;
    set_3_smp_mid_to_bgn<T, MaxSize>(arr, 0, length);
    T temp = arr[0];
    while (true)
    {
        while (arr[++low] <= temp && high > low && low < length)
        {
            if (arr[low] == temp)
                swapElement<T, MaxSize>(arr, low, ++left);
        }
        while (arr[--high] >= temp && high > low && high > 0)
        {
            if (arr[high] == temp)
                swapElement<T, MaxSize>(arr, high, --right);
        }
        if (low >= high)
            break;
        swapElement<T, MaxSize>(arr, low, high);
    }
    // swapElement<T, MaxSize>(arr, 0, high);
    while (left >= 0)
    {
        swapElement<T, MaxSize>(arr, left--, high--);
    }
    while (right <= length - 1)
    {
        swapElement<T, MaxSize>(arr, right++, low++);
    }
    quickSort_2<T, MaxSize>(arr, high + 1);
    quickSort_2<T, MaxSize>(arr + low, length - low);
}
// template <class T, int MaxSize>
// void quick_sort(T *arr, int left, int right)
// {
//     if (right - left <= 5)
//         istst<T, MaxSize>(arr, left, right);
//     else
//     {
//         int low = left, high = right;
//         set_3_smp_mid_to_bgn<T, MaxSize>(arr, left, right);
//         T temp = arr[0];
//         while (true)
//         {
//             while (arr[++low] < temp && low < right - 1)
//                 ;
//             while (arr[--high] > temp)
//                 ;
//             if (low >= high)
//                 break;
//             swapElement<T, MaxSize>(arr, low, high);
//         }
//         swapElement<T, MaxSize>(arr, left, high);
//         quick_sort<T, MaxSize>(arr, left, high);
//         quick_sort<T, MaxSize>(arr, high + 1, right);
//     }
// }
// template <class T, int MaxSize>
// void SeqList<T, MaxSize>::half_sort_1()
// {
//     T pivot = data[0];
//     int low = 0, high = length - 1;
//     while (true)
//     {
//         while (data[high] >= pivot)
//             --high;
//         if (high <= low)
//         {
//             data[low] = pivot;
//             istst<T, MaxSize>(data, 0, low);
//             istst<T, MaxSize>(data, low + 1, length);
//             break;
//         }
//         else
//             data[low] = data[high];
//         while (data[low] <= pivot)
//             ++low;
//         if (high <= low)
//         {
//             data[high] = pivot;
//             istst<T, MaxSize>(data, 0, high);
//             istst<T, MaxSize>(data, high + 1, length);
//             break;
//         }
//         else
//             data[high] = data[low];
//     }
// }
template <class T, int MaxSize>
void SeqList<T, MaxSize>::half_sort_2()
{
    int low = 0, high = length;
    T temp = data[0];
    while (true)
    {
        while (data[++low] < temp && low < length - 1)
            ;
        while (data[--high] > temp)
            ;
        if (low >= high)
            break;
        swapElement<T, MaxSize>(data, low, high);
    }
    swapElement<T, MaxSize>(data, 0, high);
    istst<T, MaxSize>(data, 0, high);
    istst<T, MaxSize>(data, high + 1, length);
}
template <class T, int MaxSize>
void SeqList<T, MaxSize>::Sort()
{
    // quick_sort<T, MaxSize>(data, 0, length);
    // this->half_sort_2();
    // swapElement<T, MaxSize>(data, 0, length - 1);
    // quickSort_1<T, MaxSize>(data, length);
    quickSort_2<T, MaxSize>(data, length);
}
template <class T, int MaxSize>
T SeqList<T, MaxSize>::deleteMin()
{
    if (length == 0)
    {
        std::cerr << "下溢" << std::endl;
        exit(1);
    }
    int i, min = 0;
    T temp = data[0];
    for (i = 0; i < length; ++i)
        if (data[i] < temp)
        {
            temp = data[i];
            min = i;
        }
    data[min] = data[length - 1];
    length--;
    return temp;
}
template <class T, int MaxSize>
SeqList<T, MaxSize> mergeTwoSortedList(SeqList<T, MaxSize> &arr1, SeqList<T, MaxSize> &arr2)
{

    SeqList<T, MaxSize> c;
    c.length = arr1.length + arr2.length;
    if (c.length > MaxSize)
    {
        std::cerr << "上溢" << std::endl;
        exit(1);
    }
    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.data[i] < arr2.data[j])
        {
            c.data[k] = arr1.data[i];
            ++i;
            ++k;
        }
        else
        {
            c.data[k] = arr2.data[j];
            ++j;
            ++k;
        }
    }
    while (i < arr1.length)
    {
        c.data[k] = arr1.data[i];
        ++i;
        ++k;
    }
    while (j < arr2.length)
    {
        c.data[k] = arr2.data[j];
        ++j;
        ++k;
    }
    return c;
}