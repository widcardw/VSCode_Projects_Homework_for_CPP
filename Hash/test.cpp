#include <iostream>
#include "hashmap.h"
#include "binary.h"
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>

void testHash()
{
    FILE *fin;
    fin = fopen("aviobuf.c", "r");
    assert(fin);
    HashMap hlist;
    hlist.CreateHashMapFromFile(fin);
    hlist.PrintList(std::cout);
    std::cout << "总查找长度: " << hlist.CalSearchLen() << std::endl;
    fclose(fin);
}

void testBin()
{
    FILE *fin;
    fin = fopen("aviobuf.c", "r");
    assert(fin);
    BinMap blist;
    blist.CreateMapFromFile(fin);
    blist.PrintList(std::cout);
    std::cout << "总查找长度: " << blist.CalSearchLen() << std::endl;
    fclose(fin);
}

int main()
{
    std::cout << "Hash查找: " << std::endl;
    testHash();
    std::cout << "\n二分查找" << std::endl;
    testBin();
    return 0;
}