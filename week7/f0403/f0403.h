#ifndef _MYSTRING_H
#define _MYSTRING_H
/*class define----------------------------------------------------*/
class CMyString
{
private:
    unsigned int m_size; //�ַ�������󳤶�-1
    char *mp_data;       //ָ�������ݵ��ڴ�ռ�
public:
    CMyString(unsigned int = 0);             //���캯��
    CMyString(const char *pstr);             //���캯��
    ~CMyString();                            //��������
    char &operator[](int);                   //�±���������غ���
    int length() const;                      //���ص�ǰ������Ԫ�ظ���
    int capacity() const;                    //������������Ԫ�ظ���
    void display() const;                    //��ʾ�ַ�������
    CMyString &operator=(const CMyString &); //��ֵ���������
};

#endif
