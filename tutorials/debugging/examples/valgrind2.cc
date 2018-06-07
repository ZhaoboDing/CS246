#include <iostream>
using namespace std;
int main() {
    int * x;
    cout << x << endl; // uninitialized read
    x = new int[10];
    x[0] = x[10];      // subscript error, invalid read
    x[10] = 10;        // subscript error, invalid write
    delete[] x;
    delete[] x;        // invalid free
    x[0] = 3;          // dangling pointer, invalid write
}
