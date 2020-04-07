#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> vecDouble = {98.5, 67.5, 43.6, 32.9};
    vecDouble.push_back(100.8);
    for (int i = 0; i < vecDouble.size(); i++)
        cout << vecDouble[i] << endl;

    sort(vecDouble.begin(), vecDouble.end());

    reverse(vecDouble.begin(), vecDouble.end());

    vector<double>::iterator it;
    for (it = vecDouble.begin(); it != vecDouble.end(); ++it)
        cout << *it << endl;

    return 0;
}