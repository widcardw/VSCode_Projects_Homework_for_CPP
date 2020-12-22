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
    MGraph<int> gr(t, v, n, e, std::cin);
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
    GraphType t = undinetwork;
    fin >> n >> e;
    char *v = new char[n];
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    MGraph<char> gr(t, v, n, e, fin);
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
    ALGraph<char> gr(t, v, n, e, fin);
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
void test4()
{
    std::ifstream fin;
    fin.open("graph.txt");
    int n, e;
    fin >> n >> e;
    char *v = new char[n + 1];
    for (int i = 0; i < n; ++i)
        fin >> v[i];

    MGraph<char> mundigr(undigraph, v, n, e, fin);
    std::cout << std::endl;
    mundigr.PrintEdges();
    std::cout << "\nDFS: ";
    int count = mundigr.DFSTraverse();
    std::cout << "\ntree nums: " << count << std::endl;
    std::cout << "BFS: ";
    count = mundigr.BFSTraverse();
    std::cout << "\ntree nums: " << count << std::endl;
    std::cout << "Prim:" << std::endl;
    mundigr.Prim(0);
    //std::cout << "TopoSort: ";
    //mundigr.TopoSort();
    fin.close();

    fin.open("network.txt");
    fin >> n >> e;
    for (int i = 0; i < n; ++i)
        fin >> v[i];

    MGraph<char> mundinw(dinetwork, v, n, e, fin);
    std::cout << std::endl;
    mundinw.PrintEdges();
    std::cout << "DFS: ";
    count = mundinw.DFSTraverse();
    std::cout << "\ntree nums: " << count << std::endl;
    std::cout << "BFS: ";
    count = mundinw.BFSTraverse();
    std::cout << "\ntree nums: " << count << std::endl;
    // std::cout << "Prim:" << std::endl;
    // mundinw.Prim(0);
    std::cout << "TopoSort: ";
    mundinw.TopoSort();
    std::cout << "\nPrim: " << std::endl;
    mundinw.Prim(0);
    std::cout << "Dijkstra shortest path: " << std::endl;
    int *path = new int[n];
    float *dist = new float[n];
    mundinw.Dijkstra(0, path, dist);
    PrintPath(mundinw, path, dist, 0);
    fin.close();
    delete[] v;
    delete[] path;
    delete[] dist;
}
int main()
{
    test4();
    return 0;
}