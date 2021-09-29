#include "triple.h"
int main()
{
    Triple<int> arr[] = {{0, 0, 2}, {1, 3, -5}, {2, 1, 4}, {4, 3, 9}};
    SparseMatrix<int> l1(arr, 5, 5, 4);
    l1.print();
    return 0;
}