# example3/Makefile
CXX=g++                                                  #compiler name
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -g  #options to pass

main: main.o book.o textbook.o comic.o
	${CXX} ${CXXFLAGS} main.o book.o textbook.o comic.o -o main

book.o: book.cc book.h

textbook.o: textbook.cc textbook.h book.h

comic.o: comic.cc comic.h book.h

main.o: book.h textbook.h comic.h main.cc

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
