#include <iostream>
#include "hashmap.h"
#include "binary.h"
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>

void testHash(std::string filename)
{
    FILE *fin;
    fin = fopen(filename.data(), "r");
    assert(fin);
    HashMap hlist;
    hlist.CreateHashMapFromFile(fin);
    hlist.PrintList(std::cout);
    std::cout << "总查找长度: " << hlist.CalSearchLen() << std::endl;
    fclose(fin);
}

void testBin(std::string filename)
{
    FILE *fin;
    fin = fopen(filename.data(), "r");
    assert(fin);
    BinMap blist;
    blist.CreateMapFromFile(fin);
    blist.PrintList(std::cout);
    std::cout << "总查找长度: " << blist.CalSearchLen() << std::endl;
    fclose(fin);
}

int main()
{
    std::string filename;
    int choice = 0;
    while(1) {
        std::cout << "请输入要查询的文件名：";
        std::cin >> filename;
        std::cout << "请输入你的选项：\n1.hash查找&二分查找\n2.退出\n请选择：";
        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Hash查找: " << std::endl;
                testHash(filename);
                std::cout << "\n二分查找" << std::endl;
                testBin(filename);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}