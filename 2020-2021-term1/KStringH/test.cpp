#include <iostream>
#include <fstream>
#include "kstring.h"
using namespace std;
int main()
{
    /*KString ceshi1,ceshi2,ceshi;
	cin >> ceshi1>>ceshi2;
	ceshi = ceshi1 + ceshi2;
	cout << ceshi << endl;
	KString a("KingJames");
	KString b(a);
	b = b + " LBJ";
	KString c = "MVP " + a;
	//KString d = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	//cout << d << endl;
	cout << (a <= b) << endl;
	c += " choose one";
	cout << c << endl;
	KString d=a.upper();
	KString e = a.lower();
	cout << d << " " << e << endl;*/
    int opt = 0;
    while (1)
    {

        cout << "欢迎使用KString程序，操作菜单如下:\n\n***********************************************************************************************\n|  1、将一个字符串拼接到一个KString类对象的str后                                    |\n|  2、将两个KString对象拼接起来                                                     |\n|  3、查找某个字符串在KString对象的str中是否存在，若存在则返回第一个字符所在的位置  |\n|  4、比较两个字符串的大小                                                          |\n|  5、将KString类中的字符串转化为大写                                               |\n|  6、将KString类中的字符串转化为小写                                               |\n|  7、求出KString字符串的子串                                                       |\n|  0、退出程序                                                                      |" << endl;
        cout << "*********************************************************************************************" << endl;
        cout << "                                                                                                                   \n";
        cout << "请选择您的操作：";

        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            char *myx1;
            int n1, i;
            cout << "请输入你想添加的字符串的长度n1=";
            cin >> n1;
            myx1 = new char[n1 + 1];
            cout << "请输入你想添加的字符串：";
            for (i = 0; i < n1; i++)
                cin >> *(myx1 + i);
            *(myx1 + i) = '\0';
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            KString ma;
            ma = yu + myx1;
            cout << ma << endl;
            break;
        }
        case 2:
        {
            KString king;
            cout << "请输入你想添加的KString类型字符串：";
            cin >> king;
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            KString ma;
            ma = yu + king;
            cout << "拼凑之后的结果：" << ma << endl;
            break;
        }
        case 3:
        {
            char *myx1;
            int n1, i;
            cout << "请输入你想查找的字符串的长度n1=";
            cin >> n1;
            myx1 = new char[n1 + 1];
            cout << "请输入你想查找的字符串：";
            for (i = 0; i < n1; i++)
                cin >> *(myx1 + i);
            *(myx1 + i) = '\0';
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            if (yu.find(myx1, 0) >= 0)
            {
                cout << "字符串所在的位置：" << yu.find(myx1, 0) << endl;
            }
            else
                cout << "KString对象中字符串不含此子串" << endl;
            break;
        }
        case 4:
        {
            KString king;
            cout << "请输入你想比较的KString类型字符串1：";
            cin >> king;
            cout << "请输入你想输入的KString字符串2：";
            KString yu;
            cin >> yu;
            if (yu > king)
                cout << "字符串2大" << endl;
            else if (yu < king)
                cout << "字符串1大" << endl;
            else
                cout << "一样大" << endl;
            break;
        }
        case 5:
        {
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            KString ma;
            ma = yu.upper();
            cout << "转化为大写以后的结果为：";
            cout << ma << endl;
            break;
        }
        case 6:
        {
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            KString ma;
            ma = yu.lower();
            cout << "转化为小写以后的结果为：";
            cout << ma << endl;
            break;
        }
        case 7:
        {
            int i, j;
            cout << "请输入子串的起始位置（从0开始）：";
            cin >> i;
            cout << "请输入子串的长度：";
            cin >> j;
            cout << "请输入你想输入的KString字符串：";
            KString yu;
            cin >> yu;
            KString ma(yu.KSubstr(i, j));
            cout << "子串的结果为：";
            cout << ma << endl;
            break;
        }
        default:
        {
            cout << "谢谢体验，您已退出程序。" << endl;
            exit(0);
        }
        }
    }
    return 0;
}