#include "huffman.h"
#include <iomanip>
HuffmanTree::HuffmanTree(std::vector<HuffmanNode> &leafs)
{
    int i;
    n = leafs.size();
    int less = 0x80000000, least = 0x80000000;
    hufftree.resize(2 * n - 1);
    for (i = 0; i < n; ++i)
    {
        hufftree.at(i).data = leafs.at(i).data;
        hufftree.at(i).weight = leafs.at(i).weight;
        hufftree.at(i).parent = hufftree.at(i).lchild = hufftree.at(i).rchild = -1;
    }
    for (i = n; i < 2 * n - 1; ++i)
    {
        SelectSmall(least, less, i);
        hufftree.at(least).parent = i;
        hufftree.at(less).parent = i;
        hufftree.at(i).parent = -1;
        hufftree.at(i).lchild = least;
        hufftree.at(i).rchild = less;
        hufftree.at(i).weight = hufftree.at(least).weight + hufftree.at(less).weight;
    }
}
void HuffmanTree::SelectSmall(int &least, int &less, int i)
{
    int k, temp_least = least, temp_less = less;
    least = less = 0;
    for (k = 0; k < i; ++k)
    {
        while (hufftree.at(least).parent != -1)
            ++least;
        if (hufftree.at(k).parent != -1)
            continue;
        else if (hufftree.at(k).weight < hufftree.at(least).weight)
        {
            least = k;
            // std::cout << "get least" << std::endl;
        }
    }
    for (k = 0; k < i; ++k)
    {
        while (hufftree.at(less).parent != -1 || less == least)
            ++less;
        if (hufftree.at(k).parent != -1 || k == least)
            continue;
        if (hufftree.at(k).weight < hufftree.at(less).weight)
        {
            less = k;
            // std::cout << "get less" << std::endl;
        }
    }

    // std::cout << "least=" << least << ",less=" << less << std::endl;
}
HuffmanTree::~HuffmanTree()
{
    hufftree.clear();
    n = 0;
}
bool HuffmanTree::GetCode(int i, std::vector<int> &code)
{
    int p = i;                          //结点下标
    int parent = hufftree.at(i).parent; //当前结点的父节点下标
    code.clear();
    while (parent != -1)
    {
        if (hufftree.at(parent).lchild == p)
            code.insert(code.begin(), 0); //如果p是parent的左孩子,则在头部插入0
        else
            code.insert(code.begin(), 1);    //如果p是parent的右孩子,则在头部插入1
        p = parent;                          //当前节点变为它的父节点
        parent = hufftree.at(parent).parent; //父节点变为它自己的父节点,上溯
    }
    return true;
}
std::string HuffmanTree::Decode(std::vector<int> &source)
{
    std::string target = "";
    int root = hufftree.size() - 1; //根节点下标
    int p = root, i;
    for (i = 0; i < source.size(); ++i)
    {
        if (source.at(i) == 0)
            p = hufftree.at(p).lchild;
        else
            p = hufftree.at(p).rchild;
        if (hufftree.at(p).lchild == -1 && hufftree.at(p).rchild == -1)
        {
            target = target + hufftree.at(p).data;
            p = root;
            // std::cout << target << std::endl;
        }
    }
    return target;
}
void HuffmanTree::Get(int i)
{
    std::vector<int> code;
    this->GetCode(i, code);
    std::cout << std::setw(5) << hufftree.at(i).data << std::setw(5) << hufftree.at(i).weight << std::setw(5)
              << hufftree.at(i).lchild << std::setw(5) << hufftree.at(i).rchild << std::setw(5)
              << hufftree.at(i).parent << "  ";
    for (int j = 0; j < code.size(); ++j)
        std::cout << code.at(j);
    std::cout << std::endl;
}