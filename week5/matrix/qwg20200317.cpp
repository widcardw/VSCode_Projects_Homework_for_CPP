
/********************************************************************
File name    :  f0309.cpp
Description  :  普通函数作为友元函数
********************************************************************/
#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
using namespace std;
//-------------------------------------
class Vector;
class Matrix;

class Matrix
{
	int *m;
	int szl, szr;
	friend Vector multiply1(Matrix &m, Vector &v);

public:
	void set(int, int);
	void remove()
	{
		delete[] m;
	}
	Vector multiply11(Vector &v);
	Vector multiply1111(Vector &v);
	int sizeL();
	int sizeR();
	int &elem(int, int);
	~Matrix()
	{
		delete[] m;
	}
}; //-----------------------------------
int Matrix::sizeL()
{
	return szl;
}
int Matrix::sizeR()
{
	return szr;
}
void Matrix::set(int i, int j)
{
	szl = i;
	szr = j;
	if (i <= 0 || j <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i * j];
	assert(m);
} //------------------------------------
int &Matrix::elem(int i, int j) //引用返回的目的是返回值可以作左值
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i * szr + j];
} //------------------------------------
class Vector
{
	int *v; //指向一个数组,表示向量
	int sz;

public:
	friend Vector multiply1(Matrix &m, Vector &v);
	friend Matrix;
	void remove()
	{
		delete[] v;
	}
	int size()
	{
		return sz;
	}
	friend Vector Matrix::multiply11(Vector &v);
	void set(int);
	void display();
	int &operator[](int);
	int &elem(int);
	Vector()
	{
		sz = 0;
		v = NULL;
	}
	~Vector()
	{
		if (sz != 0)
			delete[] v;
	}
	Vector &operator=(Vector &ve)
	{
		if (this != &ve)
		{
			if (sz != 0)
				delete[] v;
			set(ve.sz);
			for (int i = 0; i < sz; i++)
			{
				v[i] = ve.v[i];
			}
		}
		return *this;
	}
	Vector(Vector &ve)
	{
		set(ve.sz);
		for (int i = 0; i < sz; i++)
		{
			v[i] = ve.v[i];
		}
	}
};
//-----------------------------------
void Vector::set(int s)
{
	sz = s;
	if (s <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
	assert(v);
} //------------------------------------
int &Vector::operator[](int i) //引用返回的目的是返回值可以作左值
{
	if (i < 0 || i >= sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
} //------------------------------------
int &Vector::elem(int i) //引用返回的目的是返回值可以作左值  Vector v;v.set(10);v.elem(2)=3;
{
	if (i < 0 || i >= sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
} //------------------------------------
void Vector::display()
{
	for (int i = 0; i < sz; ++i)
		cout << v[i] << " ";
	cout << "\n";
} //------------------------------------
Vector multiply(Matrix &m, Vector &v) //矩阵乘向量
{
	if (m.sizeR() != v.size())
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;		  //创建一个存放结果的空向量
	r.set(m.sizeL()); //不能够写m.szl
	for (int i = 0; i < m.sizeL(); i++)
	{
		r[i] = 0; //r.elem(i)=0;
		for (int j = 0; j < m.sizeR(); j++)
			r[i] += m.elem(i, j) * v[j]; //r.elem(i)+=m.elem(i,j)*v.elem(j);
	}
	return r;
} //------------------------------------
Vector multiply1(Matrix &m, Vector &v) //矩阵乘向量
{
	if (m.szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r; //创建一个存放结果的空向量
	r.set(m.szl);
	for (int i = 0; i < m.szl; i++)
	{
		r.v[i] = 0; //r[i]=0; or r.elem(i)=0;
		for (int j = 0; j < m.szr; j++)
			r.v[i] += m.m[i * m.szr + j] * v.v[j]; //	r[i] += m.elem(i,j) * v[j];//r.elem(i)+=m.elem(i,j)*v.elem(j);
	}
	return r;
} //------------------------------------
Vector Matrix::multiply11(Vector &v) //矩阵乘向量
{
	if (szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(szl); //创建一个存放结果的空向量
	for (int i = 0; i < szl; i++)
	{
		r.v[i] = 0;
		for (int j = 0; j < szr; j++)
			r.v[i] += m[i * szr + j] * v.v[j];
	}
	return r;
} //------------------------------------
Vector Matrix::multiply1111(Vector &v) //矩阵乘向量
{
	if (szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(szl); //创建一个存放结果的空向量
	for (int i = 0; i < szl; i++)
	{
		r.v[i] = 0;
		for (int j = 0; j < szr; j++)
			r.v[i] += m[i * szr + j] * v.v[j];
	}
	return r;
} //------------------------------------

int main()
{
	ifstream in("in.txt");
	if (!in)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int x, y;
	in >> x >> y;
	Matrix ma;
	ma.set(x, y);
	int i;
	for (i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			in >> ma.elem(i, j);
	in >> x;
	Vector ve;
	ve.set(x);
	for (i = 0; i < x; ++i)
		in >> ve[i];
	Vector vx;
	double t_start = clock();
	for (i = 0; i < 1000; i++)
		vx = multiply(ma, ve);
	cout << clock() - t_start << endl;
	vx.display();
	t_start = clock();
	for (i = 0; i < 1000; i++)
		vx = multiply1(ma, ve);
	cout << clock() - t_start << endl;
	vx.display();
	t_start = clock();
	for (i = 0; i < 1000; i++)
		vx = ma.multiply11(ve);
	cout << clock() - t_start << endl;
	vx.display();
	t_start = clock();
	for (i = 0; i < 1000; i++)
		vx = ma.multiply1111(ve);
	cout << clock() - t_start << endl;
	vx.display();
	return 0;
}
//====================================

/********************************************************************
	File name    :  f0306.cpp
	Description  :  利用全局变量统计生成对象个数
********************************************************************/
/*#include <iostream>
using namespace std;
//int countP=0;		//全局变量，用于统计创建的Point对象个数
class Point								//Point类声明
{
public:									//外部接口
	Point(int X=0, int Y=0):X(X),Y(Y) 			//构造函数
	{
//		X=X;
//		Y=Y;
		countP++;
		cout<<countP<<endl;
	}	
	Point(Point &p);						//复制构造函数
	~Point()
	{
		countP--;
		cout<<countP<<endl;
	}
	int GetX() 
	{
		return X;
	}
	int GetY() 
	{
		return Y;
	}
	static void showP()
	{
		cout<<countP<<endl;
	}
private:
	static int countP;//私有数据成员
	int X,Y;
};
int Point::countP=0;
Point::Point(Point &p)
{
	X=p.X;
	Y=p.Y;
	countP++;
	cout<<countP<<endl;
}

void main()		        					//主函数实现
{
	Point::showP();
//	cout<<Point::countP<<endl;       	
	Point A;                 			//声明对象A
	A.showP();
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY()<<endl;
//	cout<<" Object id="<<++Point::countP<<endl;	
	Point B(A);	
	Point::showP();
	B.showP();//声明对象B
	cout<<"Point B,"<<B.GetX()<<","<<B.GetY()<<endl;
//	cout<<" Object id="<<A.countP<<"    "<<B.countP<<"    "<<Point::countP<<endl; 	

}*/
/********************************************************************
File name    :  f0308.cpp
Description  :  静态成员变量的使用
********************************************************************/
/*
#include <iostream>
#include <string>
using namespace std;

class Panda
{
	static string ChName;
	static string EnName;
	static string LtName;
	string name;
	char sex;
	string place;
	int yearofBirth;
public:
	Panda(string nm="noName",char sx='m',
		string place="四川",int year=2015):
	name(nm),sex(sx),place(place),yearofBirth(year)
	{}
	void print()
	{
		cout<<"名字："<< name << endl
			<<"性别："<<( (sex=='m') ? "雄性":"雌性")<<endl
			<<"地点："<< place<<endl
			<<"出生年份："<<yearofBirth<<endl;
	}
	static void intro()
	{
		cout<<"熊猫的"<<endl
			<<"中文名称："<<ChName<<endl
			<<"英文名称："<<EnName<<endl
			<<"拉丁名称："<<LtName<<endl;
	}
};
string Panda::ChName="大熊猫";
string Panda::EnName="Giant Panda";
string Panda::LtName="Ailuropoda melanoleuca";
void main()
{
	Panda::intro();
	Panda panpan("巴斯",'m',"洛杉矶",1980);
	Panda xiwang("希望",'f',"四川",2005);
	panpan.intro();
	panpan.print();
	xiwang.intro();
	xiwang.print();
}
*/
