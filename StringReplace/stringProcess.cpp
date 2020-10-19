#include <iostream>
#include <cstring>
using namespace std;
const int MAXSIZE = 500;
void BFmatchAndReplace(char *s, char *t, char *p);
void test();
int main()
{
    test();
    return 0;
}
void test()
{
    char s[MAXSIZE], t[MAXSIZE], p[MAXSIZE];
    while (1)
    {
        cout << "Input string s: " << endl;
        gets(s);
        cout << "Input string t: " << endl;
        gets(t);
        cout << "Input string p: " << endl;
        gets(p);
        cout << "替换后的字符串: " << endl;
        BFmatchAndReplace(s, t, p);
        cout << s << endl;
    }
}
void BFmatchAndReplace(char *s, char *t, char *p)
{
    int i = 0, j = 0, k = 0, index = -1;
    int s_len = strlen(s), t_len = strlen(t), p_len = strlen(p);
    int gap = t_len - p_len;
    while (i < s_len)
    {
        while (i < s_len && j < t_len)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
                if (i >= s_len)
                    return;
            }
        }
        index = i - j;
        if (gap == 0)
        {
            for (k = 0; k < p_len; ++k)
                s[index + k] = p[k];
        }
        else if (gap > 0)
        {
            for (k = 0; k < p_len; ++k)
                s[index + k] = p[k];
            for (k = index + p_len; k < s_len - gap; ++k)
                s[k] = s[k + gap];
            s[k] = '\0';
        }
        else
        {
            for (k = s_len - gap; k > index; --k)
                s[k - gap] = s[k];
            s_len = strlen(s);
            if (s_len > MAXSIZE)
            {
                cerr << "上溢" << endl;
                exit(1);
            }
            s[s_len] = '\0';
            for (k = 0; k < p_len; ++k)
                s[k + index] = p[k];
        }
        j = 0;
    }
}