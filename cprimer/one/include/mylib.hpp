#pragma once
#include <iostream>

int MenuCM(int argc, char *argv[]);
typedef decltype(MenuCM) *PFp;
typedef decltype(MenuCM) PF;
typedef  PF *pPF;
using fPF=int (*)(int, char **);
using ffP=int (int, char **);
using namespace std;
int newline();
int blankline();
int star(const char c);
int star(const int &n=0);
int star(const int c,const int n);
int star(const char c,const int n);
int star(const char * const p);
int star(const char c,const char *p);
int star(const char *p,const char c);
int starn();
int PrintClassSize();
int PrintSx (char const *const cmessage);
int PrintSLx (char const *const cmessage);
int Print_NCharx (char c, int inum);
int PrintSTx (char const *const cmessage);

inline const char * datenow(int i=1)
{
    if(i==1)
        cout<<__DATE__<<endl;
    return __DATE__;
}
inline const char * timenow(int i=1)
{
    if(i==1)
        cout<<__TIME__<<endl;
    return __TIME__;
}
inline const int  line(int i=1)
{
    if(i==1)
        cout<<__LINE__<<endl;
    return __LINE__;
}
inline const char * filename(int i=1)
{
    if(i==1)
        cout<<__FILE__<<endl;
    return __FILE__;
}
inline const char * funname(int i=1)
{
    if(i==1)
        cout<<__func__<<endl;
    return __func__;
}
