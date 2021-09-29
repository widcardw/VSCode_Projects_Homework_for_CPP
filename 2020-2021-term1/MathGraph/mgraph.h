#include <vector>
#include <iostream>
#ifndef _POINT_H
#define _POINT_H
class Point
{
public:
    int x; int y;
    Point(int x, int y)
    {
        this->x = x; this->y = y;
    }
    Point()
    {
        this->x = this->y = 0;
    }
    friend std::ostream &operator<<(std::ostream& out, Point& onepoint)
    {
        out << "[" << onepoint.x << ", " << onepoint.y << "]";
        return out;
    }
    Point& operator=(const Point& p)
    {
        x = p.x; y = p.y;
        return *this;
    }
    bool operator==(const Point& p)
    {
        if (x == p.x && y == p.y)
            return true;
        return false;
    }
    Point(const Point &p)
    {
        this->x = p.x; this->y = p.y;
    }
};
#endif

#ifndef _EDGE_H
#define _EDGE_H
struct Edge
{
    Point adjvex;
    int lowcost;
};
#endif

#ifndef _MGRAPH_H
#define _MGRAPH_H

class MGraph
{
private: 
    int vexnum;
    std::vector<Point> vexs;
    std::vector<std::vector<int>> edges;
    int MiniNum(Edge *miniegdes);
public:
    MGraph(std::vector<Point> &v);
    Point GetVexValue(int v);
    int GetEdgeValue(int v, int i);
    ~MGraph();
    int Prim(int v, std::vector<std::pair<Point, Point>>&);
    int Prim(int v);
};

#endif