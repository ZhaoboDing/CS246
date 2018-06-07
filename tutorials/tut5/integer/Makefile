CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -fno-elide-constructors
EXEC = bigInteger
OBJECTS = main.o bigInteger.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
