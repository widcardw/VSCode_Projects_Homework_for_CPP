#ifndef  _SHAPE_H
#define  _SHAPE_H
#include <math.h>
const double pi = 3.14158;    	//����ȫ�ֳ���pi
class CShape                   	//ͼ������һ��������࣬Ϊ�������ṩͳһ����
{
public:
	virtual void show()const = 0;    		//���麯��
};

class CShape1D : public CShape     			//һάͼ������ͼ����Ϊ����
{
public:
	virtual void MoveTo(double) = 0; 		//ƽ��
	virtual double GetLength()const = 0; 	//���㳤��
};


class CShape2D :public CShape        		//��άͼ������ͼ����Ϊ����
{
public:
	virtual void MoveToX(double) = 0; 		//��X��ƽ��
	virtual void MoveToY(double) = 0; 		//��Y��ƽ��
	virtual double GetArea()const = 0;  	//�������
};

class CShape3D :public CShape        		//��άͼ������ͼ����Ϊ����
{
public:
	virtual void MoveToX(double) = 0; 		//��X��ƽ��
	virtual void MoveToY(double) = 0; 		//��y��ƽ��
	virtual void MoveToZ(double) = 0; 		//��Z��ƽ��
	virtual double GetArea()const = 0;		//�������
	virtual double GetVolume()const = 0;		//�������
};
#endif
