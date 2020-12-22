#include "BiTree.cpp"
#include <vector>
#include <fstream>
void cinInput()
{
    int n = 5;
    int input = 0;
    int elem;
    std::cout << "Input TreeNode Number:";
    std::cin >> n;
    std::vector<int> v1, v2;
    std::cout << "Input PreOrder:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> input;
        v1.push_back(input);
    }
    std::cout << "Input InOrder:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> input;
        v2.push_back(input);
    }
    BiTree<int> tree(v1, v2);
    // std::cout << std::endl;
    // tree.PreOrder();
    // std::cout << std::endl;
    // tree.InOrder();
    // std::cout << std::endl;
    std::cout << "PostOrder:" << std::endl;
    tree.PostOrder();
    std::cout << "LevelOrder" << std::endl;
    tree.LevelOrder();
    std::cout << std::endl;
    std::cout << "Height:" << tree.Height() << std::endl;
    std::cout << "Count:" << tree.Count() << std::endl;
    std::cout << "Input element you want to search:";
    std::cin >> elem;
    BiNode<int> *tar = tree.Search(elem);
    BiNode<int> *par = tree.SearchParent(tar);
    std::cout << "Parent node element value:" << par->data << std::endl;
}
void finInput()
{
    int n = 5, i;
    char input = 0;
    char elem;
    std::ifstream fin;
    BiNode<char> *tar = NULL, *par = NULL;
    fin.open("data.txt");
    if (!fin)
    {
        exit(-1);
    }
    fin >> n;
    std::vector<char> v1, v2;
    for (i = 0; i < n; ++i)
    {
        fin >> input;
        v1.push_back(input);
    }
    for (i = 0; i < n; ++i)
    {
        fin >> input;
        v2.push_back(input);
    }
    fin.close();
    BiTree<char> tree1(v1, v2);
    std::cout << "PreOrder: " << std::endl;
    tree1.PreOrder();
    std::cout << "\n\nInOrder: " << std::endl;
    tree1.InOrder();
    std::cout << "\n\nPostOrder:" << std::endl;
    tree1.PostOrder();
    std::cout << "\n\nLevelOrder: " << std::endl;
    tree1.LevelOrder();
    std::cout << std::endl;
    std::cout << "\nHeight:" << tree1.Height() << std::endl;
    std::cout << "Count:" << tree1.Count() << std::endl;
    while (true)
    {
        std::cout << "Input element you want to search:";
        std::cin >> elem;
        tar = tree1.Search(elem);
        if (tar)
        {
            par = tree1.SearchParent(tar);
            if (par != NULL)
                std::cout << "Parent node element value:" << par->data << std::endl;
            else
                std::cout << "This is the root node." << std::endl;
        }
        else
        {
            std::cout << "Cannot find target node!" << std::endl;
        }
    }
}
int main()
{
    finInput();
    return 0;
}