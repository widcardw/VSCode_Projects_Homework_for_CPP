/*
5��ʹ�� string �����������ɵ��ʣ���������¹��ܣ�
(1)�����ֵ�˳������е��ʴ�С�������򣬲��� main ������������������е��ʣ�
Ҫ��һ������һ�С�
(2)���ݵ��ʳ��ȶ����е��ʴ�С�������򣬲��� main ������������������е��ʣ�
Ҫ��һ������һ�С�
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