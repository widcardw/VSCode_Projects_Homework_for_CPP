#ifndef _KSTRING_H
#define _KSTRING_H

class KString
{
private:
    char *m_str;
    int m_len;

public:
    KString(const char *p = "");
    KString(const KString &str);
    ~KString();
    int length() const;
    bool isEmpty() const;
    int find(const char c, int startPosition = 0) const;
    int find(const char *p, int startPosition = 0) const;
    int Compare(const KString &p);
    int Compare(const char *p);
    KString &operator=(const KString &p);
    KString &operator+=(const KString &p);
    KString &operator+=(const char *p);
    friend KString operator+(KString &p1, KString &p2);
    friend KString operator+(KString &p1, const char *p2);
    friend KString operator+(const char *p1, KString &p2);
    bool operator==(const KString &p);
    bool operator!=(const KString &p);
    bool operator>(const KString &p);
    bool operator<(const KString &p);
    bool operator>=(const KString &p);
    bool operator<=(const KString &p);
    friend std::ostream &operator<<(std::ostream &, KString &);
    friend std::istream &operator>>(std::istream &, KString &);
    KString Upper();
    KString Lower();
};

#endif