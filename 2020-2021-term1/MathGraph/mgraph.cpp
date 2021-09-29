#include <vector>
#include <cstdlib>
#include "mgraph.h"

MGraph::MGraph(std::vector<Point>& v)
{
    this->vexnum = v.size();
    // 初始化节点数量
    this->vexs.resize(this->vexnum);
    // 初始化边矩阵大小
    this->edges.resize(this->vexnum);
    for (int i = 0; i < this->vexnum; i++) 
    {
        this->vexs.at(i) = v[i];
        this->edges.at(i).resize(this->vexnum);
    }
    for (int i = 0; i < this->vexnum; i++) 
    {
        for (int j = 0; j < this->vexnum; j++) 
        {
            this->edges.at(i).at(j) = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
        }
    }
}

MGraph::~MGraph() 
{
    for (int i = 0; i < this->vexnum; i++) 
    {
        this->edges[i].clear();
    }
    this->edges.clear();
    this->vexs.clear();
}

int MGraph::MiniNum(Edge *miniedges)
{
    int k, i;
    for (i = 0; i < vexnum; ++i)
        if (miniedges[i].lowcost != 0 && miniedges[i].lowcost != 0x80000000)
        {
            k = i;
            break;
        }
    for (i = 0; i < vexnum; ++i)
    {
        if (miniedges[i].lowcost == 0 || miniedges[i].lowcost == 0x80000000)
            continue;
        if (miniedges[i].lowcost < miniedges[k].lowcost)
            k = i;
    }
    return k;
}

Point MGraph::GetVexValue(int v)
{
    return this->vexs.at(v);
}

int MGraph::GetEdgeValue(int v, int i)
{
    return this->edges.at(v).at(i);
}

int MGraph::Prim(int v, std::vector<std::pair<Point, Point>>& vec)
{
    // std::vector<std::pair<char, char>> vec;
    int length = 0;
    Edge* miniedges = new Edge[this->vexnum];
    for (int i = 0; i < this->vexnum; i++)
    {
        miniedges[i].adjvex = GetVexValue(v);
        miniedges[i].lowcost = GetEdgeValue(v, i);
    }
    miniedges[v].lowcost = 0;
    for (int i = 1; i < this->vexnum; i++) 
    {
        int k = MiniNum(miniedges);
        Point p1 = miniedges[k].adjvex;
        Point p2 = GetVexValue(k);
        vec.push_back(std::pair<Point, Point>(p1, p2));
        length += abs(p1.x - p2.x) + abs(p1.y - p2.y);
        miniedges[k].lowcost = 0;
        for (int j = 0; j < this->vexnum; j++) 
        {
            if (GetEdgeValue(k, j) < miniedges[j].lowcost)
            {
                miniedges[j].adjvex = GetVexValue(k);
                miniedges[j].lowcost = GetEdgeValue(k, j);
            }
        }
    }
    delete[] miniedges;
    return length;
}

int MGraph::Prim(int v)
{
    // std::vector<std::pair<char, char>> vec;
    int length = 0;
    Edge* miniedges = new Edge[this->vexnum];
    for (int i = 0; i < this->vexnum; i++)
    {
        miniedges[i].adjvex = GetVexValue(v);
        miniedges[i].lowcost = GetEdgeValue(v, i);
    }
    miniedges[v].lowcost = 0;
    for (int i = 1; i < this->vexnum; i++) 
    {
        int k = MiniNum(miniedges);
        Point p1 = miniedges[k].adjvex;
        Point p2 = GetVexValue(k);
        length += abs(p1.x - p2.x) + abs(p1.y - p2.y);
        miniedges[k].lowcost = 0;
        for (int j = 0; j < this->vexnum; j++) 
        {
            if (GetEdgeValue(k, j) < miniedges[j].lowcost)
            {
                miniedges[j].adjvex = GetVexValue(k);
                miniedges[j].lowcost = GetEdgeValue(k, j);
            }
        }
    }
    delete[] miniedges;
    return length;
}