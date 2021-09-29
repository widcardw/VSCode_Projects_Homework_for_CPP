#include <iostream>
#include <cstring>
using namespace std;
void getNext(char *t, int next[])
{
    int j = 0, k = -1;
    int m = strlen(t);
    next[0] = -1;
    while (j < m - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
            k = next[k];
    }
}
//  a   b   c   a   b   b   c
//  -1  0   0   0   1   2   0ニャンコ先生
int KMPMatching(char *s, char *t)
{
    int i = 0, j = 0, n = strlen(s), m = strlen(t);
    int next[100];
    getNext(t, next);
    while (i < n && j < m)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= m)
        return i - m;
    else
        return -1;
}
int main()
{
    char a[100], b[100];
    cout << "Input source string:" << endl;
    gets(a);
    cout << "Input target string:" << endl;
    gets(b);
    cout << KMPMatching(a, b) << endl;
    return 0;
}