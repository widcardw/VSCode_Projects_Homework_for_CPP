// 用于测试 posible 中的点进行组合，加入到基站中
// 得到路径长度的最小值

#include <iostream>
#include "mgraph.cpp"
#include "mgraph.h"
#include <vector>

void get_combination(
    std::vector<Point>& vec,
    std::vector<Point>& bases,
    int begin, int len,
    std::vector<Point>& stack,
    int& min
);

// 可选的点，可以再加亿些点
void get_posible_points(std::vector<Point>& vec)
{
    vec.clear();
    vec.push_back(Point(36, 31));
    vec.push_back(Point(36, 16));
    vec.push_back(Point(50, 6));
    vec.push_back(Point(50, 16));
    vec.push_back(Point(52, 16));
    vec.push_back(Point(52, 15));
    vec.push_back(Point(52, 5));
    vec.push_back(Point(36, 6));
    vec.push_back(Point(36, 5));
    vec.push_back(Point(35, 5));
    vec.push_back(Point(35, 6));
    vec.push_back(Point(35, -9));
    vec.push_back(Point(35, -12));
    vec.push_back(Point(52, -12));
    vec.push_back(Point(52, -23));
    vec.push_back(Point(57, -23));
    vec.push_back(Point(57, -12));
    vec.push_back(Point(57, -9));
    vec.push_back(Point(57, 5));
    vec.push_back(Point(52, -34));
    vec.push_back(Point(65, -9));
    vec.push_back(Point(65, 16));
    vec.push_back(Point(68, 5));
}

// 原本的 9 个点
void get_bases(std::vector<Point>& bases)
{
    bases.clear();
    bases.push_back(Point(36, 35));
    bases.push_back(Point(50, 31));
    bases.push_back(Point(68, 16));
    bases.push_back(Point(65, 5));
    bases.push_back(Point(86, -12));
    bases.push_back(Point(52, -9));
    bases.push_back(Point(57, -34));
    bases.push_back(Point(35, -23));
    bases.push_back(Point(25, 6));
}

void try_points(std::vector<Point>& vec, std::vector<Point>& bases, int num)
{
    int min = 9999;
    std::vector<Point> stack;
    get_combination(vec, bases, 0, num, stack, min);
    std::cout << min << std::endl;
}

void get_combination(
    std::vector<Point>& vec,
    std::vector<Point>& bases,
    int begin, int len,
    std::vector<Point>& stack,
    int& min
) {
    if (len == 0) 
    {
        for (auto it = stack.begin(); it != stack.end(); it++)
            bases.push_back(*it);

        MGraph m = MGraph(bases);
        int length = m.Prim(0);
        if (min > length) min = length;
        // 找目前最小的路径
        if (length == 190) 
        {
            std::cout << length << std::endl;
            std::vector<std::pair<Point, Point>> vv;
            m.Prim(0, vv);
            for (int k = 0; k < vv.size(); k++)
            {
                std::cout << vv[k].first << "-->" << vv[k].second << std::endl;
            }
        }

        for (int i = 0; i < stack.size(); i++)
            bases.pop_back();
        return;
    }
    if (begin >= vec.size())
    {
        return;
    }
    stack.push_back(vec.at(begin));
    get_combination(vec, bases, begin + 1, len - 1, stack, min);
    stack.pop_back();
    get_combination(vec, bases, begin + 1, len, stack, min);
}

int main()
{
    std::vector<Point> vec;
    std::vector<Point> bases;
    get_posible_points(vec);
    get_bases(bases);
    // 在备选通讯站中选出 5 个
    try_points(vec, bases, 5);
    return 0;
}