#include <iostream>
#include <fstream>
#include <ctime>
int main()
{
    srand(time(NULL));
    int range = 10000, i;
    std::ofstream file;
    file.open("data.dat");
    if (!file)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < range; ++i)
    {
        file << rand() % 998244353;
        if (i % 20 == 19)
            file << '\n';
        else
            file << '\t';
    }
    file.close();
    return 0;
}