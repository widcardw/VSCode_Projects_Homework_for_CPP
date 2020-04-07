#include <iostream>
#include <string>
using namespace std;

int strToint(const string &str)
{
    int num = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str.at(i) >= '0' && str.at(i) <= '9')
        {
            num = num * 10 + str.at(i) - '0';
        }
        else
            throw str.at(i);
    }
    return num;
}

int main()
{
    string str;
    int i_value;
    cout << "Please input a number string:\n";
    cin >> str;
    try
    {
        i_value = strToint(str);
        if (i_value > 10000)
            throw i_value;
    }
    catch (char)
    {
        cout << "Input string includes illegal character" << endl;
        i_value = -1;
    }
    catch (int)
    {
        cout << "number is too large: " << i_value << endl;
    }
    cout << i_value << endl;
    return 0;
}