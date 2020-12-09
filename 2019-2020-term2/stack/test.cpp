#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> q;
    q.push(1);
    cout << q.top() << endl;
    q.pop();
    return 0;
}