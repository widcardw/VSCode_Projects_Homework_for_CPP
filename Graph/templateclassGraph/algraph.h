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

#ifndef _EDGENODE_H
#define _EDGENODE_H
struct EdgeNode
{
    int adjvex;
    int weight;
    EdgeNode *nextedge;
};
#endif

#ifndef _ALGRAPH_H
#define _ALGRAPH_H

template <class T>
struct VexNode
{
    T data;
    EdgeNode *firstedge;
};

template <class T>
class ALGraph
{
private:
    int vexnum, edgenum;
    std::vector<VexNode<T>> adjlist;
    GraphType kind;
    void DFS(int v, bool *visited);
    // int MiniNum(Edge<T> *miniedges);

public:
    ALGraph(GraphType t, T vexs[], int n, int e);
    ~ALGraph();
    EdgeNode *FirstNode(int v);
    int VexNum();
    int EdgeNum();
    int DFSTraverse();
    int BFSTraverse();
    void PrintVexs();
    void PrintEdges();
    void TopoSort();
};
#endif