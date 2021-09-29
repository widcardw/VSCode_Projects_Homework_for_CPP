#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
void test()
{
    srand(time(NULL));
    int arr[20], i;
    for (i = 0; i < 20; ++i)
        arr[i] = rand() % 100;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (i = 0; i < 20; ++i)
        q.push(arr[i]);
    for (i = 0; i < 20; ++i)
    {
        std::cout << std::setw(5) << q.top();
        q.pop();
    }
    std::cout << std::endl;
}
int main()
{
    test();
    return 0;
}