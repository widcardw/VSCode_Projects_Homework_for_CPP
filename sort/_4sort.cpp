#include <iostream>
#include <fstream>
#include <iomanip>
void ShellSort(int *arr, int start, int end)
{
    int n = end - start, d, i, j, temp;
    for (d = n / 2; d >= 1; d /= 2)
    {
        for (i = d; i < end; ++i)
        {
            temp = arr[i];
            for (j = i - d; j >= start && temp < arr[j]; j -= d)
            {
                arr[j + d] = arr[j];
            }
            arr[j + d] = temp;
        }
    }
}
int Partition(int *arr, int i, int j)
{
    int temp = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= temp)
            --j;
        if (i < j)
        {
            arr[i] = arr[j];
            ++i;
        }
        while (i < j && arr[i] <= temp)
            ++i;
        if (i < j)
        {
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = temp;
    return i;
}
void QuickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void Sift(int *arr, int k, int m)
{
    int i = k;         // the node
    int j = 2 * i + 1; // lchild index of the node
    while (j <= m)
    {
        if (j < m && arr[j] < arr[j + 1])
            ++j;
        if (arr[i] > arr[j]) // value of the node is greater than value of children
            break;
        else
        {
            swap(arr, i, j);
            i = j; // Here may be some error
            j = 2 * i + 1;
        }
    }
}
void HeapSort(int *arr, int start, int end)
{
    int n = end - start, i;
    for (i = n / 2; i >= 0; --i)
        Sift(arr, i, n);
    for (i = 0; i < n; ++i)
    {
        swap(arr, 0, n - i + 1);
        Sift(arr, 0, n - i);
    }
}
int main()
{
    std::ifstream fin;
    fin.open("data.dat");
    if (!fin)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    int x = 0, arr[10000] = {0}, i = 0;
    while (fin >> x)
    {
        arr[i++] = x;
    }
    fin.close();
    HeapSort(arr, 0, 9999);
    std::ofstream fout;
    fout.open("Heap.dat");
    if (!fout)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < 10000; ++i)
    {
        fout << std::setw(10) << arr[i];
        if (i % 10 == 9)
            fout << '\n';
    }
    fout.close();
    return 0;
}