#include <iostream>
void BubbleSort(int *arr, int n);
void BubbleSortBtr(int *arr, int n);
void SelectSort(int *arr, int n);
int main()
{
    return 0;
}
void BubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; ++i)
    {
        for (j = 0; j < n - i; ++j)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}
void BubbleSortBtr(int *arr, int n)
{
    int i, j, temp;
    bool exchange = 1;
    for (i = 1; i < n && exchange == 1; ++i)
    {
        exchange = false;
        for (j = 0; j < n - i; ++j)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                exchange = true;
            }
    }
}
void SelectSort(int *arr, int n)
{
    int i, j, min = 0, temp;
    for (i = 0; i < n; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
void InsertSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; ++i)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}