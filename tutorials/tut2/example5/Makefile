# example4/Makefile
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g
OBJECTS=main.o book.o textbook.o comic.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=main

TESTDIR=test
EXECSDIR=../executables
EXECGIVEN=${EXEC}
SUITE=suite.txt

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

# @ silences output
test:
	@cp ${EXECSDIR}/${EXECGIVEN} ${TESTDIR}                 # copy over given exec
	@mv ${TESTDIR}/${EXECGIVEN} ${TESTDIR}/sol_${EXECGIVEN} # prefix it with sol_
	@cp ${EXEC} ${TESTDIR}                                  # copy over your exec
	@(cd ${TESTDIR}\									    # go into test directory
	&& ./produceOutputs ${SUITE} ./sol_${EXECGIVEN}\        # run produceOutputs
	&& ./runSuite ${SUITE} ./${EXEC})                       # run runSuite
.PHONY: test
