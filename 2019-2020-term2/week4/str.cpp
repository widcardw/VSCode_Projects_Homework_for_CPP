#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
class Mystring
{
private:
    char *data;
    int length;

public:
    Mystring()
    {
        data = NULL;
        length = 0;
    }
    Mystring(const char *str)
    {
        assert(str);
        if (!str)
        {
            length = 0;
            data = new char[1];
            *data = '\0';
        }
        else
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
    }
    Mystring(const Mystring &str) //copy constructor function
    {
        length = str.length;
        data = new char[length + 1];
        assert(data);
        mystrcpy(data, str.data);
    }
    ~Mystring()
    {
        delete[] data;
        length = 0;
    }
    int mystrlen()
    {
        assert(data);
        int i = 0;
        while (*(data + i) != '\0')
        {
            i++;
        }
        return i;
    }
    void mystrcpy(char *str1, const char *str2)
    {
        assert(str1);
        assert(str2);
        int i = 0;
        while (str2[i] != '\0')
        {
            str1[i] = str2[i];
            i++;
        }
        str1[i] = '\0';
    }
    int mystrcmp(Mystring &str2)
    {
        assert(data);
        assert(str2.data);
        while (*data == *str2.data)
        {
            if (*data == '\0')
                return 0;
            data++;
            str2.data++;
        }
        if (*data > *str2.data)
            return 1;
        else if (*data < *str2.data)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    Mystring substr(int start, int len)
    {
        assert(start >= 0 && len > 0 && start + len <= length && start < length);
        assert(data);
        int j = 0;
        char *str;
        str = new char[len + 1];
        for (int i = start; i < start + len; i++, j++)
        {
            *(str + j) = *(data + i);
        }
        *(str + (start + len)) = '\0';
        Mystring tmp(str);
        delete[] str;
        return tmp;
    }
    Mystring mystrcat(const Mystring &str)
    {
        char *myxstr = new char[length + str.length + 1];
        assert(data);
        assert(str.data);
        assert(myxstr);
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            *(myxstr + i) = *(data + i);
        }
        for (int i = length; i < length + str.length; i++, j++)
        {
            *(myxstr + i) = *(str.data + j);
        }
        *(myxstr + length + str.length) = '\0';
        Mystring tmp(myxstr);
        delete[] myxstr;
        return tmp;
    }
    Mystring &operator=(const Mystring &str)
    {
        assert(str.data);
        if (this == &str)
            return *this;
        delete[] data;
        length = strlen(str.data);
        data = new char[length + 1];
        assert(data);
        mystrcpy(data, str.data);
        return *this;
    }
    void print()
    {
        cout << data << endl;
    }
};
int main()
{
    Mystring str1("LeBronJames"), str2;
    str2 = str1;
    str1.print();
    str2.print();
    cout << str1.mystrlen() << endl;
    Mystring str3 = " is a great king";
    str3.print();
    cout << str1.mystrcmp(str3) << endl;
    Mystring str4 = str1.substr(2, 4);
    str4.print();
    Mystring str5 = str2.mystrcat(str3);
    str5.print();
    return 0;
}