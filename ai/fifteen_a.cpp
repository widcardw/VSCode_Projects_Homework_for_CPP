#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;

const int DIR[4] = {-1, -4, 4, 1};
int dx[4] = {0, -1, 1, 0}, dy[4] = {-1, 0, 0, 1};
const int LEN = 16;

class Status
{
public:
    int Parent;
    int Option;
    int Step;
    int Value;
    vector<int> Data;
    Status(const vector<int> &arr, int pa, int op, int st, int va)
    {
        assert(arr.size() == LEN);
        Parent = pa;
        Option = op;
        Step = st;
        Value = va;
        Data.assign(arr.begin(), arr.end());
    }
    Status()
    {
        Parent = 0;
        Option = 0;
        Step = 0;
        Value = 0;
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
    // bool operator<(const Status &s) const
    // {
    //     return this->Value > s.Value;
    // }
};

bool isDestNode(const vector<int> &dest, const Status &tmp)
{
    for (int i = 0; i < LEN; i++)
        if (dest[i] != tmp.Data[i])
            return false;
    return true;
}

int evaluateDistance(const vector<int> &dest, const Status &n)
{
    int count = 0;
    for (int i = 0; i < LEN; i++)
        if (n.Data[i] != dest[i])
            count++;
    return count;
}

int evaluateDistance(const vector<int> &dest, const vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < LEN; i++)
        if (arr[i] != dest[i])
            count++;
    return count;
}

void PrintSteps(vector<Status> &Closed)
{
    int parent = Closed.size();
    stack<Status> res;
    while (parent != 0)
    {
        res.push(Closed[parent - 1]);
        parent = Closed[parent - 1].Parent;
    }
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

void insertNode(vector<Status> &Open, const Status &n)
{
    int i;
    for (i = 0; i < Open.size(); i++)
        if (n.Value <= Open[i].Value)
            break;
    Open.insert(Open.begin() + i, n);
}

void ExtendNode(vector<Status> &Closed, vector<Status> &Open,
                const Status &tmp, int parent, const vector<int> &dest)
{
    int zero_index = findZero(tmp.Data);
    int row = zero_index / 4, col = zero_index % 4;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i], ncol = col + dy[i];
        if (nrow >= 0 && nrow < 4 && ncol >= 0 && ncol < 4)
        {
            int zero_new = nrow * 4 + ncol;
            Status n = Status(tmp.Data, parent, DIR[i], tmp.Step + 1, 0);
            swap(n.Data[zero_index], n.Data[zero_new]);
            n.Value = n.Step + evaluateDistance(dest, n);
            if (!hasNode(n, Closed) && !hasNode(n, Open))
                insertNode(Open, n);
        }
    }
}

void Solve(const vector<int> &dest, const vector<int> &src)
{
    vector<Status> Open;
    vector<Status> Closed;
    Status start = Status(src, 0, 0, 0, evaluateDistance(dest, src));
    Open.push_back(start);

    while (!Open.empty())
    {
        Status tmp = Open.front();
        Open.erase(Open.begin());
        Closed.push_back(tmp);

        if (isDestNode(dest, tmp))
        {
            PrintSteps(Closed);
            return;
        }
        Status n[4];
        int parent = Closed.size();
        ExtendNode(Closed, Open, tmp, parent, dest);
    }
}

int main()
{
    vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8, 11, 9, 10, 12, 0, 13, 14, 15};
    vector<int> dest = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    Solve(dest, src);
    return 0;
}