CC= g++

CXXSTD=c++17
DEBUGFLAGS = -g -Wnoall
OPTIMIZATION = -O3
INCLUDEDIRECTORY = -Iinclude
CXXFLAGS = $(OPTIMIZATION) $(DEBUGFLAGS) -std=$(CXXSTD) $(INCLUDEDIRECTORY)

all: rebuild debug

debug: 

rebuild: clean asm main

main: obj
	@echo "Build the tagert file ......"
	${CC} ${CXXFLAGS} -o main *.o 
	@echo "Ok!......the tagert file <main> is scuessful make!"

obj: *.cpp
	@echo "Build the object file ......"
	${CC} ${CXXFLAGS} -c *.cpp 

asm:
	@echo "Build the Asm file ......"
	${CC} ${CXXFLAGS} -S *.cpp

clean:
	clear
	@echo "Clean the useless file ......"
	rm *.o *.s *.out main -f

