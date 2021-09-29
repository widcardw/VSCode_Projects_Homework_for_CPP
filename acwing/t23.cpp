#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool hasPath(vector<vector<char>>& matrix, string &str) {
        if (matrix.size() == 0) return false;
        bool* visited = new bool[matrix.size() * matrix[0].size()];
        for (int i = 0; i < matrix.size(); i ++ ) {
            for (int j = 0; j < matrix[i].size(); j ++ ) {
                if (dfs(matrix, str, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }
    bool dfs(vector<vector<char>>& matrix, string &str, int i, int j, int k, bool* visited) {
        if (matrix[i][j] != str[k]) return false;
        if (str.length() == k + 1) return true;
        int pos = i * matrix[i].size() + j;
        visited[pos] = true;
        for (int l = 0; l < 4; l ++) {
            int x = i + dx[l], y = j + dy[l];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[x].size() && !visited[x * matrix[x].size() + y]) {
                if (dfs(matrix, str, x, y, k + 1, visited)) {
                    return true;
                }
            }
        }
        visited[pos] = false;
        return false;
    }
};