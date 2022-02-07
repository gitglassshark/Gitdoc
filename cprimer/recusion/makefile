CC= g++

CXXDEBUGFLAGS = -g -Wall -I$(INCLUDEDIRECTORY) -std=c++17
CXXFLAGS = -w -O3 -I$(INCLUDEDIRECTORY) -std=c++17

INCLUDEDIRECTORY = ./include/
SRCDIRECTORY = ./src/
OUTDIRECTORY = ./out/
SRCFILES = $(wildcard *.c *.cpp ./src/*.cpp ./src/*.c ./include/*.cpp ./include/*.c)
HEADFILES = $(wildcard *.hpp *.h ./include/*.hpp ./include/*.h)
OBJECTS  = $(patsubst %.cpp,%.o,$(SRCFILES))
DEBUGOBJECTS =$(OBJECTS)

.PHONY: build run debugrun rebuild asm debug clean

build: main
	#build:

run:main
	./main
	
debugrun:debug
	gdb ./main

rebuild: clean main
	#rebuild

debug: clean  
	#debugobj "Build the debug object file ......"
	${CC} ${CXXDEBUGFLAGS} -c $(SRCFILES) 
	#debug "Build the tagert file for debug......"
	${CC} ${CXXDEBUGFLAGS} -o main $(DEBUGOBJECTS) 
	@echo "Ok!......the debug tagert file <main> is scuessful make!"
	
main: $(OBJECTS)
	#main "Build the tagert file main......"
	${CC} ${CXXFLAGS} -o $@ $? 
	@echo "Ok!......the tagert file <main> is scuessful make!"

$(OBJECTS): %.o:%.cpp 
	#obj "Build the object file ......"
	${CC} ${CXXFLAGS} -c $? -o $@
	
indent:$(SRCFILES) $(HEADFILES)
	#indent
	indent -bad -bap -bbb -bbo -nbc -bl -bli0 -bls -c33 -cd33 -ncdb -ncdw -nce -cli0 -cp33 -cs -d0 -nbfda -di2 -nfc1 -nfca -hnl -ip5 -l75 -lp -pcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -i4 -ts4 -ut $^ 

asm:$(SRCFILES)
	#asm "Build the Asm file ......"
	${CC} ${CXXFLAGS} -S $?

clean:
	#clean "Clean the useless file ......"
	@rm *.s *.o *~  main -f
	@find . -name "*~" -exec rm -f {} \;
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.s" -exec rm -f {} \;
	@find . -name "main" -exec rm -f {} \;
