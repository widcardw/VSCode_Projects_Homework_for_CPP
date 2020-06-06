#include <iostream>
#include <string>
#include "shape.h"
#include "1DPoint.h"
#include "1DLine.h"
#include "2DPoint.h"
#include "2DCircle.h"
#include "2DLine.h"
#include "2DRectangle.h"
#include "2DTriangle.h"
#include "3DPoint.h"
#include "3DCube.h"
#include "3DColumn.h"
using namespace std;

typedef struct
{
	string name;
	CShape*shape;
}TagShape;

const int ShapeNum = 10;
/*函数用于构造一个包含20个图形的链表，以测试图形类库结构的正确性 ---------*/
int  ReadShape(TagShape* shapList)
{
	int i = 0;
	int count = 0;
	
	for (i = 0; i < 20; i++)
	{
		try
		{
			int k = i % ShapeNum;
			switch (k){
			case 0:
				shapList[count].name = "C1DPoint";
				shapList[count].shape = new C1DPoint(i);
				break;
			case 1:
				shapList[count].name = "C1DLine";
				shapList[count].shape = new C1DLine(i, i+k);
				break;
			case 2:
				shapList[count].name = "C2DPoint";
				shapList[count].shape = new C2DPoint(i, i / ShapeNum+k);
				break;
			case 3:
				shapList[count].name = "C2DLine";
				shapList[count].shape = new C2DLine(i, i / ShapeNum + k,
 										i + k, ShapeNum + k);
				break;
			case 4:
				shapList[count].name = "C2DRectangle";
				shapList[count].shape = new C2DRectangle(i, i / ShapeNum + k, 
									   i + k, ShapeNum + k);
				break;
			case 5:
				shapList[count].name = "C2DTriangle";
				shapList[count].shape = new C2DTriangle(0, 0, i, i, k, k + i);
				break;
			case 6:
				shapList[count].name = "C2DCircle";
				shapList[count].shape = new C2DCircle(i, i, k + i / ShapeNum);
				break;
			case 7:
				shapList[count].name = "C3DPoint";
				shapList[count].shape = new C3DPoint(i, i, i);
				break;
			case 8:
				shapList[count].name = "C3DCube";
				shapList[count].shape = new C3DCube(i, i, i, k + i, k + i, k + i);
				break;
			case 9:
				shapList[count].name = "C3DColumn";
				shapList[count].shape = new C3DColumn(i, i, i,k, k + i);
				break;
			}
			++count;
		}
		catch (string s)
		{
			cout << "Create shape is error: " << s << endl;
		}
	}
	return count;
}

int main()
{
	TagShape  shapList[30];
	int count=0;
	

	count = ReadShape(shapList);
	for (int i = 0; i < count; i++)
	{
		cout << shapList[i].name << ":  ";
		shapList[i].shape->show();
		cout << "\n";
	}

	return 0;
}   
