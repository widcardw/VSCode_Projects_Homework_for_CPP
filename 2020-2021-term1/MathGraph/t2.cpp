#include <iostream>
#include "mgraph.cpp"
#include "mgraph.h"
#include <vector>
#include <cstdlib>
#include <fstream>

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

int try_2_points(
    std::vector<Point>& bases, 
    int x_min, int x_max,
    int y_min, int y_max
) {
    if (x_min >= x_max || y_min >= y_max) return 9999;
    int min = 9999;
    for (int i = x_min; i < x_max; i++) 
    {
        for (int j = y_min; j < y_max; j++) 
        {
            bases.push_back(Point(i, j));
            for (int m = i + 1; m < x_max; m++)
            {
                for (int n = j + 1; n < y_max; n++)
                {
                    bases.push_back(Point(m, n));
                    for (int v = m + 1; v < x_max; v++) 
                    {
                        for (int w = n + 1; w < y_max; w++) 
                        {
                            bases.push_back(Point(v, w));
                            MGraph jm = MGraph(bases);
                            int length = jm.Prim(0);
                            // std::cout << length << std::endl;
                            if (min > length) 
                            {
                                min = length;
                                std::cout << min << std::endl;
                            }
                            bases.pop_back();
                        }
                    }
                    bases.pop_back();
                }
            }
            bases.pop_back();
        }
    }
    return min;
}

void test()
{
    std::vector<Point> bases;
    getPoints2(bases);
    for (int i = 0; i < bases.size(); i++)
    {
        std::cout << bases[i] << std::endl;
    }
    int min = try_2_points(bases, 0, 60, 0, 60);
    std::cout << min << std::endl;
}

int main()
{
    test();
    return 0;
}