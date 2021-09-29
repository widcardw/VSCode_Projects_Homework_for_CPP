#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void swap_char(string& str, int i, int j)
{
    char temp = str.at(j);
    str.at(j) = str.at(i);
    str.at(i) = temp;
}

int bfs(string str)
{
    string dest = "12345678x";
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    queue<string> q;
    unordered_map<string, int> map;
    q.push(str);
    map[str] = 0;
    while(q.size() != 0)
    {
        string current = q.front();
        q.pop();
        if (current == dest) return map[current];
        int distance = map[current];

        int x_pos = current.find('x');
        int row = x_pos / 3, col = x_pos % 3;

        for (int i = 0; i < 4; i++)
        {
            int y = row + dy[i];
            int x = col + dx[i];

            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                swap_char(current, y * 3 + x, x_pos);
                if (map.count(current) == 0)
                {
                    map[current] = distance + 1;
                    q.push(current);
                }
                swap_char(current, y * 3 + x, x_pos);
            }
        }
    }
    
    return -1;
}

int main()
{
    char c;
    string src;
    for (int i = 0; i < 9; i++) 
    {
        cin >> c;
        src += c;
    }
    cout << bfs(src) << endl;
    return 0;
}