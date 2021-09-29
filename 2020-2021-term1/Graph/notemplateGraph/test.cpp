#include <iostream>
#include "MGraph.cpp"

void test1()
{
    int n, e;
    GraphType t = undinetwork;
    std::cout << "Input vexnum and edgenum: ";
    std::cin >> n >> e;
    std::cout << "Input vex value:\n";
    int *v = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    MGraph gr(t, v, n, e);
    gr.PrintVexs();
    gr.PrintEdges();
    delete[] v;
}
int main()
{
    test1();
    return 0;
}