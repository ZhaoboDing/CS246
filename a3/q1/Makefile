# a3q1 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Wall -Werror -Wextra -Wpedantic -g
EXEC = a3q1
OBJECTS = main.o drone.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
