#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Person
{
	char *pName;

public:
	Person(char *pN = "noName")
	{
		pName = new char[strlen(pN) + 1];
		assert(pName);
		strcpy(pName, pN);
		//		if (pName)
		//			strcpy(pName, pN);
		cout << "构造函数: &pName =" << &pName << "   pName=" << (void *)pName << "   string=" << pName << endl;
	}
	Person(const Person &one) //	:pName(one.pName)			//复制构造函数 copy constructor 拷贝构造函数
							  //浅拷贝，浅复制，shallow copy
	{
		//为strName开辟独立的内存空间
		pName = new char[strlen(one.pName) + 1];
		assert(pName);
		strcpy(pName, one.pName); //复制内容
		cout << "复制构造函数！"
			 << "  &pName =" << &pName << "   pName=" << (void *)pName << "   string=" << pName << endl;
	}
	Person &Assign(const Person &a) //a=b;
	{
		if (strcmp((*this).pName, a.pName) != 0)
		{
			delete[] pName;
			pName = new char[strlen(a.pName) + 1];
			assert(pName);
			strcpy(pName, a.pName);
			//			if(pName)
			//				strcpy(pName,a.pName);
		}
		return *this;
	}
	Person &operator=(const Person &a)
	{
		if (strcmp((*this).pName, a.pName) != 0)
		{
			delete[] pName;
			pName = new char[strlen(a.pName) + 1];
			assert(pName);
			strcpy(pName, a.pName);
		}
		return *this;
	}

	~Person()
	{
		cout << "析构函数:  "
			 << "   &pName =" << &pName << "    pName=" << (void *)pName << "    string=" << pName << endl;
		delete[] pName;
	}
	void print()
	{
		cout << pName << "    \n";
	}
	friend ostream &operator<<(ostream &out, const Person &obj) //cout<<"abvc="<<p2<<"  "<<i<<endl;
	{
		out << obj.pName;
		return out;
	}
	bool operator>(const Person &obj)
	{
		//		cout<<"-----"<<strcmp(pName,obj.pName)<<"   "<<pName<<"  "<<obj.pName<<endl;
		return (strcmp(pName, obj.pName) > 0);
	}
};

#endif