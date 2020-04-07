/*
7������һ������������ 100 �����������ı��ļ� data.txt����������¹��ܣ�
(1)��дһ�����������ļ��ж�ȡ������������
(2)�� main �����������������������ʽҪ��ÿ����� 8 ��������ÿ������ռ 5 �С�
(3)��дһ��������ɾ�������������а������� 2 �� 4 ���������� main �������������
ʣ��������������ʽ��(2)��ͬ��
(4)��дһ����������(3)�е���������������ı��ļ� result.txt �У���ʽ���������Ļ
�ĸ�ʽ��ͬ��
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