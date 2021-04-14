#include <iostream>
#include <iomanip>

class Point {
protected: 
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x; this->y = y;
    }
    Point(int x) {
        this->x = x; this->y = 0;
    }
    Point() {
        this->x = this->y = 0;
    }
    virtual void print() {
        std::cout << '[' 
            << std::setw(3) << this->x << ',' 
            << std::setw(3) << this->y << ']' 
            << std::endl;
    }
    virtual ~Point() {}
};

class Point3D : public Point {
protected:
    int z;
public:
    Point3D(int x, int y, int z) : Point(x, y) {
        this->z = z;
    }
    Point3D(int x, int y) : Point(x, y) {
        this->z = 0;
    }
    Point3D(int x) : Point(x) {
        this->y = this-> z = 0;
    }
    Point3D() : Point() {
        this->z = 0;
    }
    virtual void print() {
        std::cout << '[' 
            << std::setw(3) << this->x << ',' 
            << std::setw(3) << this->y << ',' 
            << std::setw(3) << this->z << ']' 
            << std::endl;
    }
    virtual ~Point3D() {}
};

int main(int arg, char** args) {
    Point* p = new Point3D();
    p->print();
    return 0;
}