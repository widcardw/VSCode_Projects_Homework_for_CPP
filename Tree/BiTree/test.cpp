#include "BiTree.cpp"
#include <vector>
int main()
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
    return 0;
}