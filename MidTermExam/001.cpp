#include <iostream>
class Rect
{
    double length, width;

public:
    Rect(double l = 0, double w = 0) : length(l), width(w) {}
    void Set(double l, double w)
    {
        if (l <= 0 || l >= 50 || w <= 0 || w >= 50)
        {
            std::cout << "Length or width should be in (0, 50)!" << std::endl;
            exit(0);
        }
        length = l;
        width = w;
    }
    double GetArea()
    {
        return length * width;
    }
};