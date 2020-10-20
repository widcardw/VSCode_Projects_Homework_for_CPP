#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;
class MyString
{
private:
    char *str;

public:
    MyString(const char *s)
    {
        if (s)
        {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else
            str = NULL;
    }
    ~MyString()
    {
        if (str)
            delete[] str;
    }
    char *StrCpy()
    {
        if (str)
        {
            char *newstr = new char[strlen(str) + 1];
            strcpy(newstr, str);
            return newstr;
        }
        else
            return NULL;
    }
    int Length() { return strlen(str); }
    int Subchar(const char *c)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] == *c)
                return i;
            i++;
        }
        return -1;
    }
    int StrCmp(const char *str1)
    {
        return strcmp(str, str1);
    }
    void print();
    char *StrCat(const char *s2)
    {
        char *newstr = new char[strlen(str) + strlen(s2) + 1];
        int i = 0;
        for (i = 0; i < strlen(str); i++)
            *(newstr + i) = *(str + i);
        for (int j = 0; j < strlen(s2); i++, j++)
            *(newstr + i) = *(s2 + j);
        *(newstr + i) = '\0';
        return newstr;
    }
    int SubStrLoc(const char *s)
    {
        int loc = -1, i = 0, j = 0;
        for (i = 0; i < strlen(str) - strlen(s); i++)
        {
            for (j = 0; j < strlen(s); j++)
            {
                if (str[i + j] != s[j])
                    break;
            }
            if (j == strlen(s))
            {
                loc = i;
                break;
            }
        }
        return loc;
    }
    char *SubStr(int start, int len)
    {
        if (start + len > strlen(str))
        {
            cout << "SubStr Error! Out of Range!" << endl;
            return NULL;
        }
        char *subs = new char[len + 1];
        int i = 0;
        for (i = 0; i < len; i++)
            *(subs + i) = *(str + start + i);
        *(subs + i) = '\0';
        return subs;
    }
};
void MyString::print()
{
    if (str != NULL)
        cout << str << endl;
    return;
}
void teststring()
{
    MyString s1("I love "), s2("Programming");
    s1.print();
    cout << "s1.Length=" << s1.Length() << endl;
    MyString s3 = s1.StrCat("C++");
    s3.print();
    cout << "s2.SubChar(o)=" << s2.Subchar("o") << endl;
    cout << "s2.SubStrLoc(mi)=" << s2.SubStrLoc("mi") << endl;
    MyString s4 = s2.SubStr(4, 6);
    s4.print();
}
int main()
{
    teststring();
    //system("pause");
    return 0;
}