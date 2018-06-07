#include <iostream>
#include <string>
using namespace std;

int main() {
    int *pi = new int{5};
    cout << "The integer is: " << *pi << endl
         << "Please type in an integer:" << endl;
    cin >> *pi;
    cout << "The integer is now: " << *pi << endl;

    int *arr = new int[5];
    cout << "Please enter 5 integers:" << endl;
    for(int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }
    cout << "The integer array is:";
    for(int i = 0; i < 5; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;

    delete pi;
    delete[] arr;
}
