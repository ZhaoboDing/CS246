#include <iostream>
using namespace std;

struct Vec{
	int x;
	int y;

	// Comment/uncomment the following constructors
	// as needed and see what happens to the main
	// function!

	Vec(int x, int y) {
		// Why do we need this here?
		this->x = x;
		this->y = y;
	}

	// Is this using MILs?
	Vec(int x): x{x}, y{0} {}

	// Is this a default constructor?
	Vec() {
		x = y = 0;
	}
};

// Pretty prints the vector
ostream &operator<<(ostream &out, Vec &vec){
	out << "The vector in R2 is (" << vec.x << "," << vec.y << ")" << endl;
	return out;
} 

// Pretty reads the vector
void read(int &x, int &y){
	cout << "Enter two numbers:" << endl;
    cin >> x >> y;
}

int main() {
	// 2 parameter ctor
	int x,y;
	read(x,y);
	Vec v1{x,y};
	cout << v1;

	// 1 parameter ctor
    read(x,y);
	Vec v2{x};
    cout << v2;

	// default ctor
	read(x,y);
	Vec v3;
	cout << v3;
}

