#include <iostream>
#include <fstream>
#include <vector>
#include "mgraph.cpp"
#include "mgraph.h"
// 获取 9 个点，长度只能是 9
void getPoints(std::vector<Point>& arr)
{
    std::ifstream fin;
    int x, y;
    int n = 9;
    arr.resize(9);
    fin.open("C:\\Users\\row31976300\\Documents\\VSCode_Projects_Homework_for_CPP\\MathGraph\\points.txt");
    for (int i = 0; i < n; i++)
    {
        fin >> x; fin >> y;
        arr[i].x = x; arr[i].y = y;
    }
    fin.close();
}
// 读取文件，将得到的点直接 push 进入 vector 中
void getPoints2(std::vector<Point> &arr)
{
    std::ifstream fin;
    int x, y;
    arr.clear();
    fin.open("C:\\Users\\row31976300\\Documents\\VSCode_Projects_Homework_for_CPP\\MathGraph\\points2.txt");
    while (fin >> x)
    {
        fin >> y;
        arr.push_back(Point(x, y));
    }
    fin.close();
}
// 对 9 个基站建立最小生成树，结果为 229
void test(std::vector<Point>& arr)
{
    MGraph m = MGraph(arr);
    std::vector<std::pair<Point, Point>> vec;
    int length = m.Prim(0, vec);
    std::cout << length << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i).first << "-->" << vec.at(i).second << std::endl;
    }
}
// void test2(std::vector<Point>& arr)
// {
//     std::ofstream fout;
//     int min = 0x7fffffff;
//     fout.open("C:\\Users\\row31976300\\Documents\\VSCode_Projects_Homework_for_CPP\\MathGraph\\result.csv");
//     for (int i = 36; i < 86; i++)
//     {
//         for (int j = -23; j < 35; j++) 
//         {
//             arr[9] = Point(i, j);
//             MGraph m = MGraph(n + 1, arr);
//             std::vector<std::pair<Point, Point>> vec;
//             int length = m.Prim(0, vec);
//             if (min > length) min = length;
//             fout << i << "," << j << "," << length << "," << std::endl;
//             vec.clear();
//         }
//     }
//     fout.close();
//     std::cout << min << std::endl;
// }
// 判断某个点 t 是否在长度为 n 的 arr 中
bool pointInPoints(std::vector<Point>& arr, int n, Point t)
{
    for (int i = 0; i < n; i++)
    {
        if (t == arr[i]) 
            return true;
    }
    return false;
}
// 在一个矩形区域内逐个取点，将这 10 个点逐一建立最小生成树，路径长度存入文件
void test3(std::vector<Point>& arr)
{
    std::ofstream fout;
    int min = 0x7fffffff;
    fout.open("C:\\Users\\row31976300\\Documents\\VSCode_Projects_Homework_for_CPP\\MathGraph\\result.csv");
    for (int i = 20; i < 90; i++)
    {
        for (int j = -40; j < 40; j++)
        {
            arr.push_back(Point(i, j));
            if (!pointInPoints(arr, 9, arr[9]))
            {
                MGraph m = MGraph(arr);
                std::vector<std::pair<Point, Point>> vec;
                int length = m.Prim(0, vec);
                if (min > length) min = length;
                fout << i << "," << j << "," << length << "," << std::endl;
                vec.clear();
            }
            else 
            {
                fout << i << "," << j << "," << 260 << "," << std::endl;
            }
            arr.pop_back();
        }
    }
    fout.close();
}
 // 调用 test3
void test123()
{
    int n = 9; 
    std::vector<Point> arr;
    getPoints(arr);
    test3(arr);
}
// 选 4 个点建立最小生成树，最小路径 193
void test4()
{
    int n = 9;
    std::vector<Point> arr;
    getPoints(arr);
    arr.push_back(Point(50, 6));
    arr.push_back(Point(52, -23));
    arr.push_back(Point(52, -12));
    arr.push_back(Point(52, 5));
    // arr.push_back(Point(65, 16));
    MGraph m = MGraph(arr);
    std::vector<std::pair<Point, Point>> vec;
    int length = m.Prim(0, vec);
    std::cout << "Path Length = " << length << std::endl;
    for (int i = 0; i < vec.size(); i++) 
    {
        std::cout << vec.at(i).first << "-->" << vec.at(i).second << std::endl;
    }
}
// 25 个点建立最小生成树
void t2test()
{
    std::vector<Point> arr;
    getPoints2(arr);
    std::vector<std::pair<Point, Point>> vec;
    MGraph m = MGraph(arr);
    int length = m.Prim(0, vec);
    std::cout << length << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i].first << "-->" << vec[i].second << std::endl;
    }
}
// 选 2 个点建立最小生成树
void t2test2()
{
    std::vector<Point> arr;
    getPoints2(arr);
    std::vector<std::pair<Point, Point>> vec;
    // arr.push_back(Point(35, 38));
    arr.push_back(Point(34, 24));
    arr.push_back(Point(34, 12));
    MGraph m = MGraph(arr);
    int length = m.Prim(0, vec);
    std::cout << length << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i].first << "-->" << vec[i].second << std::endl;
    }
}

// 在矩形区域里面逐一取点建立最小生成树，存入文件
void t2gm()
{
    std::vector<Point> arr;
    getPoints2(arr);
    int min = 99999;
    std::ofstream fout;
    fout.open("C:\\Users\\row31976300\\Documents\\VSCode_Projects_Homework_for_CPP\\MathGraph\\result2.csv");
    for (int i = 0; i < 60; i++)
    {
        for (int j = -10; j < 60; j++)
        {
            arr.push_back(Point(i, j));
            if (!pointInPoints(arr, 25, arr[25]))
            {
                std::vector<std::pair<Point, Point>> vec;
                MGraph m = MGraph(arr);
                int length = m.Prim(0, vec);
                if (min > length) min = length;
                fout << i << "," << j << "," << length << "," << std::endl;
                vec.clear();
            }
            else 
            {
                fout << i << "," << j << "," << 240 << "," << std::endl;
            }
            arr.pop_back();
        }
    }
    fout.close();
    std::cout << min << std::endl;
}

int main()
{
    t2test2();
    // t2gm();
    return 0;
}