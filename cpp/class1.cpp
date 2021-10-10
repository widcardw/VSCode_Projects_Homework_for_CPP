#include <iostream>
using namespace std;
class B {
private: 
    int x, y;
public:
    B(int i, int j) {
        x = i; y = j;
    }
    virtual int fun() {
        return x * y;
    }
    virtual int fun(int i) {
        return x + y;
    }
    int get(int &a) {
        a = x;
        return y;
    }
};

class I: public B {
private: 
    int z;
public:
    I(int i, int j, int k): B(i, j) {
        z = i + j + k;
    }
    int fun() {
        int a, b;
        b = get(a);
        return (a + b + z) / 3;
    }
};

int main()
{
    I obj(2, 4, 10);
    B p1 = obj;
    cout << p1.fun() << endl;
    B *p3 = &obj;
    cout << p3->fun() << endl;
    cout << p3->fun(2) << endl;
    return 0;
}