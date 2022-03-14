#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <set>
#include <vector>
#include "arraytest.hpp"
#include "temptest.hpp"
#include "mylib.hpp"
#include "menu.hpp"
//
using namespace std;

int TestArrayABC(int argc, char *argv[])
{
    typedef std::array<int,8> ArrayNum8;
    ArrayNum8 arOne;
    ArrayNum8 ar4;
    const int mod=10;
    MakeEleRandom(arOne,mod);
    MakeEleRandom(ar4,mod);
    star("print arOne");
    PrintEle(arOne);
    ArrayNum8 ar2;
    ar2=arOne;
    star("print ar2");
    PrintEle(ar2);
    ArrayNum8 ar3(ar2);
    star("print ar3");
    PrintEle(ar3);
    star("print ar4");
    PrintEle(ar4);
    star("fill ar3 with 2");
    ar3.fill(2);
    star("print ar3");
    PrintEle(ar3);
    star("print ar2 first ele with front()");
    cout<<ar2.front()<<endl;
    star("print ar2 end ele with back()");
    cout<<ar2.back()<<endl;
    star("print ar2 max_size");
    cout<<ar2.max_size()<<endl;
    star("print arOne size");
    cout<<arOne.size()<<endl;
    star("print ar2 first data address and value");
    cout<<ar2.data()<<t<<*ar2.data()<<endl;
    star("print arOne is empty()?");
    cout<<boolalpha<<arOne.empty()<<endl;
    star("print arOne is at(4)");
    cout<<arOne.at(4)<<endl;
    star("swap() arOne and ar4)");
    arOne.swap(ar4);
    cout<<arOne.at(4)<<endl;
    star("print arOne");
    PrintEle(arOne);
    star("print ar4");
    PrintEle(ar4);
    star("print ar4 begin() and end()");
    cout<<*ar4.begin()<<t<<*(ar4.end()-1)<<endl;
    star("print ar4 rbegin() and rend()");
    cout<<*ar4.rbegin()<<t<<*(ar4.rend()-1)<<endl;
    return 0;
}

int TestArrayBCD(int argc,char * argv[] )
{
    array<int,8> a4;
    array<int,8>::value_type it;
    MakeEleRandom(a4,10);
    PrintEle(a4);
    it=*a4.begin();
    cout<<it<<endl;
    star("print diff from begin to end");
    array<int,8>::value_type id=a4.end()-a4.begin();
    cout<<id<<endl;
    array<int,8>::reverse_iterator i=a4.rend();
    cout<<*--i<<t<<*--i<<endl;
    return 0;
}

int StdArrayTest(int argc,char * argv[] )
{
    vector<string>Menu;
    vector<PFp>Command;
    string strMenuTitle="Please choice a Menu command No to run a command,choice 0 = exit...";
    Menu.push_back(strMenuTitle);
    Command.push_back(nullptr);
    string strMenuName;

    strMenuName="ArrayTest:ABC";
    Menu.push_back(strMenuName);
    Command.push_back(TestArrayABC);

    strMenuName="TestArrayBCD";
    Menu.push_back(strMenuName);
    Command.push_back(TestArrayBCD);

    RunMenuMU(argc, argv,Menu,Command);
    return 0;
}

