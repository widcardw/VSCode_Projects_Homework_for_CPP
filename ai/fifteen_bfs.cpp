#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

int dx[4] = {0, -1, 1, 0}, dy[4] = {-1, 0, 0, 1};
const int DIR[4] = {-1, -4, 4, 1};
const int LEN = 16;
unordered_map<int, char> m;

class Status
{
public:
    int Parent;
    int Option;
    vector<int> Data;
    Status(const vector<int> &arr, int pa, int op)
    {
        assert(arr.size() == LEN);
        Parent = pa;
        Option = op;
        Data.assign(arr.begin(), arr.end());
    }
    Status()
    {
        Parent = 0;
        Option = 0;
        Data = vector<int>(LEN, 0);
    }
    void print_map()
    {
        for (int i = 0; i < LEN; i++)
        {
            cout << setw(4) << Data[i];
            if (i % 4 == 3)
                cout << endl;
        }
    }
};

bool matchNode(const Status &n, Status &close)
{
    for (int i = 0; i < LEN; i++)
        if (n.Data[i] != close.Data[i])
            return false;
    return true;
}

bool hasNode(const Status &n, vector<Status> &Closed)
{
    for (int i = 0; i < Closed.size(); i++)
        if (matchNode(n, Closed[i]))
            return true;
    return false;
}

bool isDestNode(const vector<int> &dest, const Status &tmp)
{
    for (int i = 0; i < LEN; i++)
        if (dest[i] != tmp.Data[i])
            return false;
    return true;
}

void getAnswer(vector<Status> &Closed, stack<Status>& res)
{
    int parent = Closed.size();
    while (parent != 0)
    {
        res.push(Closed[parent - 1]);
        parent = Closed[parent - 1].Parent;
    }
}

void PrintOptions(vector<Status> &Closed)
{
    stack<Status> res;
    getAnswer(Closed, res);
    while (!res.empty())
    {
        cout << m[res.top().Option];
        res.pop();
    }
    cout << endl;
}

void PrintSteps(vector<Status> &Closed)
{
    stack<Status> res;
    getAnswer(Closed, res);
    while (!res.empty())
    {
        res.top().print_map();
        res.pop();
        cout << endl;
    }
}

int findZero(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 0)
            return i;
    return -1;
}

void ExtendNode(vector<Status> &Closed, vector<Status> &Open,
                const Status &tmp, int parent)
{
    int zero_index = findZero(tmp.Data);
    int row = zero_index / 4, col = zero_index % 4;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow >= 0 && nrow < 4 && ncol >= 0 && ncol < 4)
        {
            int zero_new = nrow * 4 + ncol;
            Status n = Status(tmp.Data, parent, DIR[i]);
            swap(n.Data[zero_index], n.Data[zero_new]);
            if (!hasNode(n, Closed) && !hasNode(n, Open))
                Open.push_back(n);
        }
    }
}

void Solve(const vector<int> &dest, const vector<int> &src, void (*optionFunc)(vector<Status>&))
{
    vector<Status> Open;
    vector<Status> Closed;
    Status start = Status(src, 0, 0);
    Open.push_back(start);

    while (!Open.empty())
    {
        Status tmp = Open.front();
        Open.erase(Open.begin());
        Closed.push_back(tmp);

        if (isDestNode(dest, tmp))
        {
            (*optionFunc)(Closed);
            return;
        }
        Status n[4];
        int parent = Closed.size();
        ExtendNode(Closed, Open, tmp, parent);
    }
}

void init_map()
{
    m[-1] = 'L';
    m[-4] = 'U';
    m[4] = 'D';
    m[1] = 'R';
}

int main()
{
    init_map();
    vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 12, 13, 10, 14, 15};
    vector<int> dest = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    Solve(dest, src, PrintOptions);
    return 0;
}