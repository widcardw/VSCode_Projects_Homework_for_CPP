#include <iostream>
#include <cmath>

class Vector2d
{
    double x, y;

public:
    Vector2d(double x_, double y_) : x(x_), y(y_) {}
    double operator-(const Vector2d v)
    {
        return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }
    double operator[](int r)
    {
        if (r == 0)
            return x;
        if (r == 1)
            return y;
    }
    friend std::ostream &operator<<(std::ostream &out, Vector2d &v)
    {
        out << "(" << v.x << "," << v.y << ")";
        return out;
    }
};
int main()
{
    Vector2d v1(1, 2), v2(4, 6);
    std::cout << "|v1-v2|=" << v1 - v2 << std::endl;
    std::cout << "v1.x=" << v1[0] << ",v2.y=" << v2[1] << std::endl;
    return 0;
}