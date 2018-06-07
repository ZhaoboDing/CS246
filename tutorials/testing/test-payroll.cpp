#include <iostream>

#include "payroll.h"

int main(int argc, char** argv) {
	// tests argument parsing
	for ( int i = 1; i < argc; ++i ) std::cout << argv[i] << std::endl;

	// tests payroll program
	while ( true ) {
		int hourly_rate;
		int hours_worked;

		if ( ! ( std::cin >> hourly_rate ) ) break;
		if ( ! ( std::cin >> hours_worked ) ) break;

		std::cout << payroll(hourly_rate, hours_worked) << "\n" << std::endl;
	}
}