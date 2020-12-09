#include "huffman.h"
// #include "huffman.cpp"
#include <algorithm>
void test();
void test2();
void test3();
void sw();
int main()
{
    test3();
    return 0;
}
void sw(HuffmanTree tree1)
{
    std::vector<int> code;
    char c;
    int i, j;
    std::string ss;
    while (true)
    {
        std::cout << "1. GetCode\n2. DeCode\n3. Quit\nChoose: ";
        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            // code.clear();
            std::cout << "Input Data Index: ";
            std::cin >> j;
            tree1.GetCode(j, code);
            std::cout << "Code Length: " << code.size() << std::endl;
            std::cout << "Code: ";
            for (i = 0; i < code.size(); ++i)
                std::cout << code.at(i);
            std::cout << std::endl;
        }
        break;
        case 2:
        {
            ss.clear();
            code.clear();
            std::cout << "Input Code: ";
            std::cin >> ss;
            for (int k = 0; k < ss.length(); ++k)
            {
                c = ss.at(k);
                code.push_back(c - '0');
                // std::cout << "get" << std::endl;
            }
            ss.clear();
            ss = tree1.Decode(code);
            std::cout << ss << std::endl;
        }
        break;
        default:
            exit(0);
        }
    }
}
void test()
{
    char dat;
    double wei;
    std::vector<HuffmanNode> tr;
    int n, i, j;
    std::cout << "Input Leaf Num: ";
    std::cin >> n;
    tr.resize(n);
    for (i = 0; i < n; ++i)
    {
        std::cout << "Input data: ";
        std::cin >> dat;
        std::cout << "Input weight: ";
        std::cin >> wei;
        tr[i].data = dat;
        tr[i].weight = wei;
    }
    // std::cout << tr[1].data << std::endl;
    HuffmanTree tree1(tr);
    for (i = 0; i < 2 * n - 1; ++i)
        tree1.Get(i);
    std::vector<int> code;
    char c;
    std::string ss;
    while (true)
    {
        std::cout << "1. GetCode\n2. DeCode\nChoose: ";
        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            // code.clear();
            std::cout << "Input Data Index: ";
            std::cin >> j;
            tree1.GetCode(j, code);
            // std::copy(tree1.GetCode(j).begin(), tree1.GetCode(j).end(), code.begin());
            std::cout << code.size() << std::endl;
            for (i = 0; i < code.size(); ++i)
                std::cout << code.at(i);
            std::cout << std::endl;
        }
        break;
        case 2:
        {
            ss.clear();
            code.clear();
            std::cout << "Input Code: ";
            std::cin >> ss;
            for (int k = 0; k < ss.length(); ++k)
            {
                c = ss.at(k);
                code.push_back(c - '0');
                // std::cout << "get" << std::endl;
            }
            ss.clear();
            ss = tree1.Decode(code);
            std::cout << ss << std::endl;
        }
        break;
        default:
            exit(0);
        }
    }
}
void test2()
{
    std::vector<HuffmanNode> tr;
    tr.resize(7);
    tr[0] = {'A', 12};
    tr[1] = {'B', 23};
    tr[2] = {'C', 34};
    tr[3] = {'D', 45};
    tr[4] = {'E', 56};
    tr[5] = {'F', 78};
    tr[6] = {'G', 111};
    std::vector<int> code;
    char c;
    std::string ss;
    int i, j;
    HuffmanTree tree1(tr);
    while (true)
    {
        std::cout << "1. GetCode\n2. DeCode\nChoose: ";
        std::cin >> i;
        switch (i)
        {
        case 1:
        {
            // code.clear();
            std::cout << "Input Data Index: ";
            std::cin >> j;
            tree1.GetCode(j, code);
            // std::copy(tree1.GetCode(j).begin(), tree1.GetCode(j).end(), code.begin());
            // std::cout << code.size() << std::endl;
            for (i = 0; i < code.size(); ++i)
                std::cout << code.at(i);
            std::cout << std::endl;
        }
        break;
        case 2:
        {
            ss.clear();
            code.clear();
            std::cout << "Input Code: ";
            std::cin >> ss;
            for (int k = 0; k < ss.length(); ++k)
            {
                c = ss.at(k);
                code.push_back(c - '0');
                // std::cout << "get" << std::endl;
            }
            ss.clear();
            ss = tree1.Decode(code);
            std::cout << ss << std::endl;
        }
        break;
        default:
            exit(0);
        }
    }
}
void test3()
{
    std::string s1;
    std::vector<HuffmanNode> tr;
    std::vector<HuffmanNode>::iterator it;
    HuffmanNode node;
    std::cout << "Input data:" << std::endl;
    // std::cin >> s1;
    getline(std::cin, s1);
    int i;
    for (i = 0; i < s1.length(); ++i)
    {
        if (s1.at(i) == ' ')
            continue;
        node.data = s1.at(i);
        it = find(tr.begin(), tr.end(), node.data);
        if (it != tr.end())
            it->weight += 1;
        else
        {
            node.weight = 1;
            tr.push_back(node);
        }
    }
    HuffmanTree tree1(tr);
    for (i = 0; i < 2 * tr.size() - 1; ++i)
        tree1.Get(i);
    sw(tree1);
}
