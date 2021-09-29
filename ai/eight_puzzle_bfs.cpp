#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

const int L = 1, U = 2, D = 3, R = 4;
const int LEN = 9;

void ExtendNode(vector<int> &dest, vector<int> &src, int direction, int parent)
{
    dest.resize(11);
    copy(src.begin() + 1, src.end(), dest.begin() + 1);
    auto zero_index = find(dest.begin() + 2, dest.end(), 0);
    dest[0] = parent;
    switch (direction)
    {
    case L:
    {
        if (zero_index - 1 >= dest.begin() + 2)
        {
            dest[1] = L;
            swap(*(zero_index), *(zero_index - 1)); // Error
        }
        break;
    }
    case U:
    {
        if (zero_index - 3 >= dest.begin() + 2)
        {
            dest[1] = U;
            swap(*(zero_index), *(zero_index - 3));
        }
        break;
    }
    case D:
    {
        if (zero_index + 3 < dest.end())
        {
            dest[1] = D;
            swap(*(zero_index), *(zero_index + 3));
        }
        break;
    }
    case R:
    {
        if (zero_index + 1 < dest.end())
        {
            dest[1] = R;
            swap(*(zero_index), *(zero_index + 1));
        }
        break;
    }
    }
}

bool isDestNode(int *dest, vector<int> &tmp)
{
    for (int i = 0; i < LEN; i++)
        if (dest[i] != tmp[i + 2])
            return false;
    return true;
}

void PrintPuzzleMap(vector<int> &puzzle)
{
    for (int i = 2; i < LEN + 2; i++)
    {
        cout << setw(4) << puzzle[i];
        if (i % 3 == 1)
            cout << endl;
    }
}

void PrintSteps(vector<vector<int>> &Closed)
{
    int parent = Closed.size();
    stack<vector<int>> res;
    while (parent != 0)
    {
        res.push(Closed[parent - 1]);
        parent = Closed[parent - 1][0];
    }
    while(!res.empty()) 
    {
        PrintPuzzleMap(res.top());
        res.pop();
        cout << endl;
    }
}

void Solve(int *dest, int *src)
{
    queue<vector<int>> Open;
    vector<vector<int>> Closed;
    vector<int> start(11, 0);
    copy(src, src + LEN, start.begin() + 2);
    // step 1
    Open.push(start);
    // step 2, Open is not empty
    while (!Open.empty())
    {
        // step 3, pop Open and push tmp into Closed
        vector<int> tmp = Open.front();
        Open.pop();
        Closed.push_back(tmp);
        // judge that tmp matches the dest node
        if (isDestNode(dest, tmp))
        {
            PrintSteps(Closed);
            return;
        }
        // step 4, extend nodes
        vector<int> n1, n2, n3, n4;
        int parent = Closed.size();
        ExtendNode(n1, tmp, L, parent);
        ExtendNode(n2, tmp, U, parent);
        ExtendNode(n3, tmp, D, parent);
        ExtendNode(n4, tmp, R, parent);
        // step 5
        Open.push(n1);
        Open.push(n2);
        Open.push(n3);
        Open.push(n4);
    }
}

int main()
{
    int src[] = {2, 8, 3, 1, 0, 4, 7, 6, 5};
    int dest[] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
    Solve(dest, src);
    return 0;
}