#include <iostream>
#include <vector>
#include <string>
struct HuffmanNode
{
    char data;
    double weight;
    int parent, lchild, rchild;

    bool operator==(const char c)
    {
        return (this->data == c);
    }
};
class HuffmanTree
{
private:
    std::vector<HuffmanNode> hufftree;
    int n;
    void SelectSmall(int &least, int &less, int i);

public:
    HuffmanTree(std::vector<HuffmanNode> &leafs); //构造
    ~HuffmanTree();                               //析构
    bool GetCode(int i, std::vector<int> &code);  //编码
    std::string Decode(std::vector<int> &source); //解码
    void Get(int i);
};