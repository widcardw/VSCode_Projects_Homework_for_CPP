#include <iostream>
#include <stdio.h>

#include <cassert>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
void main()
{
	char *p1="abc",*p2="",*p3=NULL;
	cout<<(void*)p1<<"   "<<strcmp(p1,p2)<<endl;
	cout<<(void*)p2<<"   ";//<<strcmp(p1,p3)<<endl;
	cout<<(void*)p3<<"   ";//<<strcmp(p1,p3)<<endl;
}

*/
class MyString
{
public:
	MyString(const char *str = "");

	MyString(const MyString &str);

	~MyString();

	MyString &operator=(const MyString &str);
	void print()
	{
		cout << m_data << endl;
	}
	int strcamp(const MyString &str)
	{
		strcmp(m_data, str.m_data);
	}
	MyString substr(int begin, int len)
	{
		assert(begin >= 0 && len >= 1 && begin < m_size && begin + len <= m_size);
		char *p = new char[m_size + 1];
		strcpy(p, m_data);
		p[begin + len] = '\0';
		MyString temp(p + begin);
		delete[] p;
		return temp;
	}

private:
	char *m_data;
	int m_size;
};

MyString::MyString(const char *str)
{

	m_size = strlen(str);
	m_data = new char[m_size + 1];
	assert(m_data);
	strcpy(m_data, str);
}

MyString::MyString(const MyString &str)
{
	m_size = str.m_size;
	m_data = new char[m_size + 1];
	assert(m_data);
	strcpy(m_data, str.m_data);
}

MyString::~MyString()
{
	delete[] m_data;
}

MyString &MyString::operator=(const MyString &str)
{
	if (this == &str)
		return *this;

	delete[] m_data;
	m_size = strlen(str.m_data);
	m_data = new char[m_size + 1];
	assert(m_data);
	strcpy(m_data, str.m_data);
	return *this;
}

void main()
{
	MyString a, b;
	a = "abdabc";
	b.print();
	a.print();
	b = a;
	b.print();
	a.substr(2, 3).print();
}
