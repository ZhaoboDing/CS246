# a3q2 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Wall -Werror -Wextra -Wpedantic -g
EXEC = a3q2
OBJECTS = main.o makefile.o target.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
