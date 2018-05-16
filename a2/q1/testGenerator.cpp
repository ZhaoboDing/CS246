#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

const int testSize = 1000;
const int arrayElementBound = 1000;
const int arraySizeLowerBound = 5;
const int arraySizeUpperBound = 100;

void writeSuite()
{
	ofstream fout;
	fout.open("./tests/suiteq1.txt");
	for (int i = 0; i < testSize; i++)
		fout << "test" + to_string(i) << endl;
	fout.close();
}

void createTest(int testNum)
{
	string inputTestName = "./tests/test" + to_string(testNum) + ".in";
	string outputTestName = "./tests/test" + to_string(testNum) + ".out";

	ofstream fout;
	fout.open(inputTestName.c_str());

	int arraySize = rand() % (arraySizeUpperBound - arraySizeLowerBound + 1) + arraySizeLowerBound;

	int r = rand() % (arrayElementBound * 2 + 1) - arrayElementBound;
	int ans = r, cur = max(0, r);
	fout << r;

	for (int i = 1; i <= arraySize; i++)
	{
		int r = rand() % (arrayElementBound * 2 + 1) - arrayElementBound;

		cur += r;
		ans = max(ans, cur);
		cur = max(cur, 0);
		fout << ' ' << r;
	}

	fout.close();
	fout.open(outputTestName.c_str());
	fout << ans;
	fout.close();

	return;
}

int main()
{
	srand((unsigned)time(NULL));

	writeSuite();
	for (int i = 1; i <= testSize; i++)
		createTest(i);

	return 0;
}
