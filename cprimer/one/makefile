CC= g++

CXXSTD=c++17
DEBUGFLAGS =  -g  -Wall
OPTIMIZATION =  -O3
INCLUDEDIRECTORY =-Iinclude
CXXFLAGS =  $(OPTIMIZATION)  $(DEBUGFLAGS)  -std=$(CXXSTD)  $(INCLUDEDIRECTORY)

all: rebuild asm main debug

debug: 

build: rebulid

rebuild: clean 

main: main.o fun.o
	@echo "build the tagert file ......"
	${CC} ${CXXFLAGS}  -o  main  main.o  fun.o
	@echo "Ok!......the tagert file <main> is scuessful make!"

main.o: main.cpp
	${CC} ${CXXFLAGS}  -c  main.cpp  

fun.o: fun.cpp
	${CC} ${CXXFLAGS}  -c  fun.cpp  

asm:
	${CC} ${CXXFLAGS}  -S  *.cpp

clean:
	clear
	@echo "clean the useless file ......"
	rm  *.o  *.s  *.out  main  -f

