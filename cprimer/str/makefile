CC= g++

CXXSTD=c++17
DEBUGFLAGS = -g -Wall
OPTIMIZATION = -O3 -w
INCLUDEDIRECTORY = include/
OUTDIRECTORY = out/
CXXFLAGS = $(OPTIMIZATION) -I$(INCLUDEDIRECTORY) -std=$(CXXSTD)  

.PHONY:build all rebuild asm debug debugobj obj asm clean

build: main
	#build:

all: rebuild asm
	#all

debug:clean debugobj
	#debug
	@echo "Build the tagert file for debug......"
	${CC} ${CXXFLAGS} $(DEBUGFLAGS) -o main *.o 
	@echo "Ok!......the debug tagert file <main> is scuessful make!"

debugobj: *.cpp inden
	#debugobj
	@echo "Build the debug object file ......"
	${CC} ${CXXFLAGS} $(DEBUGFLAGS) -c *.cpp 
	
rebuild: clean main
	#rebuild

main: obj
	#main
	@echo "Build the tagert file ......"
	${CC} ${CXXFLAGS} -o main *.o 
	@echo "Ok!......the tagert file <main> is scuessful make!"

obj: *.cpp inden
	#obj
	@echo "Build the object file ......"
	${CC} ${CXXFLAGS} -c *.cpp 

asm: inden
	#asm
	@echo "Build the Asm file ......"
	${CC} ${CXXFLAGS} -S *.cpp 

inden:
	#inden
	@indent -bad -bap -bbb -bbo -nbc -bl -bli0 -bls -c33 -cd33 -ncdb -ncdw -nce -cli0 -cp33 -cs -d0 -nbfda -di2 -nfc1 -nfca -hnl -ip5 -l75 -lp -pcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -i4 -ts4 -ut *.cpp $(INCLUDEDIRECTORY)*.hpp

clean:
	#clean
	echo "Clean the useless file ......"
	rm *.s *.o *~  main -f
	find . -name "*~" -exec rm -f {} \;
	find . -name "*.o" -exec rm -f {} \;
	find . -name "*.s" -exec rm -f {} \;
	find . -name "main" -exec rm -f {} \;
