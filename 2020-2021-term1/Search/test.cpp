#include <iostream>
#include <iomanip>
#include "BiSortTree.h"

void test()
{
    int n, c, x;
    BiNode *p;
    std::cout << "Data length: ";
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Input data: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    BiSortTree tree(arr, n);
    delete[] arr;
    while (true)
    {
        std::cout << "InOrder Traverse: " << std::endl;
        tree.InOrder();
        std::cout << "1.Insert\n2.Delete\n3.Search\nChoose: ";
        std::cin >> c;
        switch (c)
        {
        case 1:
        {
            std::cout << "Input data that you want to insert: ";
            std::cin >> x;
            tree.Insert(x);
        }
        break;
        case 2:
        {
            std::cout << "Input data that you want to delete: ";
            std::cin >> x;
            tree.Delete(x);
        }
        break;
        case 3:
        {
            std::cout << "Input data that you want to search: ";
            std::cin >> x;
            p = tree.Search(x);
            if (p != NULL)
            {
                // tree.SilentInOrder(p, count);
                std::cout << "Found!" << std::endl;
            }
            else
                std::cout << "Cannot Find!" << std::endl;
        }
        break;
        default:
            return;
        }
        std::cout << std::endl;
    }
}
int main()
{
    test();
    return 0;
}