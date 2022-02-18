#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.hpp"
using namespace std;

extern const int constintest=100;

char t='\t';
char e='\n';
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

int none()
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

int six(int argc,char * argv[] )
{
    star();
    //    string strArgOne=argv[1];
    //    cout<<atoi(strArgOne)<<endl;
    string strgetline;
    if(strgetline.empty())
        cout<<"string is empty now.\n";
    cout<<"string size is "<<strgetline.size()<<endl;
    getline(cin,strgetline);
    star();
    for(char c:strgetline)
        cout<<toupper(c);
    cout<<endl;
    star();
    for(char &d:strgetline)
        d=toupper(d);
    cout<<strgetline<<endl;
    star();
    int narray[100]= {0};
    for(int a:narray)
        cout<<a++<<'\t';
    for(int c:narray)
        cout<<c<<'\t';
    cout<<endl;
    //     cout<<strgetline<<endl;
    return 0;
}

int seven(int argc,char * argv[] )
{
    star();
    string strline;
    getline(cin,strline);
    cout<<strline<<endl;
    newline();
    for(char &a:strline)
        {
            if(ispunct(a))
                a=' ';
        }
    cout<<strline<<endl;
    cout<<endl;
    return 0;
}

int eight(int argc,char * argv[] )
{
    vector<string> iVecOne(10,"line\n");
    for(auto i:iVecOne)
        cout<<i;
    star();
    string strname("program test.cpp.\n");
    string::iterator iterstarname=strname.begin();
    while(iterstarname!=strname.end())
        cout<<*iterstarname++;
    return 0;
}

int vector_assign(int argc,char * argv[] )
{
    char t='\t';
    char e='\n';
    vector<int> v1,v2,v3;
    vector<int> v4(10,10);
    cout<<"v4:"<<e;
    for(auto v:v4)
        cout<<v<<t;
    cout<<endl;
    star();
    vector<int> v6(v4);
    v6.push_back(100);
    cout<<"v6:"<<e;
    for(auto v:v6)
        cout<<v+1<<t;
    cout<<endl;
    star();
    vector<int> v5(10);
    cout<<"v5:"<<e;
    for(auto v:v5)
        cout<<v<<t;
    cout<<endl;
    star();
    vector<int> v7{10,22,33,44,55};
    cout<<"v7:"<<e;
    for(auto v:v7)
        cout<<v<<t;
    cout<<endl;
    star();

    v1.assign(v7.begin(),v7.end());
    cout<<"v1:"<<e;
    for(auto v:v1)
        cout<<v+2<<t;
    cout<<endl;
    star();

    v2.assign(10,200);
    cout<<"v2:"<<e;
    for(auto v:v2)
        cout<<3+v<<t;
    cout<<endl;
    star();

    v3=v1;
    cout<<"v3:"<<e;
    for(auto v:v3)
        cout<<v<<t;
    cout<<endl;
    star();
    cout<<v3.at(1)<<endl;
    v3.at(1)+=10;
    cout<<v3.at(1)<<endl;
    cout<<v3.back()<<endl;
    cout<<*v3.begin()<<endl;
    cout<<*v3.end()<<endl;
    cout<<*(v3.end()-1)<<endl;
    cout<<*(v3.begin()+(v3.end()-v3.begin())/2)<<endl;
    star();
    cout<<"v1 capacity is "<<t<<v1.capacity()<<e;
    cout<<"v2 capacity is "<<t<<v2.capacity()<<e;
    cout<<"v3 capacity is "<<t<<v3.capacity()<<e;
    cout<<"v4 capacity is "<<t<<v4.capacity()<<e;
    cout<<"v5 capacity is "<<t<<v5.capacity()<<e;
    cout<<"v6 capacity is "<<t<<v6.capacity()<<e;
    cout<<"v7 capacity is "<<t<<v7.capacity()<<e;
    star();
    cout<<"v2:"<<e;
    for(auto v:v2)
        cout<<v<<t;
    cout<<endl;
    v2.clear();
    star();
    cout<<"v2:"<<e;
    for(auto v:v2)
        cout<<v<<t;
    cout<<endl;
    star();
    cout<<"v3:"<<e;
    for(auto v:v3)
        cout<<v<<t;
    cout<<endl;
    v3.resize(2);
    star();
    cout<<"v3:"<<e;
    for(auto v:v3)
        cout<<v<<t;
    cout<<endl;
    v3.resize(5);
    star();
    cout<<"v3:"<<e;
    for(auto v:v3)
        cout<<v<<t;
    cout<<endl;
    star();
    v3=v4;
    cout<<"v3:"<<e;
    for(auto v:v3)
        cout<<v<<t;
    cout<<endl;
    star();
    cout<<"v3[4]:"<<e;
    cout<<v3[4]<<t<<e;
    v3[4]+=20;
    cout<<v3[4]<<t<<e;
    star();
    decltype(v3) vx(v3);
    cout<<vx[4]<<e;
    cout<<vx[3]<<e;
    return 0;
}

