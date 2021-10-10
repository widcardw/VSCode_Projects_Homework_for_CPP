#include <iostream>

using namespace std;

int main()
{
    char *s = "2473", c;
    while (c = *s++)
    {
        switch (c - '2')
        {
        case 0:
        case 1:
            cout << (char)(c + 4) << "\t";
        case 2:
            cout << (char)(c + 4) << "\t";
            break;
        case 3:
            cout << (char)(c + 3) << "\t";
        default:
            cout << (char)(c + 2) << "\n";
        }
    }
    return 0;
}