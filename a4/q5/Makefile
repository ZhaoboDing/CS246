# a4q5 Makefile
CXX = g++
CXXFLAGS = -std=c++14 -MMD -Werror=vla -Wall -Wextra -Wpedantic -g
EXEC = a4q5
OBJECTS = main.o cell.o subject.o graphicdisplay.o grid.o window.o textdisplay.o observer.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
