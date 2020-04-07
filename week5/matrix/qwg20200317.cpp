
/********************************************************************
File name    :  f0309.cpp
Description  :  ��ͨ������Ϊ��Ԫ����
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
int &Matrix::elem(int i, int j) //���÷��ص�Ŀ���Ƿ���ֵ��������ֵ
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
	int *v; //ָ��һ������,��ʾ����
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
int &Vector::operator[](int i) //���÷��ص�Ŀ���Ƿ���ֵ��������ֵ
{
	if (i < 0 || i >= sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
} //------------------------------------
int &Vector::elem(int i) //���÷��ص�Ŀ���Ƿ���ֵ��������ֵ  Vector v;v.set(10);v.elem(2)=3;
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
Vector multiply(Matrix &m, Vector &v) //���������
{
	if (m.sizeR() != v.size())
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;		  //����һ����Ž���Ŀ�����
	r.set(m.sizeL()); //���ܹ�дm.szl
	for (int i = 0; i < m.sizeL(); i++)
	{
		r[i] = 0; //r.elem(i)=0;
		for (int j = 0; j < m.sizeR(); j++)
			r[i] += m.elem(i, j) * v[j]; //r.elem(i)+=m.elem(i,j)*v.elem(j);
	}
	return r;
} //------------------------------------
Vector multiply1(Matrix &m, Vector &v) //���������
{
	if (m.szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r; //����һ����Ž���Ŀ�����
	r.set(m.szl);
	for (int i = 0; i < m.szl; i++)
	{
		r.v[i] = 0; //r[i]=0; or r.elem(i)=0;
		for (int j = 0; j < m.szr; j++)
			r.v[i] += m.m[i * m.szr + j] * v.v[j]; //	r[i] += m.elem(i,j) * v[j];//r.elem(i)+=m.elem(i,j)*v.elem(j);
	}
	return r;
} //------------------------------------
Vector Matrix::multiply11(Vector &v) //���������
{
	if (szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(szl); //����һ����Ž���Ŀ�����
	for (int i = 0; i < szl; i++)
	{
		r.v[i] = 0;
		for (int j = 0; j < szr; j++)
			r.v[i] += m[i * szr + j] * v.v[j];
	}
	return r;
} //------------------------------------
Vector Matrix::multiply1111(Vector &v) //���������
{
	if (szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(szl); //����һ����Ž���Ŀ�����
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
	Description  :  ����ȫ�ֱ���ͳ�����ɶ������
********************************************************************/
/*#include <iostream>
using namespace std;
//int countP=0;		//ȫ�ֱ���������ͳ�ƴ�����Point�������
class Point								//Point������
{
public:									//�ⲿ�ӿ�
	Point(int X=0, int Y=0):X(X),Y(Y) 			//���캯��
	{
//		X=X;
//		Y=Y;
		countP++;
		cout<<countP<<endl;
	}	
	Point(Point &p);						//���ƹ��캯��
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
	static int countP;//˽�����ݳ�Ա
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

void main()		        					//������ʵ��
{
	Point::showP();
//	cout<<Point::countP<<endl;       	
	Point A;                 			//��������A
	A.showP();
	cout<<"Point A,"<<A.GetX()<<","<<A.GetY()<<endl;
//	cout<<" Object id="<<++Point::countP<<endl;	
	Point B(A);	
	Point::showP();
	B.showP();//��������B
	cout<<"Point B,"<<B.GetX()<<","<<B.GetY()<<endl;
//	cout<<" Object id="<<A.countP<<"    "<<B.countP<<"    "<<Point::countP<<endl; 	

}*/
/********************************************************************
File name    :  f0308.cpp
Description  :  ��̬��Ա������ʹ��
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
		string place="�Ĵ�",int year=2015):
	name(nm),sex(sx),place(place),yearofBirth(year)
	{}
	void print()
	{
		cout<<"���֣�"<< name << endl
			<<"�Ա�"<<( (sex=='m') ? "����":"����")<<endl
			<<"�ص㣺"<< place<<endl
			<<"������ݣ�"<<yearofBirth<<endl;
	}
	static void intro()
	{
		cout<<"��è��"<<endl
			<<"�������ƣ�"<<ChName<<endl
			<<"Ӣ�����ƣ�"<<EnName<<endl
			<<"�������ƣ�"<<LtName<<endl;
	}
};
string Panda::ChName="����è";
string Panda::EnName="Giant Panda";
string Panda::LtName="Ailuropoda melanoleuca";
void main()
{
	Panda::intro();
	Panda panpan("��˹",'m',"��ɼ�",1980);
	Panda xiwang("ϣ��",'f',"�Ĵ�",2005);
	panpan.intro();
	panpan.print();
	xiwang.intro();
	xiwang.print();
}
*/
