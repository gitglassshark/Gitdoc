CC= g++

DEBUGS = -g -Wall -I$(INCD) -std=c++17
CXXFLAGS = -w -O0 -I$(INCD) -std=c++17

TAGET = main
INCD = ./include
SRCD = ./src .
OUTD = ./out
VPATH = ./src:./include
SRCS = $(wildcard $(SRCD)/*.cpp $(SRCD)/*.c $(INCD)/*.cpp $(INCD)/*.c)
HEADS = $(wildcard *.hpp *.h ./$(INCD)/*.hpp ./$(INCD)/*.h)
FILES = $(HEADS) $(SRCS)
OBJS  := $(patsubst %.cpp,%.o,$(SRCS))
#$(patsubst %.c,%.o,$(SRCS)

.PHONY: all run debugrun rebuild debug  asm clean 

all: $(TAGET)
	#build: Ok!......the tagert file <$(TAGET)> is scuessful make!

run:$(TAGET)
	./$(TAGET)
	
debugrun:debug
	gdb ./$(TAGET)

rebuild:clean $(TAGET)
	#rebuild

debug: CXXFLAGS = $(DEBUGS)
debug: clean $(TAGET) 
	#debug: Build the debug object file ......Ok!The debug mode tagert file <$(TAGET)> is scuessful make!

$(TAGET):$(OBJS)
	#$(TAGET): Build the tagert file $(TAGET)......
	${CC} ${CXXFLAGS} -o $@ $? 
	#$(TAGET): Build the tagert file $(TAGET) is scuessful make!
	
$(OBJS): %.o:%.cpp 
	#obj: Build the object file ......
	${CC} ${CXXFLAGS} -c $? -o $@
	
indent:$(FILES)
	#indent $(FILES)
	indent -bad -bap -bbb -bbo -nbc -bl -bli0 -bls -c33 -cd33 -ncdb -ncdw -nce -cli0 -cp33 -cs -d0 -nbfda -di2 -nfc1 -nfca -hnl -ip5 -l75 -lp -pcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -i4 -ts4 -ut $? 

asm:$(SRCS)
	#asm: Build the Asm file ......
	${CC} ${CXXFLAGS} -S $?

clean:
	#clean: Clean the useless file ......
	@rm *.s *.o *~  $(TAGET) -f
	@find . -name *~ -exec rm -f {} \;
	@find . -name *.o -exec rm -f {} \;
	@find . -name *.s -exec rm -f {} \;
	@find . -name $(TAGET) -exec rm -f {} \;

test:
	make -B -n
