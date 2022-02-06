CC= g++

CXXSTD=c++17
DEBUGFLAGS = -g -w -dumpdir out
OPTIMIZATION = -O3
INCLUDEDIRECTORY = include/
OUTDIRECTORY = out/
CXXFLAGS = $(OPTIMIZATION) $(DEBUGFLAGS) -I$(INCLUDEDIRECTORY) -std=$(CXXSTD)  

all: rebuild debug

debug: 

rebuild: clean asm main

main: obj
	@echo "Build the tagert file ......"
	${CC} ${CXXFLAGS} -o main *.o 
	@echo "Ok!......the tagert file <main> is scuessful make!"

obj: *.cpp inden
	@echo "Build the object file ......"
	${CC} ${CXXFLAGS} -c *.cpp 

asm: inden
	@echo "Build the Asm file ......"
	${CC} ${CXXFLAGS} -S *.cpp 

inden:
	@indent -bad -bap -bbb -bbo -nbc -bl -bli0 -bls -c33 -cd33 -ncdb -ncdw -nce -cli0 -cp33 -cs -d0 -nbfda -di2 -nfc1 -nfca -hnl -ip5 -l75 -lp -pcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -i4 -ts4 -ut *.cpp $(INCLUDEDIRECTORY)*.hpp

clean:
	@echo "Clean the useless file ......"
	rm *.s *.o  main -f

