/*
5．使用 string 类型输入若干单词，试完成如下功能：
(1)按照字典顺序对所有单词从小到大排序，并在 main 函数中输出排序后的所有单词，
要求一个单词一行。
(2)根据单词长度对所有单词从小到大排序，并在 main 函数中输出排序后的所有单词，
要求一个单词一行。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void sort_by_dic(string *p, int cnt)
{
    sort(p, p + cnt);
}
void sort_by_len(string *p, int cnt)
{
    sort(p, p + cnt, [](string a, string b) { return a.length() < b.length(); });
}
void print(string *p, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        cout << *(p + i) << endl;
    }
}
int main()
{
    string s;
    getline(cin, s);
    int cnt = [](string s) {int a=0;for(int i=0;i<s.length();++i)if(s[i]==' ')a++;return a; }(s) + 1;
    string *p = new string[cnt];
    int a = 0, p_i = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            p[p_i] = s.substr(a, i - a);
            a = i + 1;
            p_i++;
        }
    }
    sort_by_dic(p, cnt);
    print(p, cnt);
    sort_by_len(p, cnt);
    print(p, cnt);
    return 0;
}