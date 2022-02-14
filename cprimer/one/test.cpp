#include <iostream> //
#include <stdio.h>
#include <stdlib.h>
#include "mylib.hpp"


using namespace std;

int testone();
int testtwo(int argc,char * argv[] );
int testthree( int argc, char *argv[]);

int RunMyTestFN(int argc, char *argv[])
{
    Print_NCharx('a',100);
    PrintClassSize();
    return 0;
}

int testtwo(int argc,char * argv[] )
{
    //测试函数原型作用域及可见性
    cout<<"in test......\n测试函数原型作用域及可见性"<<endl;
    cout<<"end test......"<<endl;
    return 0;
}

int PrintLongSizeL(int argc, char *argv[])
{
    //     testthree( argc, argv);
    //     testone();
    //     testtwo(argc,argv );
    cout<<"long long sizeof is "<<sizeof(long)<<endl;
    int  isizeoflong =sizeof(long);
    isizeoflong =sizeof(long)*8;
    unsigned long  lmaxlong =1;
    for(int i=0;i<isizeoflong-1;i++)
        lmaxlong*=2;
    cout<<"long sizeof is "<<sizeof(long)<<endl;
    cout<<"max long is "<<lmaxlong<<endl;
    cout<<"int sizeof is "<<sizeof(int)<<endl;

    return 0;
}


int FCopyFileDelteNCharFN(char *pcFormFile,char *pcDestFile,char cCharIsNDelete)
{
    //编写一个程序，将输入文件复制到输出文件，在复制过程中，要求将输入
    //文件中的多个连续空格转化为一个空格并复制到输出文件中，其它字符不
    //变，原样复制。。
    FILE *fIn,*fOut;
    fIn=fopen(pcFormFile,"r");
    fOut=fopen(pcDestFile,"w+");
    if((!fIn)||(!fOut))
    {
        cout<<"File error!exit......\n";
        exit(0);
    }
    int c;
    cCharIsNDelete=' ';
    long long iS=0;
    while((c=fgetc(fIn))!=EOF){
        if(c==cCharIsNDelete){
            if(!iS++)
                fputc(c,fOut);
        }
        else{
            fputc(c,fOut);
            iS=0;
        }

    }
    fclose(fIn);
    fclose(fOut);
    return 0;
}


int testthree( int argc, char *argv[])
{
    int iArgcTotalL=0;
    cout<<"打印参数列表："<<endl;
    for(int i=0; i<argc; i++)
    {
        iArgcTotalL+=atoi(argv[i]);
        cout<<argv[i]<<endl;
    }
    cout<<iArgcTotalL<<endl;
    return 0;
}

int testone()
{

    // 测试变量作用域,
    int key=100;
    {
        cout<<"in {}key is "<<endl;
        int key=200;
        cout<<key<<endl;
    }
    cout<<key<<endl;
    int i=22;
    for(int i=0; i<9; i++)
    {
        if(i==8)
        {
            cout<<"in if, i=8"<<i<<endl;
        }
        if(i==9)
        {
            cout<<i<<endl;
        }
    }
    cout<<i<<endl;
    return 0;
}



