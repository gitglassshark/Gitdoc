CC= clang
#CC= g++

DEBUGS = -g -Wall -I$(INCD) -std=c++17
CXXFLAGS = -lstdc++ -w -O0 -I$(INCD) -std=c++17

TAGET = main
INCD = ./include
SRCD = ./src .
OUTD = ./out
VPATH = ./src:./include
SRCS = $(wildcard $(SRCD)/*.cpp $(SRCD)/*.c $(INCD)/*.cpp $(INCD)/*.c)
HEADS = $(wildcard *.hpp *.h ./$(INCD)/*.hpp ./$(INCD)/*.h)
FILES = $(HEADS) $(SRCS)
OBJS  := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY: all debugrun rebuild debug  asm clean 

all: $(TAGET)

	
debugrun:debug
	gdb ./$(TAGET)

rebuild:clean $(TAGET)

debug: CXXFLAGS = $(DEBUGS)
debug: clean $(TAGET) 

$(TAGET):$(OBJS)
	${CC} ${CXXFLAGS} -o $@ $? 
	
$(OBJS): %.o:%.cpp 
	${CC} ${CXXFLAGS} -c $? -o $@
	
indent:$(FILES)
	indent -bad -bap -bbb -bbo -nbc -bl -bli0 -bls -c33 -cd33 -ncdb -ncdw -nce -cli0 -cp33 -cs -d0 -nbfda -di2 -nfc1 -nfca -hnl -ip5 -l75 -lp -pcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss -i4 -ts4 -ut $? 

linux:$(FILES)
	astyle --style=linux $(FILES)

gnu:$(FILES)
	astyle --style=gnu $(FILES)
	
bsd:$(FILES)
	astyle --style=bsd $(FILES)

google:$(FILES)
	astyle --style=google  $(FILES)

asm:$(SRCS)
	${CC} ${CXXFLAGS} -S $?

clean:
	#clean: Clean the useless file ......
	@rm *.s *.o *~  $(TAGET) -f
	@find . -name *~ -exec rm -f {} \;
	@find . -name *.o -exec rm -f {} \;
	@find . -name "*.orig" -exec rm -f {} \;
	@find . -name *.s -exec rm -f {} \;
	@find . -name $(TAGET) -exec rm -f {} \;

test:
	make -B -n all
	make -B -n debug
	make -B -n indent
	make -B -n asm
	make -B -n clean

testvar:rebuild
	@echo -n  DEBUGS: 
	@echo   $(DEBUGS)
	@echo -n  CXXFLAGS: 
	@echo   $(CXXFLAGS)
	@echo -n  TAGET: 
	@echo   $(TAGET)
	@echo -n  INCD: 
	@echo   $(INCD)
	@echo -n  SRCD: 
	@echo   $(SRCD)
	@echo -n  OUTD: 
	@echo   $(OUTD)
	@echo -n  VPATH: 
	@echo   $(VPATH)
	@echo -n  SRCS: 
	@echo   $(SRCS)
	@echo -n  HEADS: 
	@echo   $(HEADS)
	@echo -n  FILES: 
	@echo   $(FILES)
	@echo -n  OBJS: 
	@echo   $(OBJS)
