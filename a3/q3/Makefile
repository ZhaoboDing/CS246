# a3q3 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Wall -Werror -Wextra -Wpedantic -g
EXEC = a3q3
OBJECTS = main.o intSet.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
