#include <stdexcept>

int foo(int x){
	if (x != 246) {
		throw invalid_argument("Not 246!");
	}
	return x;

}

int main() {
	int x = 0;
	try {
		// causes an exception
		// x will still have a value of 0,
		//  because foo never returned
		x = foo(245);
	}

	catch (invalid_argument& ia) {
		// catches the exception
		// program flow continues here
		// what() method retrives the string the exception was constructed with
		cout << ia.what() << endl;
	}

	// program flow continues
	foo(246); // will be executed
}
