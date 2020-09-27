#include <iostream>
#include "SeqList.h"
#include "SeqList.cpp"
#include "LinkList.h"
#include "LinkList.cpp"
#include <algorithm>
using namespace std;
// void test();
// void testMerge();
void chooseScene();
// void testLink();
template <class T, int MaxSize>
void gnrtRandLstFunc()
{
    int len1, len2;
    cout << "请输入两个数组长度: ";
    cin >> len1 >> len2;
    if (len1 <= 0 || len1 > MaxSize || len2 <= 0 || len2 > MaxSize || len1 + len2 > MaxSize)
    {
        cerr << "数组长度不合法!" << endl;
        exit(1);
    }
    const int l1 = len1;
    const int l2 = len2;
    int a[l1], b[l2];
    for (int i = 0; i < l1; ++i)
        a[i] = rand() % 100;
    for (int i = 0; i < l2; ++i)
        b[i] = rand() % 100;
    SeqList<int, MaxSize> lst1(a, l1);
    SeqList<int, MaxSize> lst2(b, l2);
    lst1.Sort();
    lst2.Sort();
    cout << "这是第一个数组: " << endl;
    lst1.PrintSeqList();
    cout << "这是第二个数组: " << endl;
    lst2.PrintSeqList();
    SeqList<int, MaxSize> lst3 = mergeTwoSortedList(lst1, lst2);
    cout << "这是归并后的数组: " << endl;
    lst3.PrintSeqList();
}
template <class T, int MaxSize>
void typeInLstFunc()
{
    int len1, len2;
    cout << "请输入两个数组的长度: ";
    cin >> len1 >> len2;
    if (len1 <= 0 || len1 > MaxSize || len2 <= 0 || len2 > MaxSize || len1 + len2 > MaxSize)
    {
        cerr << "数组长度不合法!" << endl;
        exit(1);
    }
    const int l1 = len1;
    const int l2 = len2;
    int a[l1], b[l2];
    cout << "请输入第一个数组: " << endl;
    for (int i = 0; i < l1; ++i)
        cin >> a[i];
    cout << "请输入第二个数组: " << endl;
    for (int i = 0; i < l2; ++i)
        cin >> b[i];
    SeqList<int, MaxSize> lst1(a, l1);
    SeqList<int, MaxSize> lst2(b, l2);
    cout << "为保证输入的数组都有序, 先将这些数组排了序" << endl;
    lst1.Sort();
    lst2.Sort();
    SeqList<int, MaxSize> lst3 = mergeTwoSortedList(lst1, lst2);
    cout << "这是归并后的数组: " << endl;
    lst3.PrintSeqList();
}
template <class T>
void gnrtRandLinkListFunc()
{
    int len1, len2;
    cout << "请输入两个链表的长度: ";
    cin >> len1 >> len2;
    const int l1 = len1;
    const int l2 = len2;
    int a[l1], b[l2], i;
    for (i = 0; i < l1; ++i)
        a[i] = rand() % 100;
    for (i = 0; i < l2; ++i)
        b[i] = rand() % 100;
    sort(a, a + l1);
    sort(b, b + l2);
    LinkList<int> lst1(a, l1);
    LinkList<int> lst2(b, l2);
    cout << "这是第一个链表: " << endl;
    lst1.PrintLinkList();
    cout << "这是第二个链表: " << endl;
    lst2.PrintLinkList();
    Merge(lst1, lst2);
    cout << "这是归并后的链表: " << endl;
    lst1.PrintLinkList();
}
template <class T>
void inputLinkListFunc()
{
    int len1, len2;
    cout << "请输入两个链表的长度: ";
    cin >> len1 >> len2;
    const int l1 = len1;
    const int l2 = len2;
    int a[l1], b[l2], i;
    cout << "请输入第一个数组: " << endl;
    for (i = 0; i < l1; ++i)
        cin >> a[i];
    cout << "请输入第二个数组: " << endl;
    for (i = 0; i < l2; ++i)
        cin >> b[i];
    cout << "为保证输入的链表都有序, 先将这些链表排了序" << endl;
    sort(a, a + l1);
    sort(b, b + l2);
    LinkList<int> lst1(a, l1);
    LinkList<int> lst2(b, l2);
    Merge(lst1, lst2);
    cout << "这是归并后的链表: " << endl;
    lst1.PrintLinkList();
}
int main()
{
    // test();
    // testMerge();
    chooseScene();
    // testLink();
    return 0;
}
// void testLink()
// {
//     const int len1 = 10;
//     int a[len1] = {0}, i;
//     for (i = 0; i < len1; ++i)
//         a[i] = rand() % 100;
//     LinkList<int> lst(a, len1);
//     lst.Sort();
//     cout << "这是第一个链表" << endl;
//     lst.PrintLinkList();
//     int b[len1] = {0};
//     for (i = 0; i < len1; ++i)
//         b[i] = rand() % 100;
//     LinkList<int> lst2(b, len1);
//     lst2.Sort();
//     cout << "这是第二个链表" << endl;
//     lst2.PrintLinkList();
//     Merge(lst, lst2);
//     cout << "这是归并后的链表" << endl;
//     lst.PrintLinkList();
// }
// void test()
// {
//     const int num = 100;
//     const int len = 50;
//     int a[len] = {0};
//     // for (int i = 0; i < len; ++i)
//     //     cin >> a[i];
//     for (int i = 0; i < len; ++i)
//         a[i] = rand() % 100;
//     SeqList<int, num> lst(a, len);
//     lst.PrintSeqList();
//     lst.Insert(2, 10);
//     lst.PrintSeqList();
//     lst.Delete(1);
//     lst.PrintSeqList();
//     lst.Sort();
//     lst.PrintSeqList();
// }
// void testMerge()
// {
//     const int num = 100;
//     const int len = 20;
//     int a[len] = {0};
//     for (int i = 0; i < len; ++i)
//         a[i] = rand() % 100;
//     SeqList<int, num> lst1(a, len);
//     lst1.Sort();
//     lst1.PrintSeqList();
//     int b[len] = {0};
//     for (int i = 0; i < len; ++i)
//         b[i] = rand() % 100;
//     SeqList<int, num> lst2(b, len);
//     lst2.Sort();
//     lst2.PrintSeqList();
//     SeqList<int, num> lst3 = mergeTwoSortedList(lst1, lst2);
//     lst3.PrintSeqList();
// }
void chooseScene()
{
    const int MaxSize = 100;
    while (1)
    {
        system("cls");
        char ch;
        cout << "| 1. 生成随机有序数组      |" << endl;
        cout << "| 2. 键盘输入有序数组      |" << endl;
        cout << "| 3. 生成随机有序链表      |" << endl;
        cout << "| 4. 键盘输入有序链表      |" << endl;
        cout << "| 5. 退出                  |" << endl;
        cout << "请选择: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            gnrtRandLstFunc<int, MaxSize>();
            system("pause");
            break;
        case '2':
            typeInLstFunc<int, MaxSize>();
            system("pause");
            break;
        case '3':
            gnrtRandLinkListFunc<int>();
            system("pause");
            break;
        case '4':
            inputLinkListFunc<int>();
            system("pause");
            break;
        default:
            exit(0);
        }
    }
}