int one(int argc,char * argv[] )
{
    string strname("program test.cpp.\n");
    string::iterator iterstarname=strname.begin();
    return 0;
}

int pointerandrefence(int argc,char * argv[] )
{
    int iarray[50];
    int (&rarray)[50]=iarray;
    for(auto &i:iarray)
        {
            i=2;
        }
    star();
    for(auto &i:iarray)
        {
            cout<<i<<t;
        }
    cout<<e;
    star();

    cout<<"print reference rarray value:\n";
    for(auto &i:rarray)
        {
            i=3;
        }
    star();
    for(auto &i:rarray)
        {
            cout<<i<<t;
        }
    cout<<e;
    cout<<"print reference iarray value:\n";
    star();
    for(auto &i:iarray)
        {
            cout<<i<<t;
        }
    cout<<e;
    star(8);
    int *pb=begin(rarray);
    int *pe=end(iarray);
    for(; pb!=pe; pb++)
        cout<<*pb<<t;
    cout<<e;
    star(9);
    char char1[10],char2[10];
    for(char &i:char1)
        i='a';
    *(end(char1)-1)='\0';
    for(char &i:char2)
        i='b';
    *(end(char2)-1)='\0';
    cout<<char1<<e<<char2<<e;
    if(strcmp(char1,char2)==0)
        cout<<"char1 equal char2.\n";
    else
        cout<<"char1 not equal char2.\n";
    cout<<"char1 length is:\t"<<strlen(char1)<<e;
    cout<<"char2 length is:\t"<<strlen(char2)<<e;
    char char3[strlen(char1)+strlen(char2)];
    strcpy(char3,char1);
    strcpy(char3+strlen(char1),char2);
    star(10);
    cout <<char1<<endl;
    cout <<char2<<endl;
    cout <<char3<<endl;
    cout<<"char3 length is:\t"<<strlen(char3)<<e;
    star();
    return 0;
}

int relationoperation(int argc,char * argv[] )
{
    star();
    bool btest1=false;
    bool btest2=false;
    bool btest3=false;
    btest1=argc==2?true:false;
    btest2=atoi(argv[1])==0?true:false;
    btest3=argc==4?true:false;
    if(btest1)
        cout<<"argc is 2"<<e;
    if(btest2)
        cout<<"argv1 is 0"<<e;
    if(btest3)
        cout<<"argc is 4"<<e;
    return 0;
}

int bittest(int argc,char * argv[] )
{
    unsigned int i=1;
    unsigned int j=2;
    star();
    i<<1;
    cout<<i<<e;
    i<<1;
    cout<<i<<e;
    cout<<(i<<1)<<e;
    cout<<(i<<2)<<e;
    cout<<(i<<3)<<e;
    cout<<(i<<4)<<e;
    cout<<(i<<4)%2<<e;
    cout<<(i<<3)%2<<e;
    cout<<(i<<2)%2<<e;
    cout<<(i<<1)%2<<e;
    i<<=1;
    cout<<i<<e;
    i<<=3;
    cout<<i<<e;
    i>>=2;
    cout<<i<<e;
    i=0xffff;
    unsigned int i0=0xffff;
    unsigned int i1=0xfffe;
    unsigned int i2=0xfffd;
    unsigned int i3=0xfffb;
    unsigned int i4=0xfff7;
    unsigned int i5=0xffef;
    unsigned int izero=0x0000;
    j=1;
    bitset<32>x;
    bitset<64>y;
    star();
    typedef bitset<32> bit32;
    typedef bitset<64> bit64;
    cout<<((bitset<32>)i)<<endl;
    cout<<bitset<32>(i)<<endl;
    cout<<bit32(i)<<endl;
    cout<<(bit32)i<<endl;
    star();
    cout<<(bit64)i<<endl;
    star();
    cout<<(bit64)(i-i0)<<endl;
    cout<<(bit64)i0<<endl;
    star();
    cout<<(bit64)i1<<endl;
    cout<<(bit64)(i-i1)<<endl;
    star();
    cout<<(bit64)i2<<endl;
    cout<<(bit64)(i-i2)<<endl;
    star();
    cout<<(bit64)i3<<endl;
    cout<<(bit64)(i-i3)<<endl;
    cout<<(bit64)i4<<endl;
    cout<<(bit64)i5<<endl;
    star(8);
    bit64 i6=i5;
    y=i5;
    cout<<i6<<endl;
    cout<<y<<endl;
    y.reset();
    star(9);
    cout<<y<<endl;
    y[0]=1;
    y[3]=1;
    y[5]=1;
    cout<<y<<endl;
    y.set();
    cout<<y<<endl;
    y[0]=0;
    y[3]=0;
    y[5]=0;
    cout<<y<<endl;
    return 0;
}

int RunMyTestFN(int argc, char *argv[])
{
    bittest(argc,argv);
    return 0;
}

int xx(int argc,char * argv[] )
{
    return 0;
}

