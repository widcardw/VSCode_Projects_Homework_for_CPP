#include "algraph.h"
// #include "SeqQueue.h"
#include "SeqQueue.cpp"
#include <iomanip>
#include <fstream>
template <class T>
ALGraph<T>::ALGraph(GraphType t, T vexs[], int n, int e, std::istream &in)
{
    kind = t;
    switch (kind)
    {
    case undigraph:
    {
        int i, va, vb, j;
        EdgeNode *p;
        vexnum = n;
        edgenum = e;
        adjlist.resize(vexnum);
        for (i = 0; i < vexnum; ++i)
        {
            adjlist[i].data = vexs[i];
            adjlist[i].firstedge = 0;
        }
        for (j = 0; j < edgenum; ++j)
        {
            std::cout << "Input va vb: ";
            in >> va >> vb;
            p = new EdgeNode;
            p->adjvex = vb;
            p->weight = 1;
            p->nextedge = adjlist[va].firstedge;
            adjlist[va].firstedge = p;
            p = new EdgeNode;
            p->adjvex = va;
            p->weight = 1;
            p->nextedge = adjlist[vb].firstedge;
            adjlist[vb].firstedge = p;
        }
    }
    break;
    case digraph:
    {
        int i, va, vb, j;
        EdgeNode *p;
        vexnum = n;
        edgenum = e;
        adjlist.resize(vexnum);
        for (i = 0; i < vexnum; ++i)
        {
            adjlist[i].data = vexs[i];
            adjlist[i].firstedge = 0;
        }
        for (j = 0; j < edgenum; ++j)
        {
            std::cout << "Input va vb: ";
            in >> va >> vb;
            p = new EdgeNode;
            p->adjvex = vb;
            p->weight = 1;
            p->nextedge = adjlist[va].firstedge;
            adjlist[va].firstedge = p;
        }
    }
    break;
    case undinetwork:
    {
        int i, va, vb, j, w;
        EdgeNode *p;
        vexnum = n;
        edgenum = e;
        adjlist.resize(vexnum);
        for (i = 0; i < vexnum; ++i)
        {
            adjlist[i].data = vexs[i];
            adjlist[i].firstedge = 0;
        }
        for (j = 0; j < edgenum; ++j)
        {
            std::cout << "Input va vb w: ";
            in >> va >> vb >> w;
            p = new EdgeNode;
            p->adjvex = vb;
            p->weight = w;
            p->nextedge = adjlist[va].firstedge;
            adjlist[va].firstedge = p;
            p = new EdgeNode;
            p->adjvex = va;
            p->weight = w;
            p->nextedge = adjlist[vb].firstedge;
            adjlist[vb].firstedge = p;
        }
    }
    break;
    case dinetwork:
    {
        int i, va, vb, j, w;
        EdgeNode *p;
        vexnum = n;
        edgenum = e;
        adjlist.resize(vexnum);
        for (i = 0; i < vexnum; ++i)
        {
            adjlist[i].data = vexs[i];
            adjlist[i].firstedge = 0;
        }
        for (j = 0; j < edgenum; ++j)
        {
            std::cout << "Input va vb w: ";
            in >> va >> vb >> w;
            p = new EdgeNode;
            p->adjvex = vb;
            p->weight = w;
            p->nextedge = adjlist[va].firstedge;
            adjlist[va].firstedge = p;
        }
    }
    break;
    }
}
template <class T>
ALGraph<T>::~ALGraph()
{
    int i, j;
    EdgeNode *p, *q;
    for (i = 0; i < vexnum; ++i)
    {
        p = adjlist[i].firstedge;
        while (p != 0)
        {
            q = p;
            p = p->nextedge;
            delete q;
            q = NULL;
        }
    }
    adjlist.clear();
}
template <class T>
EdgeNode *ALGraph<T>::FirstNode(int v)
{
    return this->adjlist[v].firstedge;
}
template <class T>
int ALGraph<T>::VexNum()
{
    return vexnum;
}
template <class T>
int ALGraph<T>::EdgeNum()
{
    return edgenum;
}
template <class T>
void ALGraph<T>::DFS(int v, bool *visited)
{
    std::cout << adjlist[v].data;
    visited[v] = true;
    EdgeNode *p = adjlist[v].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
            DFS(p->adjvex, visited);
        p = p->nextedge;
    }
}
template <class T>
int ALGraph<T>::DFSTraverse()
{
    int count = 0, i;
    bool *visited = new bool[vexnum];
    for (i = 0; i < vexnum; ++i)
        visited[i] = false;
    for (i = 0; i < vexnum; ++i)
        if (!visited[i])
        {
            DFS(i, visited);
            count++;
        }
    delete[] visited;
    return count;
}
template <class T>
int ALGraph<T>::BFSTraverse()
{
    int count = 0, i, j, k;
    SeqQueue<int, 10> q;
    EdgeNode *p;
    bool *visited = new bool[vexnum];
    for (i = 0; i < vexnum; ++i)
        visited[i] = false;
    for (i = 0; i < vexnum; ++i)
    {
        if (!visited[i])
        {
            p = adjlist[i].firstedge;
            std::cout << adjlist[i].data;
            visited[i] = true;
            q.EnQueue(i);
            while (!q.Empty())
            {
                j = q.DeQueue();
                p = adjlist[j].firstedge;
                while (p)
                {
                    if (!visited[p->adjvex])
                    {
                        std::cout << adjlist[p->adjvex].data;
                        visited[p->adjvex] = true;
                        q.EnQueue(p->adjvex);
                    }
                    p = p->nextedge;
                }
            }
            count++;
        }
    }
    return count;
}
template <class T>
void ALGraph<T>::PrintVexs()
{
    for (int i = 0; i < vexnum; ++i)
        std::cout << std::setw(5) << adjlist[i].data;
    std::cout << std::endl;
}
template <class T>
void ALGraph<T>::PrintEdges()
{
    int i;
    EdgeNode *p;
    for (i = 0; i < vexnum; ++i)
    {
        p = adjlist[i].firstedge;
        std::cout << std::setw(5) << i;
        while (p)
        {
            std::cout << std::setw(5) << p->adjvex;
            p = p->nextedge;
        }
        std::cout << std::endl;
    }
}
template <class T>
void ALGraph<T>::TopoSort()
{
    int *indegree = new int[vexnum]; //创建入度数组
    SeqQueue<int, 20> s;             //创建队列,存放入度为0的节点
    int i, c;
    for (i = 0; i < vexnum; ++i) //初始化入度数组为0
        indegree[i] = 0;
    EdgeNode *p;
    for (i = 0; i < vexnum; ++i) //初始化入度数组为真实的入度值
    {
        p = adjlist[i].firstedge;
        for (; p != NULL; p = p->nextedge)
            indegree[p->adjvex]++; //p指向的节点入度自增
    }
    for (i = 0; i < vexnum; ++i) //将所有入度为0的节点入队
        if (!indegree[i])
            s.EnQueue(i);
    c = 0; //存放已经读取过的节点数
    while (!s.Empty())
    {
        i = s.DeQueue();              //i为当前入度为0的节点
        std::cout << adjlist[i].data; //输出节点的数据
        ++c;                          //读取一个节点
        p = adjlist[i].firstedge;     //p为当前节点指向的下个节点
        for (; p; p = p->nextedge)    //因为当前节点i已经被输出,所以在i被"删除"的同时
        {                             //i直接指向的节点入度减少
            indegree[p->adjvex]--;
            if (!indegree[p->adjvex]) //如果i直接指向的节点入度为0
                s.EnQueue(p->adjvex); //那么就把这个节点入队
        }
    }
    if (c < vexnum)
        std::cout << "これAOV网存在环!" << std::endl;
    delete[] indegree;
}