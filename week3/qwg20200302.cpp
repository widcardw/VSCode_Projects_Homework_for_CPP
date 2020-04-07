#include <iostream>
#include <cassert>
using namespace std;

#include <string>



class Student
{
	string id;  		//定义学号
	char* pName;	//定义姓名
	char gender;	//定义性别'f''m'     ---"a""

public:
	Student(string id="1320103001", char* pN="noName",
	char gender='m' ) :id(id),gender(gender)
	{
		pName = new char[strlen(pN)+1];
		assert(pName);
		strcpy(pName,pN);
//		if(pName) 
//			strcpy(pName,pN);
		cout<<"构造函数："<<id<<endl;
	}
	Student(const Student& s)
	{
		id=s.id;
		pName = new char[strlen(s.pName)+1];
		assert(pName);
		strcpy(pName,s.pName);
//		if(pName) 
//			strcpy(pName, s.pName);
		gender=s.gender;
		cout<<"复制构造函数："<<id<<endl; 
	}
	~Student()
	{
		cout<<"析构函数："<<id<<endl;
		printf("析构函数：%s：\n",id.c_str());
		delete[] pName;
	}
	void print()
	{
		 cout<<id<<"   "<<pName<<"    "<<gender<<endl;
	}
};
Student stu1("1320103001","qwg",'m');
void fn()
{
	static Student stu2("1320103002","yws",'m');
	cout<<"fn"<<endl;
}
void main()
{
	cout << "in main()" << endl;
	Student *pStu=new Student[2];
	Student stu3("1320103005","sq",'f');
	fn();
	static Student stu4("1320103006","wqq",'f');
	fn();
	delete []pStu;
	cout << "out main()" << endl;
	Student aa,*p,&kk=stu2;
}

//=====================================

/********************************************************************
File name  :  f0213.cpp
Description :  复制构造函数
********************************************************************/
/*
#include <iostream>
using namespace std;
class CPoint 
{
public:
	CPoint(int x = 0, int y = 0) :nPosX(x),nPosY(y)
	{ 
		cout<<"constructor"<<endl;
		cout<<"in con X="<<nPosX<<",Y="<<nPosY<<endl;
//		nPosX = x;  		
//		nPosY = y;
	}
	CPoint(const CPoint& pt) :nPosX(pt.nPosX),nPosY(pt.nPosY)
	{
		cout<<"copy constructor"<<endl;
	}
	~CPoint()
	{
		cout<<"destructor"<<endl;
	}
	void print()
	{
		cout<<"X="<<nPosX<<",Y="<<nPosY<<endl;
	}
private:
		int nPosX, nPosY;	
};

void main()
{
	CPoint pt1(1,2);
	pt1.print();
	CPoint pt2(11,22);
	pt2.print();
	CPoint pt3=pt2,pt4;//pt3(pt2);
	pt4=pt2;
	pt3.print();
	pt4.print();
}
*/
//====================================
/*
class Person
{
	char* pName;
public:
	Person(char* pN = "noName")
	{
		pName = new char[strlen(pN) + 1];
		assert(pName);
		strcpy(pName, pN);
//		if (pName)
//			strcpy(pName, pN);
		cout << "构造函数: &pName =" << &pName << "pName=" << (void*)pName << "string=" << pName << endl;
	}
	Person( const Person &one )	//	:pName(one.pName)			//复制构造函数 copy constructor 拷贝构造函数
		//浅拷贝，浅复制，shallow copy
	{
		//为strName开辟独立的内存空间
		pName = new char[strlen(one.pName)+1];
		assert(pName);
		strcpy(pName, one.pName);		//复制内容
		cout<<"复制构造函数！"<<endl;
		cout << "构造函数: &pName =" << &pName << "pName=" << (void*)pName << "string=" << pName << endl;
	}
	Person& Assign(const Person & a)//a=b;
	{
		if(strcmp((*this).pName,a.pName)!=0)
		{	
			delete []pName;
			pName=new char[strlen(a.pName)+1];
			assert(pName);
			strcpy(pName,a.pName);
//			if(pName)
//				strcpy(pName,a.pName);
		}
		return *this;
	}
	Person& operator = (const Person & a)
	{
		if(strcmp((*this).pName,a.pName)!=0)
		{	
			delete []pName;
			pName=new char[strlen(a.pName)+1];
			assert(pName);
			strcpy(pName,a.pName);
		}
		return *this;
	}

	~Person()
	{
		cout << "析构函数:  " << endl;
		cout << "构造函数: &pName =" << &pName << "pName=" << (void*)pName << "string=" << pName << endl;
		delete[] pName;
	}
	void print()
	{
		cout << pName << "    \n";
	}
};
void main()
{
	Person a1("zhang"), a2 = "wang";
	a1.print();
	a2.print();
//	Person temp(a1);//Person temp();
	Person temp;
	temp=a2;    //赋值
//	temp.Assign(a2);
	temp.print();
}
*/