/*
7．创建一个包含不超过 100 个整型数的文本文件 data.txt，试完成如下功能：
(1)编写一个函数，从文件中读取所有整型数。
(2)在 main 函数中输出所有整型数。格式要求每行输出 8 个整数，每个整数占 5 列。
(3)编写一个函数，删除所有整型数中包含数字 2 和 4 的整数。在 main 函数中输出所有
剩余的整数，输出格式与(2)相同。
(4)编写一个函数，将(3)中的所有整数输出到文本文件 result.txt 中，格式与输出到屏幕
的格式相同。
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
void read_int(int *parr, ifstream &fin, int *count)
{
    string line;
    int i = 0;
    while (getline(fin, line))
    {
        stringstream ss(line);
        while (ss >> *(parr + i))
            i++;
    }
    *count = i;
}
void print(int *parr, int count, int num)
{
    for (int i = 0; i < count; i++)
    {
        cout << setw(5) << *(parr + i);
        if ((i + 1) % num == 0)
            cout << "\n";
    }
    cout << "\n";
}
void delete_2_4(int *parr, int *count)
{
    string ar;
    for (int i = 0; i < *count; i++)
    {
        ar = to_string(*(parr + i));
        //cout << ar << endl;
        if (ar.find('2') != ar.npos || ar.find('4') != ar.npos)
        {
            for (int j = i; j < *count; j++)
                *(parr + j) = *(parr + j + 1);
            *count -= 1;
            i--;
        }
        //cout << "count=" << *count << endl;
    }
}
void output_int(int *parr, ofstream &fou, int *count, int num)
{
    for (int i = 0; i < *count; i++)
    {
        fou << setw(5) << *(parr + i);
        if ((i + 1) % num == 0)
            fou << "\n";
    }
    cout << "\n";
}
int main()
{
    int arr[100];
    int count = 0;
    ifstream fin("data.txt");
    if (!fin)
    {
        cout << "Cannot open the file!" << endl;
        exit(0);
    }
    read_int(arr, fin, &count);
    //cout << count << endl;
    print(arr, count, 8);
    delete_2_4(arr, &count);
    print(arr, count, 8);
    ofstream fou("result.txt");
    if (!fou)
    {
        cout << "Cannot open the file!" << endl;
        exit(0);
    }
    output_int(arr, fou, &count, 8);
    fin.close();
    fou.close();
    return 0;
}