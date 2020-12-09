#include <iostream>
#include <fstream>
// #include "mgraph.h"
#include "mgraph.cpp"
// #include "algraph.h"
#include "algraph.cpp"
// #include "SeqQueue.h"
// #include "SeqQueue.cpp"
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
    MGraph<int> gr(t, v, n, e);
    delete[] v;
    gr.PrintVexs();
    gr.PrintEdges();
    std::cout << std::endl;
    gr.DFSTraverse();
    std::cout << std::endl;
    gr.BFSTraverse();
}
void test2()
{
    std::ifstream fin;
    fin.open("graph.txt");
    int n, e;
    GraphType t = dinetwork;
    fin >> n >> e;
    char *v = new char[n];
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    MGraph<char> gr(t, v, n, e);
    fin.close();
    gr.PrintVexs();
    gr.PrintEdges();
    std::cout << std::endl;
    std::cout << "DFS: ";
    int count = gr.DFSTraverse();
    std::cout << '\n'
              << count << "\nBFS: ";
    count = gr.BFSTraverse();
    std::cout << '\n'
              << count << std::endl;
    gr.Prim(0);
    gr.TopoSort();
    delete[] v;
}
void test3()
{
    std::ifstream fin;
    fin.open("graph.txt");
    int n, e;
    GraphType t = digraph;
    fin >> n >> e;
    char *v = new char[n];
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    fin.close();
    ALGraph<char> gr(t, v, n, e);
    // gr.PrintVexs();
    // gr.PrintEdges();
    std::cout << std::endl;
    std::cout << "DFS: ";
    int count = gr.DFSTraverse();
    std::cout << '\n'
              << count << "\nBFS: ";
    count = gr.BFSTraverse();
    std::cout << '\n'
              << count << std::endl;
    delete[] v;
    gr.PrintVexs();
    gr.PrintEdges();
    std::cout << "End" << std::endl;
}
int main()
{
    test2();
    return 0;
}