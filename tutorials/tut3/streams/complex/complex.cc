#include <string>
#include <iostream>
#include <sstream>
using namespace std;

const int DEBUG = 1;

string complexNumberMult(string complex_a, string complex_b) {
	int real_a, im_a, real_b, im_b;
	char buffer;
	
	istringstream stream_a(complex_a), stream_b(complex_b);
	ostringstream ans;
	
	stream_a >> real_a;
	stream_a >> buffer; // buffer is '+'
	stream_a >> buffer; // buffer is 'i'
	stream_a >> im_a;

	stream_b >> real_b;
	stream_b >> buffer; // buffer is '+'
	stream_b >> buffer; // buffer is 'i'
	stream_b >> im_b;

	if (DEBUG) {
		cerr << buffer << endl;
		cerr << stream_a.str() << endl;
		cerr << stream_b.str() << endl;
	}

	ans << real_a * real_b - im_a * im_b; // putting in the real part
	ans << "+i"; // putting in "+i"	
	ans << real_a * im_b + real_b * im_a; // putting in the imaginary part

	return ans.str();
}


int main (int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " a+ib c+id" << endl;
		return 1;
	}

	cout << complexNumberMult(argv[1], argv[2]) << endl;
}
