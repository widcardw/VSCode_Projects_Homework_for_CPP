/********************************************************************
File name  	:  f0710.cpp
Description	:  成批文件的处理
********************************************************************/
#include <fstream>
#include <iostream>
#include <strstream>
#include <direct.h>
#include <string>
#include <io.h>
using  namespace std;
int  process_files(const char *skeleton, void (*proc) (const char *filename))
{
	unsigned  files=0;
	long  handle;
	struct  _finddata_t  info;
	char  buffer[100], *p;
	strcpy(buffer, skeleton);
	p=strrchr(buffer, '\\');
	if(p!=NULL)								//如果含有路径
	{  
		char  ch = *(++p);
		*p = '\0';
		if(_chdir(buffer)!=0) return 0;
		*p = ch;
	}
	else p=buffer;
	handle=_findfirst(p, &info);
	if(handle == -1) return 0;
	do {
		proc(info.name);					//调用proc所指的函数
		files++;
	}  while(_findnext(handle, &info)==0);
	return  files;
}
void file_count(const char 	*filename)
{
	char ch;
	int count=0;
	ifstream in(filename);
	if (!in)
	{
		cout<<"Can't open the file!"<<endl;
		exit(0);
	}
	while((ch=in.get())!=EOF)
	{
		cout<<int(ch);
		if(ch!=' '&&ch!='\r'&&ch!='\n')
		{
			cout<<'('<<ch<<')';
			count++;
		}
		cout<<' ';
	}
	printf("\nthe file <%s> has %d characters\n",filename,count);
	in.close();
}
void file_count_line(const char 	*filename)
{
	char ch;
	int count=0;
	string line;
	ifstream in(filename);
	if (!in)
	{
		cout<<"Can't open the file!"<<endl;
		exit(0);
	}
	while(getline(in,line))
	{
		count++;
		cout<<count<<"    "<<line<<endl;
	}
	printf("\nthe file <%s> has %d lines\n",filename,count);
	in.close();
}
void main()
{
	process_files("D:\\mydir\\*.txt",file_count_line);
}
