#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " [Start col] [End col]" << endl;
		return 1;
	}

	int i = stoi(argv[1]);
	int j = stoi(argv[2]);

	if (i < 1) {
		cerr << "The starting column number must be 1 or greater" << endl;
		return 2;
	}

	string buffer;

	int k = 1;
	while (cin >> buffer) {
		// to ensure that there is exactly one space between columns
		// for the first column to be printed, print it
		// without a leading space
		if (i == k) {
			cout << buffer;
		}

		// print the rest of the target columns with a leading space
		else if (i < k && k <= j) {
			cout << ' ' << buffer;
		}

		// check if last character is a semicolon
		// if so, reset variables to start a new line
		if (buffer.at(buffer.length() - 1) == ';') {
			k = 0; // increments to one at end of loop
			cout << endl;
		}
 
		k++;
	}

}
