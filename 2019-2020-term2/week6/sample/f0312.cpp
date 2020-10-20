/********************************************************************
  	File name    :  f0312.cpp
  	Description  :  链表类应用的主函数
********************************************************************/

#include "ListP.h"
#include "person.h"
#include <iostream>
using namespace std;

void main()
{
	//	cout<<strcmp("zhang3","liu")<<endl;
	//	cout<<strcmp("liu","zhang3")<<endl;
	//	cout<<strcmp("liu","liu")<<endl;
	listClass L;
	cout << L.ListLength() << endl;
	listItemType DataItem;
	bool Success;
	Person p0("zhang3");
	L.orderInsert(p0);
	cout << L.ListLength() << endl;
	Person p1("zhang1");
	L.orderInsert(p1);
	cout << L.ListLength() << endl;
	Person p2("zhang2");
	L.orderInsert(p2);
	cout << L.ListLength() << endl;
	Person p3("liu");
	L.orderInsert(p3);
	cout << L.ListLength() << endl;
	for (int i = 1; i <= L.ListLength(); i++)
	{
		L.ListRetrieve(i, DataItem, Success);
		cout << DataItem << endl;
		//		DataItem.print();
	}
	L.ListDelete(1, Success);
	for (int i = 1; i <= L.ListLength(); i++)
	{
		L.ListRetrieve(i, DataItem, Success);
		DataItem.print();
		//		cout<<DataItem<<endl;
	}
}
/*
void main()
{
	listItemType DataItem;
	bool Success;
	Person p1("zhang1");
	Person p2("zhang2");
	Person p3("zhang3");
	listClass listasstack;
	listasstack.push(p3);
	listasstack.push(p2);
	listasstack.push(p1);
	cout<<listasstack.ListLength()<<endl;
	Person temp;
	while(listasstack.ListLength()>0)
	{
		listasstack.top(temp);
		cout<<temp<<endl;
		listasstack.pop();

	}
}
*/
/*
void main()
{
	listClass L;
	listItemType DataItem;
	bool Success;
	Person p1("zhang1");
	L.ListInsert(1,p1,Success);
	Person p2("zhang2");
	L.ListInsert(2,p2,Success);
	Person p3("zhang3");
	L.ListInsert(3,p3,Success);
	for(int i=1;i<=L.ListLength();i++)
	{
		L.ListRetrieve(i,DataItem,Success);
		cout<<DataItem<<endl;
//		DataItem.print();
	}
	L.ListDelete(1,Success);
	for(i=1;i<=L.ListLength();i++)
	{
		L.ListRetrieve(i,DataItem,Success);
		DataItem.print();
//		cout<<DataItem<<endl;
	}
	listClass listasstack;
	listasstack.push(p3);
	listasstack.push(p2);
	listasstack.push(p1);
	cout<<listasstack.ListLength()<<endl;
	Person temp;
	while(listasstack.ListLength()>0)
	{
		listasstack.top(temp);
		cout<<temp<<endl;
		listasstack.pop();

	}

}
*/