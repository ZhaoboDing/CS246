#include <iostream>
using namespace std;

// NOTE: First try this example (both parts) without modification, then add a
// protected: keyword at the indicated spot and try it again

class A {
    int a;

    // ADD PROTECTED KEYWORD HERE
    void setA(int a) {
        this->a = a;
    }

public:
    A(int a) : a{a} {};

    void changeA() {
        setA(5);
        cout << "Changing A now" << endl;
    }
};

// B inherits from A. B IS AN A
class B : public A {
    int b;

public:
    B(int a, int b) : A{a}, b{b} {};

    void changeB(int b) {
        this->b = b;
        setA(b);
        cout << "Changing B now" << endl;
    }
};

int main() {
    // PART A
    A a{1};
    a.changeA();

    // PART B
    B b{2, 3};
    b.changeB(20);

    // cout << b.setA(5) << endl; // THIS DOES NOT WORK IN BOTH TRIES
}
