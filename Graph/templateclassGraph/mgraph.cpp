#include "mgraph.h"
#include "SeqQueue.h"
#include <cmath>
#include <string>
#include <iomanip>

template <class T>
MGraph<T>::MGraph(GraphType t, T v[], int n, int e, std::istream &in)
{
    kind = t;
    switch (kind)
    {
    case dinetwork:
    {
        vexnum = n;
        edgenum = e;
        vexs.resize(vexnum);
        edges.resize(vexnum);
        int i, j, va, vb;
        float w;
        for (i = 0; i < n; ++i)
            vexs[i] = v[i];
        for (i = 0; i < n; ++i)
            edges[i].resize(vexnum);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (i == j)
                    edges[i][j] = 0;
                else
                    edges[i][j] = INFINITY;
        for (i = 0; i < e; ++i)
        {
            std::cout << "Input va vb w: ";
            in >> va >> vb;
            in >> w;
            edges[va][vb] = w;
        }
    }
    break;
    case undinetwork:
    {
        vexnum = n;
        edgenum = e;
        vexs.resize(vexnum);
        edges.resize(vexnum);
        int i, j, va, vb;
        float w;
        for (i = 0; i < n; ++i)
            vexs[i] = v[i];
        for (i = 0; i < n; ++i)
            edges[i].resize(vexnum);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (i == j)
                    edges[i][j] = 0;
                else
                    edges[i][j] = INFINITY;
        for (i = 0; i < e; ++i)
        {
            std::cout << "Input va vb w: ";
            in >> va >> vb;
            in >> w;
            edges[va][vb] = edges[vb][va] = w;
        }
    }
    break;
    case digraph:
    {
        vexnum = n;
        edgenum = e;
        vexs.resize(vexnum);
        edges.resize(vexnum);
        int i, j, va, vb;
        // float w;
        for (i = 0; i < n; ++i)
            vexs[i] = v[i];
        for (i = 0; i < n; ++i)
            edges[i].resize(vexnum);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (i == j)
                    edges[i][j] = 0;
                else
                    edges[i][j] = INFINITY;
        for (i = 0; i < e; ++i)
        {
            std::cout << "Input va vb: ";
            in >> va >> vb;
            edges[va][vb] = 1;
        }
    }
    break;
    case undigraph:
    {
        vexnum = n;
        edgenum = e;
        vexs.resize(vexnum);
        edges.resize(vexnum);
        int i, j, va, vb;
        // float w;
        for (i = 0; i < n; ++i)
            vexs[i] = v[i];
        for (i = 0; i < n; ++i)
            edges[i].resize(vexnum);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (i == j)
                    edges[i][j] = 0;
                else
                    edges[i][j] = INFINITY;
        for (i = 0; i < e; ++i)
        {
            std::cout << "Input va vb: ";
            in >> va >> vb;
            edges[va][vb] = edges[vb][va] = 1;
        }
    }
    break;
    }
}
template <class T>
MGraph<T>::~MGraph()
{
    vexs.clear();
    for (int i = 0; i < vexnum; ++i)
        edges[i].clear();
    edges.clear();
}
template <class T>
int MGraph<T>::VexNum()
{
    return vexnum;
}
template <class T>
int MGraph<T>::EdgeNum()
{
    return edgenum;
}
template <class T>
void MGraph<T>::DFS(int v, bool *visited)
{
    std::cout << vexs[v];
    visited[v] = true;
    for (int i = 0; i < vexnum; ++i)
        if (edges[v][i] != 0 && edges[v][i] != INFINITY && !visited[i])
            DFS(i, visited);
}
template <class T>
int MGraph<T>::DFSTraverse()
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
template <class T>
int MGraph<T>::BFSTraverse()
{
    SeqQueue<int, 11> q;
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
            q.EnQueue(i);
            while (!q.Empty())
            {
                u = q.DeQueue();
                for (j = 0; j < vexnum; ++j)
                {
                    if (edges[u][j] != INFINITY && edges[u][j] != 0 && !visited[j])
                    {
                        std::cout << vexs[j];
                        visited[j] = true;
                        q.EnQueue(j);
                    }
                }
            }
            count++;
        }
    }
    delete[] visited;
    return count;
}
template <class T>
void MGraph<T>::PrintVexs()
{
    for (int i = 0; i < vexnum; ++i)
        std::cout << vexs[i] << std::endl;
}
template <class T>
void MGraph<T>::PrintEdges()
{
    int i, j;
    for (i = 0; i < vexnum; ++i)
    {
        for (j = 0; j < vexnum; ++j)
            std::cout << std::setw(12) << edges[i][j];
        std::cout << std::endl;
    }
}
template <class T>
T MGraph<T>::GetVexValue(int i)
{
    return vexs.at(i);
}
template <class T>
float MGraph<T>::GetEdgeValue(int i, int j)
{
    return edges.at(i).at(j);
}
template <class T>
int MGraph<T>::MiniNum(Edge<T> *miniedges)
{
    int k, i;
    for (i = 0; i < vexnum; ++i)
        if (miniedges[i].lowcost != 0 && miniedges[i].lowcost != INFINITY)
        {
            k = i;
            break;
        }
    for (i = 0; i < vexnum; ++i)
    {
        if (miniedges[i].lowcost == 0 || miniedges[i].lowcost == INFINITY)
            continue;
        if (miniedges[i].lowcost < miniedges[k].lowcost)
            k = i;
    }
    return k;
}
template <class T>
void MGraph<T>::Prim(int v)
{
    int i, j, k;
    Edge<T> *miniedges = new Edge<T>[vexnum];
    for (i = 0; i < vexnum; ++i)
    {
        miniedges[i].adjvex = GetVexValue(v);
        miniedges[i].lowcost = GetEdgeValue(v, i);
    }
    miniedges[v].lowcost = 0;
    for (i = 1; i < vexnum; ++i)
    {
        k = MiniNum(miniedges);
        std::cout << miniedges[k].adjvex << "-->" << GetVexValue(k) << std::endl;
        miniedges[k].lowcost = 0;
        for (j = 0; j < vexnum; ++j)
        {
            if (GetEdgeValue(k, j) < miniedges[j].lowcost)
            {
                miniedges[j].adjvex = GetVexValue(k);
                miniedges[j].lowcost = GetEdgeValue(k, j);
            }
        }
    }
    delete[] miniedges;
}
template <class T>
void MGraph<T>::Dijkstra(int v, int path[], float dist[])
{
    bool *s = new bool[vexnum];
    int i, j, k, w;
    float min;
    for (i = 0; i < vexnum; ++i)
    {
        s[i] = false;
        dist[i] = GetEdgeValue(v, i);     //初始化距离
        if (dist[i] < INFINITY || i == v) //初始化路径
            path[i] = v;
        else
            path[i] = -1; //前驱节点不是v
    }
    dist[v] = 0; //到达顶点v的路径长度为0
    s[v] = true; //顶点v进入集合S
    for (i = 0; i < vexnum; ++i)
    {
        min = INFINITY;
        for (j = 0; j < vexnum; ++j) //找到v出发能到达的最短路径
            if (s[j] == false && dist[j] < min)
            {
                k = j; //得到这个顶点j,将其存入k,那么k就是这个距离v最近的顶点
                min = dist[j];
            }
        s[k] = true; //顶点k加入集合S
        for (w = 0; w < vexnum; ++w)
            //如果顶点w不在S内,并且v->...->w的距离大于v->...->k->w的距离,那么就选择v->...->k->w这条路径
            if (s[w] == false && dist[w] > (dist[k] + GetEdgeValue(k, w)))
            {
                dist[w] = dist[k] + GetEdgeValue(k, w); //更新路径长度
                path[w] = k;                            //将路径填写为v->...->k
            }
    }
    delete[] s;
}
template <class T>
void MGraph<T>::TopoSort()
{
    int *indegree = new int[vexnum];
    SeqQueue<int, 20> s;
    int i, j, c;
    for (i = 0; i < vexnum; ++i)
        indegree[i] = 0;
    for (i = 0; i < vexnum; ++i)
        for (j = 0; j < vexnum; ++j)
            if (edges.at(j).at(i) != 0 && edges.at(j).at(i) < INFINITY)
                indegree[i]++;
    // for (i = 0; i < vexnum; ++i)
    //     std::cout << std::setw(8) << indegree[i];
    // std::cout << std::endl;
    for (i = 0; i < vexnum; ++i)
        if (indegree[i] == 0)
            s.EnQueue(i);
    c = 0;
    while (!s.Empty())
    {
        i = s.DeQueue();
        std::cout << vexs.at(i);
        ++c;
        for (j = 0; j < vexnum; ++j)
        {
            if (edges.at(i).at(j) != 0 && edges.at(i).at(j) < INFINITY)
            {
                indegree[j]--;
                if (indegree[j] == 0)
                    s.EnQueue(j);
            }
        }
    }
    if (c < vexnum)
        std::cout << "该AOV网存在环!" << std::endl;
    delete[] indegree;
}
template <class T>
void PrintPath(MGraph<T> &g, int path[], float dist[], int v)
{
    int len = g.VexNum(), i, j;
    // for (i = 0; i < len; ++i)
    //     std::cout << std::setw(6) << path[i];
    // std::cout << std::endl;
    // for (i = 0; i < len; ++i)
    //     std::cout << std::setw(6) << dist[i];
    // std::cout << std::endl;
    for (i = len - 1; i >= 0; --i)
    {
        j = i;
        std::string ss;
        ss = g.GetVexValue(j) + ss;
        while (j != v && path[j] != -1)
        {
            std::ostringstream buffer;
            buffer << g.GetVexValue(path[j]) << " --" << g.GetEdgeValue(path[j], j) << "-> ";
            ss = buffer.str() + ss;
            j = path[j];
        }
        std::cout << "Path length" << std::setw(3) << dist[i] << ": " << ss << std::endl;
    }
}