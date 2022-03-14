//#include <algorithm>
#include <memory>
#include <functional>
#include <bitset>
#include <cstring>
#include <deque>
#include <fstream>
#include <list>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include "mylib.hpp"
#include "temptest.hpp"
#include "menu.hpp"

using namespace std;
int TestGround(int argc,char * argv[] );

class cre
{
public:
    cre(int m):int_mit(m)
    {
        me.push_back(&cre::one);
        auto i=me[0];
        cout<<"start mfun ......"<<__func__<<endl;
        cout<<typeid(pFmp).name()<<endl;
        cout<<typeid(pf).name()<<endl;
        cout<<"is ok"<<endl;
        cout<<typeid(Fmp).name()<<endl;
        cout<<typeid(&cre::one).name()<<endl;
        cout<<typeid(me[0]).name()<<endl;
        cout<<typeid(i).name()<<endl;
        cout<<" ....is ok"<<endl;
        (*this.*me[0])();
        (this->*me[0])();
        (this->*i)();
        (*this.*i)();
        (this->*me.back())();
        cout<<"*this.*i id is "<<typeid(this).name()<<endl;
        cout<<"end mfun ......"<<__func__<<endl;
    }
    void one()
    {
        cout<<"start "<<__func__<<endl;
    }
    void two()
    {
        cout<<__func__<<endl;
    };
public:
    const int int_mit;
    static const int maxint_mit=100;
    typedef decltype(&cre::one) *pFmp;
    typedef decltype(&cre::one) Fmp;
    typedef void (*pf)();
    vector<pFmp> menu;
    vector<Fmp> me;
};

int ReferenceTest(int argc,char * argv[] )
{
    typedef void (cre::*pmf)();
    pmf p[2];
    pmf *lp[2];
    cout<<typeid(p).name()<<endl;
    cout<<sizeof(p)<<endl;
    int size=1;
    cre c1(size);
    p[0]=&cre::one;
    p[1]=&cre::two;
    for(int i=0; i<size; i++)
        (c1.*p[i])();
    star("ref",'_');
    cout<<"PFP "<<typeid(PFp).name()<<endl;
    cout<<"pPF "<<typeid(pPF).name()<<endl;
    cout<<"fPF "<<typeid(fPF).name()<<endl;
    cout<<"ffP "<<typeid(ffP).name()<<endl;
    cout<<"PF "<<typeid(PF).name()<<endl;
    cout<<"p "<<typeid(p).name()<<endl;
    cout<<"p[0] "<<typeid(p[0]).name()<<endl;
    cout<<"lp[0] "<<typeid(lp[0]).name()<<endl;
    cout<<"lp "<<typeid(lp).name()<<endl;
    star("unique_ptr",'_');
    unique_ptr<cre>pcre=make_unique<cre>(2);
//    auto x=pcre->me.back();
//        *c1.me.back();
    return 0;
}

int RunMyTestFN(int argc, char *argv[])
{
    vector<string>Menu;
    vector<pPF>Command;
    string strMenuTitle="Please choice a Menu command No to run a command,choice 0 = exit...";
    Menu.push_back(strMenuTitle);
    Command.push_back(nullptr);
    string strMenuName;

    strMenuName="ReferenceTest";
    Menu.push_back(strMenuName);
    Command.push_back(ReferenceTest);

    strMenuName="TestGround";
    Menu.push_back(strMenuName);
    Command.push_back(&TestGround);

    RunMenuMU(argc, argv,Menu,Command);
    return 0;
}

int TestGround(int argc,char * argv[] )
{
    negate<int>rn;
    cout<<rn(50)<<endl;
    logical_or<bool>bor;
    logical_and<bool>band;
    logical_not<bool>bnot;
    cout<<boolalpha<<bor(true,false)<<endl;
    cout<<boolalpha<<bor(false,false)<<endl;
    cout<<boolalpha<<bor(true,true)<<endl;
    cout<<boolalpha<<band(true,false)<<endl;
    cout<<boolalpha<<band(false,false)<<endl;
    cout<<boolalpha<<band(true,true)<<endl;
    cout<<boolalpha<<bnot(true)<<endl;
    cout<<boolalpha<<bnot(false)<<endl;
    return 0;
}

int Test(int argc,char * argv[] )
{
    return 0;
}

