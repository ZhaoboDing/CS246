# a3q4 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Wall -Werror -Wextra -Wpedantic -g
EXEC = a3q4
OBJECTS = main.o date.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
