#include <cassert>

#include "payroll.h"

int payroll(int hourly_rate, int hours_worked) {
	assert( hourly_rate > 0 && "hourly rate should be positive");
	assert( hours_worked >= 0 && "cannot work negative hours");

	int base_salary = hours_worked * hourly_rate;
	if ( hours_worked <= 40 ) return base_salary;

	if ( hours_worked <= 45 ) 
		return base_salary + (hours_worked - 40) * hourly_rate / 2;
	
	return base_salary 
		+ (5 * hourly_rate / 2) 
		+ ((hours_worked - 45) * hourly_rate);
}