#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
using namespace std;
class string1
{
private:
    char *str;
    int len;

public:
    string1(char *myx)
    {
        assert(myx); //先判断这个指针是否为空
        if (!myx)
        {
            len = 0;
            str = new char[1]; //如果指针为空，则new一个内存空间
            *str = '\0';
        }
        else
        {
            len = strlen(myx);
            str = new char[len + 1]; //用new申请一个内存空间
            assert(str);             //判断内存是否申请成功
            strcpy(str, myx);        //将形参的内容复制给str
        }
    }
    string1(string1 &myx)
    {
        len = myx.len;
        str = new char[myx.len + 1];
        assert(str);
        strcpy(str, myx.str);
    }
    void getnext(int next[])
    {
        int j = 0;
        int k = -1;
        next[0] = -1;
        while (j < len - 1)
        {
            if (k == -1 || str[j] == str[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
                k = next[k];
        }
    }

    int KMPmatching(string1 str2)
    {
        int i = 0;
        int j = 0;
        int m = len;
        int next[100];
        str2.getnext(next);
        while (i < len && j < m)
        {
            if (j == -1 || str2.str[i] == str[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j >= m)
            return 1;
        else
            return 0;
    }
};
int main()
{
    while (1)
    {
        char *a = new char[100], *b = new char[100];
        cout << "请输入字符串：\n";
        scanf("%s", a);
        cout << "请输入字串：";
        scanf("%s", b);
        string1 a1(a), b1(b);
        if (a1.KMPmatching(b1))
            printf("success");
        else
            printf("defeat");
        return 0;
    }
}