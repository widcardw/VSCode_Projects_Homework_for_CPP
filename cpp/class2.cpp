#include <iostream>
using namespace std;

class B {
public:
    B(int a=0) {
        cout << "B" << endl;
    }
    ~B() {
        cout << "~B" << endl;
    }
};

class A: public B {
public:
    A() {
        cout << "A"<< endl;
    }
    ~A() {
        cout << "~A" << endl;
    }
};

void f() {
    static A a;
    cout << "f()" << endl;
}

int main()
{
    f();
    f();
    return 0;
}