#include <iostream>
#include <string>
using namespace std;

int strToint(const string &str)
{
    int num = 0, i = 0;
    if (str.at(i) == '-')
        i++;
    for (; i < str.length(); i++)
    {
        if (str.at(i) >= '0' && str.at(i) <= '9')
        {
            num = num * 10 + str.at(i) - '0';
        }
        else
            throw str.at(i);
    }
    if (str.at(0) == '-')
        return -num;
    return num;
}
int main()
{
    string str;
    int i_value;
    cout << "Please input a number string: ";
    cin >> str;
    try
    {
        i_value = strToint(str);
        if (i_value < -10000 || i_value > 10000)
            throw i_value;
    }
    catch (char c)
    {
        cout << "Input string includes illegal character: " << c << endl;
        i_value = INT32_MIN;
    }
    catch (int)
    {
        cout << "Input number is out of range: " << i_value << endl;
    }
    cout << i_value << endl;
    return 0;
}