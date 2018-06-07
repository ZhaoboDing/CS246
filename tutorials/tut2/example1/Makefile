# example1/Makefile

# means main depends on these dependencies
# if all of the dependencies are up to date, then execute
# the build command below
main: main.o book.o textbook.o comic.o
	# specifies how to build main
	g++ -std=c++14 main.o book.o textbook.o comic.o -o main

book.o: book.cc book.h
	g++ -std=c++14 -c book.cc
textbook.o: textbook.cc textbook.h book.h
	g++ -std=c++14 -c textbook.cc
comic.o: comic.cc comic.h book.h
	g++ -std=c++14 -c comic.cc
main.o: book.h textbook.h comic.h main.cc
	g++ -std=c++14 -c main.cc
