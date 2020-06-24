#include <iostream>
#include <cstring>
#include <cassert>

class City
{
    char *name;

public:
    City(const char *str = "")
    {
        name = new char[strlen(str) + 1];
        assert(name);
        strcpy(name, str);
    }
    City(const City &c)
    {
        if (this == &c)
            return;
        delete[] name;
        name = new char[strlen(c.name) + 1];
        assert(name);
        strcpy(name, c.name);
    }
    City &operator=(const City &c)
    {
        if (this == &c)
            return *this;
        delete[] name;
        name = new char[strlen(c.name) + 1];
        assert(name);
        strcpy(name, c.name);
    }
    bool operator>(const City &c)
    {
        if (strcmp(name, c.name) > 0)
            return true;
        else
            return false;
    }
    ~City()
    {
        delete[] name;
    }
    friend std::ostream &operator<<(std::ostream &out, City &c)
    {
        out << c.name << "\n";
        return out;
    }
};
void sort(City city[], int n)
{
    City temp;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i; j < n; ++j)
            if (city[i] > city[j])
            {
                temp = city[i];
                city[i] = city[j];
                city[j] = temp;
            }
}
int main()
{
    City city[3] = {"Nanjing", "Beijing", "Shanghai"};
    for (int i = 0; i < 3; ++i)
        std::cout << city[i];
    sort(city, 3);
    for (int j = 0; j < 3; ++j)
        std::cout << city[j];
    return 0;
}