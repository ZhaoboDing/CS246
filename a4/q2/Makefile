# a4q2 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Werror=vla -Wall -Wextra -Wpedantic -g
EXEC = a4q2
OBJECTS = main.o Expression.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
