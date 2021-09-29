#include "MGraph.h"
#include <queue>
#include <cmath>
#include <iomanip>

MGraph::MGraph(GraphType t, int v[], int n, int e)
{
    vexnum = n;
    edgenum = e;
    kind = t;
    vexs.resize(vexnum);
    edges.resize(vexnum);
    int i, j, va, vb, w;
    for (i = 0; i < n; ++i)
        vexs[i] = v[i];
    for (i = 0; i < n; ++i)
        edges[i].resize(vexnum);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            edges[i][j] = INFINITY;
    for (i = 0; i < e; ++i)
    {
        std::cout << "input va vb w: ";
        std::cin >> va >> vb;
        std::cin >> w;
        edges[va][vb] = edges[vb][va] = w;
    }
}
MGraph::~MGraph()
{
    vexs.clear();
    for (int i = 0; i < vexnum; ++i)
        edges[i].clear();
    edges.clear();
}
int MGraph::VexNum()
{
    return vexnum;
}
int MGraph::EdgeNum()
{
    return edgenum;
}
void MGraph::DFS(int v, bool *visited)
{
    std::cout << vexs[v];
    visited[v] = true;
    for (int i = 0; i < vexnum; ++i)
        if (edges[v][i] == 1 && !visited[i])
            DFS(i, visited);
}
int MGraph::DFSTraverse()
{
    int v, count = 0;
    bool *visited = new bool[vexnum];
    for (v = 0; v < vexnum; ++v)
        visited[v] = false;
    for (v = 0; v < vexnum; ++v)
        if (!visited[v])
        {
            DFS(v, visited);
            count++;
        }
    delete[] visited;
    return count;
}
int MGraph::BFSTraverse()
{
    std::queue<int> q;
    int i, j, u, count = 0;
    bool *visited = new bool[vexnum];
    for (i = 0; i < vexnum; ++i)
        visited[i] = false;
    for (i = 0; i < vexnum; ++i)
    {
        if (!visited[i])
        {
            std::cout << vexs[i];
            visited[i] = true;
            q.push(i);
            while (!q.empty())
            {
                u = q.front();
                q.pop();
                for (j = 0; j < vexnum; ++j)
                {
                    if (edges[u][i] == 1 && !visited[j])
                    {
                        std::cout << vexs[j];
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            count++;
        }
    }
    delete[] visited;
    return count;
}
void MGraph::PrintVexs()
{
    for (int i = 0; i < vexnum; ++i)
        std::cout << vexs[i] << std::endl;
}
void MGraph::PrintEdges()
{
    int i, j;
    for (i = 0; i < vexnum; ++i)
    {
        for (j = 0; j < vexnum; ++j)
            std::cout << std::setw(8) << edges[i][j];
        std::cout << std::endl;
    }
}