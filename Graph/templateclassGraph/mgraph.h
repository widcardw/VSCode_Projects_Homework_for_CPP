#include <iostream>
#include <vector>
// #program once
#ifndef _GRAPHTYPE_H
#define _GRAPHTYPE_H
enum GraphType
{
    undigraph,
    digraph,
    undinetwork,
    dinetwork
};
#endif

#ifndef _EDGE_H
#define _EDGE_H
template <class T>
struct Edge
{
    T adjvex;
    float lowcost;
};
#endif

#ifndef _EDGETYPE_H
#define _EDGETYPE_H
template <class T>
struct EdgeType
{
    T head, tail;
    int cost;
    EdgeType(T h, T t, int c)
    {
        head = h;
        tail = t;
        cost = c;
    }
};
#endif

#ifndef _MGRAPH_H
#define _MGRAPH_H

template <class T>
class MGraph
{
private:
    int vexnum, edgenum;
    GraphType kind;
    std::vector<std::vector<float>> edges;
    std::vector<T> vexs;
    void DFS(int v, bool *visited);
    int MiniNum(Edge<T> *miniedges);

public:
    MGraph(GraphType t, T v[], int n, int e);
    ~MGraph();
    int VexNum();
    int EdgeNum();
    T GetVexValue(int i);
    // int GetVexValueNum(T v);
    float GetEdgeValue(int i, int j);
    // void InsertVex(T v);
    // void RemoveVex(T v);
    // void InsertEdge(EdgeType e);
    // void DeleteEdge(EdgeType e);
    int DFSTraverse();
    int BFSTraverse();
    void PrintEdges();
    void PrintVexs();
    void Prim(int v);
    void Dijkstra(int v, int path[], float dist[]);
    void TopoSort();
};
#endif