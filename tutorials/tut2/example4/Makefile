# example4/Makefile
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g
OBJECTS=main.o book.o textbook.o comic.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=main

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

