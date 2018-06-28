#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array a;
    for (int i = 10; i < 100; i += 7) {
        a.insert_back(i);
    }
    cout << a;
    for (int &elem : a) {
        elem++;
    }
    cout << a;
    for (int i = 10; i < 100; i += 19) {
        a.insert_back(i);
    }
    for (const int &elem : a) {
        cout << elem << endl;
    }
}
