#include <iostream>
using namespace std;

// A class A
struct A {
    int a;
    A(int a) : a{a} {};
};

// B inherits from A. B IS AN A
struct B : public A {
    int b;
    B(int a, int b) : A{a}, b{b} {};
};

// Two examples
void inheritance();
void lists();

int main() {
    // UNCOMMENT the following examples as you wish

    // inheritance(); // Example 1: Polymorphism
    // lists();       // Example 2: Array Polymorphism
}

// Polymorphism Example
void inheritance() {
    A a = B{1, 2};
    cout << "1. A a = B{1,2}" << endl;
    cout << a.a << endl << endl;

    B b{3, 4};
    a = b;
    cout << "2. a = b; (b is [3,4])" << endl;
    cout << a.a << endl << endl;

    A *a2 = &b;
    cout << "3: A* a2 = &b;" << endl;
    cout << a2->a << endl;

    // B b2 = A{1}; // THIS IS AN ERROR
}

// Array polymorphism example
void lists() {
    B arr[2] = {{1, 2}, {3, 4}}; // initializing array of two B's

    cout << "Initial array:" << endl;
    cout << "First element: " << arr[0].a << ", " << arr[0].b << endl;
    cout << "Second element: " << arr[1].a << ", " << arr[1].b << endl << endl;

    A *arrA = arr;

    arrA[0] = A{10};
    arrA[1] = A{7};

    cout << "After assigning new elements:" << endl;
    cout << "First element: " << arr[0].a << ", " << arr[0].b << endl;
    cout << "Second element: " << arr[1].a << ", " << arr[1].b << endl;
}
