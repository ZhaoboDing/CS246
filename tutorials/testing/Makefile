payroll.o: payroll.cpp payroll.h
	g++ -o payroll.o -c payroll.cpp

test-payroll: test-payroll.cpp payroll.h payroll.o
	g++ -o test-payroll test-payroll.cpp payroll.o
