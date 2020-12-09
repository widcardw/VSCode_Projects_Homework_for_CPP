#ifndef _MGRAPH_H
#define _MGRAPH_H
#include <iostream>
#include <vector>
enum GraphType
{
    undigraph,
    digraph,
    undinetwork,
    dinetwork
};
class MGraph
{
private:
    int vexnum, edgenum;
    GraphType kind;
    std::vector<std::vector<int>> edges;
    std::vector<int> vexs;
    void DFS(int v, bool *visited);

public:
    MGraph(GraphType t, int v[], int n, int e);
    ~MGraph();
    int VexNum();
    int EdgeNum();
    int DFSTraverse();
    int BFSTraverse();
    void PrintEdges();
    void PrintVexs();
};
#endif