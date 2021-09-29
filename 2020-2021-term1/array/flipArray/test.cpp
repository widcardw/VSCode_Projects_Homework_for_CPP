#include "flipArray.h"
#include "flipArray.cpp"
int main()
{
    int arr[5][5] = {{1, 2, 3, 4, 5},
                     {2, 4, 6, 8, 10},
                     {3, 6, 9, 12, 15},
                     {4, 8, 12, 16, 20},
                     {5, 10, 15, 20, 25}};
    mMatrix<int> m1(5, arr);
    m1.print();
    return 0;
}