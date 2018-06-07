# example2/Makefile
CXX=g++                                                  #compiler name
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -g  #options to pass

main: main.o book.o textbook.o comic.o
	${CXX} ${CXXFLAGS} main.o book.o textbook.o comic.o -o main

book.o: book.cc book.h
	${CXX} ${CXXFLAGS} -c book.cc
textbook.o: textbook.cc textbook.h book.h
	${CXX} ${CXXFLAGS} -c textbook.cc
comic.o: comic.cc comic.h book.h
	${CXX} ${CXXFLAGS} -c comic.cc
main.o: book.h textbook.h comic.h main.cc
	${CXX} ${CXXFLAGS} -c main.cc

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
