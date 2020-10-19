#pragma once
#ifndef _KSTRING_H
#define _KSTRING_H
#include <iostream>
using namespace std;
class KString
{
private:
    char *str; //字符串指针
    int len;   //字符串str的长度
public:
    KString(const char *myx = "");
    KString(const KString &myx);
    int length();
    bool iskong() const;
    int find(const char c, int first);
    int find(const char *myx, int first);
    bool compare(const KString &p);
    bool compare(const char *myx);
    KString KStrcat(const KString &myx);
    void KStrcpy(char *str1, const char *str2);
    int KStrcmp(const char *myx);
    KString KSubstr(int start, int len1);
    KString &operator=(const KString &myx);
    KString &operator+=(const KString &myx);
    KString &operator+=(const char *myx);
    friend KString operator+(KString &myx1, KString &myx2);
    friend KString operator+(KString &myx1, const char *myx2);
    friend KString operator+(const char *myx1, KString &myx2);
    bool operator==(const KString &myx);
    bool operator!=(const KString &myx);
    bool operator>(const KString &myx);
    bool operator<(const KString &myx);
    bool operator>=(const KString &myx);
    bool operator<=(const KString &myx);
    friend std::ostream &operator<<(std::ostream &, KString &);
    friend std::istream &operator>>(std::istream &, KString &);
    KString upper();
    KString lower();
    ~KString();
};
#endif // !_KSTRING_H
