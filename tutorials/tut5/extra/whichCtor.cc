#include <iostream>
#include <string>
using namespace std;

// This example looks at what ctors/operators are called in what syntax

// the flag
// -fno-elide-constructors
// disables copy elision


// auxilliary functions to colour code output

// could be cool to use when you do your project
// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

// red: ctor/dtor/operator calls
// cyan: code in main
// green: code in giveS(), giveS2() or giveS3()
string makeRed(const string& s) {
	return "\033[31m" + s + "\033[0m";
}


string makeGreen(const string& s) {
	return "\033[32m" + s + "\033[0m";
}


string makeCyan(const string& s) {
	return "\033[36m" + s + "\033[0m";
}


struct S {
	S() {
		cout << makeRed("Constructor") << endl;
	}

	S(const S& other) {
		cout << makeRed("Copy Constructor") << endl;
	}

	S(S&& other) {
		cout << makeRed("Move Constructor") << endl;
	}


	S& operator=(const S& rhs) {
		cout << makeRed("Copy Assignment Operator") << endl;
	}

	S& operator=(S&& rhs) {
		cout << makeRed("Move Assignment Operator") << endl;
	}

	~S() {
		cout << makeRed("Destructor") << endl;
	}
};


S giveS() {
	cout << makeGreen("giveS: return {};") << endl;
	return {};
}


// Only behaves differently than giveS() if elision is disabled
S giveS2() {
	cout << makeGreen("giveS2: S s;") << endl;
	S s;
	cout << makeGreen("giveS2: return s;") << endl;
	return s;
}


// Calls copy ctor instead of move ctor upon return, why?
S giveS3() {
	cout << makeGreen("giveS3: S* s = new S;") << endl;
	S* s = new S;
	cout << makeGreen("giveS3: return *s") << endl;
	return *s;
}


int main() {
	cout << makeCyan("S s1;") << endl;
	S s1;
	cout << endl;

	cout << makeCyan("S s2 = s1;") << endl;
	S s2 = s1;
	cout << endl;

	cout << makeCyan("S s3 = giveS();") << endl;
	S s3 = giveS();
	cout << endl;

	cout << makeCyan("s1 = s2") << endl;
	s1 = s2;
	cout << endl;

	cout << makeCyan("s3 = giveS();") << endl;
	s3 = giveS();
	cout << endl;

	cout << makeCyan("s3 = giveS2();") << endl;
	s3 = giveS2();
	cout << endl;

	cout << makeCyan("S s4 = giveS2();") << endl;
	S s4 = giveS2();
	cout << endl;

	cout << makeCyan("s4 = giveS3()") << endl;
	s4 = giveS3();
	cout << endl;
}


