#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.hpp"
using namespace std;

extern const int constintest=100;

int PrintLongSizeL(int argc, char *argv[])
{
    cout<<"long long sizeof is "<<sizeof(long)<<endl;
    int  isizeoflong =sizeof(long);
    isizeoflong =sizeof(long)*8;
    unsigned long  lmaxlong =1;
    for(int i=0; i<isizeoflong-1; i++)
        lmaxlong*=2;
    cout<<"long sizeof is "<<sizeof(long)<<endl;
    cout<<"max long is "<<lmaxlong<<endl;
    cout<<"int sizeof is "<<sizeof(int)<<endl;
    return 0;
}

int one()
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

int two(int argc,char * argv[] )
{
    //测试函数原型作用域及可见性
    cout<<"in test......\n测试函数原型作用域及可见性"<<endl;
    cout<<"end test......"<<endl;
    return 0;
}

int three( int argc, char *argv[])
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

int four(int argc,char * argv[] )
{
    int i=100;
    int &x=i;
    cout<<x<<endl;
    cout<<i<<endl;
    x++;
    cout<<x<<endl;
    cout<<i<<endl;
    i++;
    cout<<x<<endl;
    cout<<i<<endl;
    return 0;
}

int five(int argc,char * argv[] )
{
    cout<<"line one\n" "line two"
        "line one\n" "line two"
        <<endl;
    cout<<constintest*2<<endl;
    return 0;
}

int star()
{
    string strStarLine=string(60,'*');
    cout<<strStarLine<<endl;
    return 0;
}

int six(int argc,char * argv[] )
{
    star();
    return 0;
}

int RunMyTestFN(int argc, char *argv[])
{
    six(argc,argv);
    return 0;
}

int t(int argc,char * argv[] )
{
    return 0;
}

