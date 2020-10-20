/******************************
 * ��ȡtext1��text2��text3�����ı��ļ��е����ݣ������������ı��ļ��е������������Ļ�ϡ�
 * file: PrintText.cpp
 * ******************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    for (int i = 1; i <= 3; ++i)
    {
        string b(".txt");
        string file_name;
        stringstream ss;
        ss << "text" << i << b;
        ss >> file_name;
        ifstream input;
        input.open(file_name.c_str());
        //assert(input);
        if (!input)
        {
            cerr << "Cannot open the file!" << endl;
            exit(-1);
        }
        string line;
        getline(input, line);
        string::iterator it;
        for (it = line.begin(); it != line.end(); ++it)
        {
            if (*it == ' ')
                line.erase(it);
        }
        cout << line << endl;
        input.close();
    }
    return 0;
}