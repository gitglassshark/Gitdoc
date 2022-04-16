#include <algorithm>
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
#include "scrout.hpp"
#include "temptest.hpp"
#include "arraytest.hpp"
#include "vectortest.hpp"
#include "menu.hpp"

using namespace std;
int TestGround(int argc,char * argv[] );

int DequeTest(int argc, char *argv[])
{
    deque<int>ade;
    star("rbegin compare rend if equal:");
    if(ade.rbegin()==ade.rend())
        cout<<"deque is empty "<<endl;
    star("begin compare end if equal:");
    if(ade.begin()==ade.end())
        cout<<"deque is empty "<<endl;
    star("test deque member empty():");
    if(ade.empty())
        cout<<"deque is empty "<<endl;
    star();
    int nitial=20;
    int ntimes=10;
    cout<<"please input a number to inital deque:";
    cin>>nitial;
    cout<<"please input a number to times inital size";
    cin>>ntimes;
    star("test deque member resize():");
    ade.resize(ntimes,nitial);
    cout<<"deque size is  "<<ade.size()<<endl;
    if(!ade.empty())
        cout<<"deque is not empty "<<endl;
    for(auto i:ade)
        cout<<i<<t;
    cout<<endl;
    cout<<"resize size is ?"<<endl;
    int nresize=0;
    cin>>nresize;
    ade.resize(nresize);
    for(auto i:ade)
        cout<<i<<t;
    cout<<endl;
    star('_');
    int ii=0;
    for(auto &i:ade)
        {
            i=++ii;
            cout<<i<<t;
        }
    cout<<endl;
    star('_');
    ade.pop_back();
    cout<<"remove back"<<endl;
    for(auto i:ade)
        cout<<i<<t;
    cout<<endl;
    star('_');
    cout<<"remove front"<<endl;
    ade.pop_front();
    for(auto i:ade)
        cout<<i<<t;
    cout<<endl;
    star('_');
    return 0;
}

int DequeTestTwo(int argc,char * argv[] )
{
    demoArray<int> ArrayOne(20);
    ArrayOne.setallrandom();
    ArrayOne[9]=6;
    ArrayOne[7]=5;
    star();
    ArrayOne.list();
    star();
    deque<int>done;
    makedeque<int>(done,100,1000);
    listdeque<int>(done);
    sort(done.begin(),done.end());
    listdeque<int>(done);
    deque<int>dscore;
    deque<int>dman;
    int score;
    for(int i=0; i<10; ++i)
        {
            score=0;
            for(int i=0; i<10; ++i)
                {
                    score=rand()%41+60;
                    dscore.push_back(score);
                }
            sort(dscore.begin(),dscore.end());
            cout<<i<<"# man score is "<<endl;
            listdeque<int>(dscore);
            dscore.pop_back();
            dscore.pop_front();
            cout<<i<<"# man resort clean score is "<<endl;
            listdeque<int>(dscore);
            score=0;
            for(auto i:dscore)
                score+=i;
            score/=dscore.size();
            cout<<i<<"# man Avg score is : "<<score<<endl;
            dman.push_back(score);
            dscore.clear();
        }
    star();
    cout<<"all man avg is :"<<endl;
    listdeque<int>(dman);
    star();
    return 0;
}

int StackTest(int argc,char * argv[] )
{
    stack<int>stack1;
    cout<<"stack 1 empty()"<<endl;
    cout<<boolalpha<<stack1.empty()<<endl;
    stack1.push(10);
    stack1.push(20);
    cout<<"push two element and stack1 data top is "<<stack1.top()<<endl;
    stack1.pop();
    cout<<"pop element and stack1 data top is "<<stack1.top()<<endl;
    cout<<"stack1 size is"<<stack1.size()<<endl;
    MakeStack<int>(stack1,20,1000);
    star();
    cout<<"make stack 20 elemnt stack1 data top is "<<stack1.top()<<endl;
    cout<<"stack1 size is"<<stack1.size()<<endl;
    stack1.pop();
    cout<<"stack1 data top is "<<stack1.top()<<endl;
    cout<<"stack1 size is"<<stack1.size()<<endl;
    stack1.pop();
    cout<<"stack1 data top is "<<stack1.top()<<endl;
    cout<<"stack1 size is"<<stack1.size()<<endl;
    return 0;
}

int QueueTest(int argc,char * argv[] )
{
    queue<int>dinerqueue;
    int mod=1000;
    int em;
    for(int i=0; i<10; ++i)
        {
            em=random()%mod;
            cout<<em<<t;
            dinerqueue.push(em);
        }
    cout<<endl;
    star();
    cout<<dinerqueue.front()<<endl;
    cout<<dinerqueue.back()<<endl;
    cout<<dinerqueue.size()<<endl;
    star();
    dinerqueue.pop();
    cout<<dinerqueue.front()<<endl;
    cout<<dinerqueue.back()<<endl;
    cout<<dinerqueue.size()<<endl;
    star();
    queue<int>queueb;
    queueb=dinerqueue;
    cout<<queueb.size()<<endl;
    return 0;
}

int ListTest(int argc,char * argv[] )
{
    list<int>l1(20,10);
    cout<<l1.size()<<endl;
    listlist<int>(l1);
    star("l1");
    MakeList<int>(l1,10);
    listlist<int>(l1);
    star("l2");
    list<int>l2(l1);
    listlist<int>(l2);
    star("l3");
    list<int>l3=l1;
    listlist<int>(l3);
    star("l4");
    list<int>l4;
    l4=l1;
    listlist<int>(l4);
    list<int>l5;
    l5.assign(++l4.begin(),--l4.end());
    star("l5");
    listlist<int>(l5);
    int ia=l4.size()-l5.size();
    cout<<ia<<endl;
    l5.resize(10);
    star("l5 resize");
    listlist<int>(l5);
    l5.swap(l4);
    star("swap after l4");
    listlist<int>(l4);
    star("l5");
    listlist<int>(l5);
    star("l4 resize (30)");
    l4.resize(20);
    listlist<int>(l4);
    l4.resize(10,7);
    listlist<int>(l4);
    l4.resize(10,9);
//    list<int>::iterator it=l4.begin();
    auto it=l4.begin();
    l4.insert(it,8);
    l4.insert(it,8);
    l4.insert(it,8);
    l4.insert(it,8);
    star('=');
    printList<int>(l4);
    l4.remove(8);
    printList<int>(l4);
    l4.clear();
    star("list 4=");
    printList<int>(l4);
    star("list 3=");
    printList<int>(l3);
    cout<<"L3 first element is "<<l3.front()<<endl;
    cout<<"L3 end element is "<<l3.back()<<endl;
    l3.reverse();
    star("list 3 reverse");
    printList<int>(l3);
    star("list 3 sort");
    l3.sort();
    printList<int>(l3);
    star("list 3 cmp");
    //    l3.reverse();
    //    printList<int>(l3);
    l3.sort(cmp<int>);
    printList<int>(l3);
    star("list 3 rcmp");
    l3.sort(rcmp<int>);
    printList<int>(l3);
    star("list 3 pop_back() && pop_front() ");
    l3.pop_back();
    l3.pop_front();
    printList<int>(l3);
    star("list 3 push_back(99)&& push_front(88) ");
    l3.push_back(99);
    l3.push_front(88);
    printList<int>(l3);
    star("list 3 insert 20 in begin() && 22 in end()");
    l3.insert(l3.begin(),20);
    l3.insert(l3.end(),22);
    printList<int>(l3);
    star("list 3 front() && begin() ");
    cout<<*l3.begin()<<t<<l3.front()<<endl;
    star("list 3 back() && end()");
    cout<<*--l3.end()<<t<<l3.back()<<endl;
    star("list 3 max_size");
    cout<<l3.max_size()<<endl;
    star("list 3 merge list 1");
    l3.merge(l1);
    star("list 1");
    printList<int>(l1);
    star("list 3 ");
    printList<int>(l3);
    star("list 3 remove 1-5");
    for(int i=1; i<5; ++i)
        l3.remove(i);
    printList<int>(l3);
    star("list 3 assign l5");
    l3.assign(l5.begin(),l5.end());
    star("l5");
    printList<int>(l5);
    star("list 3 ");
    printList<int>(l3);
    l5.assign(7,8);
    star("list 5 assign 7,8");
    printList(l5);
    star("list 1 assign from 1-5");
    l1.assign({1,2,3,4,5,5,5,5});
    printList(l1);
    for(auto &i:l5)
        l3.push_back(i);
    for(auto &i:l1)
        l3.push_back(i);
    for(auto &i:l2)
        l3.push_back(i);
    star("display l3");
    printList(l3);
    it=l3.begin();
    while(it!=l3.end())
        {
            if(*it==8)
                {
                    l3.erase(it);
                    it=l3.begin();
                }
            else
                ++it;
        }
    star("delete all 8 and display l3");
    printList(l3);
    star("sort display l3");
    l3.sort();
    printList(l3);
    star("revese  display l3");
    l3.reverse();
    printList(l3);
    return 0;
}

int SetTest(int argc,char * argv[] )
{
    int getmod=10;
    cout<<"please input a mod for make random set:";
    cin>>getmod;
    cout<<"please input a num for make random set include elements number :";
    int getnum=10;
    cin>>getnum;
    const int mod=getmod;
    const int num=getnum;
    set<int>iset;
    multiset<int>miset;
    MakeRandomSet<set<int>>(iset,num,mod);
    MakeRandomSet<multiset<int>>(miset,num,mod);
    star("iset");
    MakeDisplaySet<set<int>>(iset);
    star("miset");
    MakeDisplaySet<multiset<int>>(miset);
    miset.erase(3);
    star("miset erase 3");
    MakeDisplaySet(miset);
    cout<<"key 5 times is "<<miset.count(5)<<endl;
    set<int>iset2;
    MakeRandomSet(iset2,num,mod);
    star("iset2");
    MakeDisplaySet(iset2);
    iset2.swap(iset);
    star("swaped iset");
    MakeDisplaySet(iset);
    star("iset2");
    MakeDisplaySet(iset2);
    star("iset transfer iset to miset ");
    TransferSet(iset2,miset);
    MakeDisplaySet(miset);
    star("iset transfer miset to iset2 ");
    TransferSet(miset,iset2);
    MakeDisplaySet(iset2);
    // 显示集合大小
    cout<<"iset size is "<<iset.size()<<"\tiset2 size is "<<iset2.size();
    cout<<"\tmiset size is "<<miset.size()<<endl;
    // find
    star("find");
//    multiset<int>::const_iterator it=miset.find(8);
    const auto it=miset.find(8);
    int ic=miset.count(8);
    if(it!=miset.end())
        cout<<*it<<t<<ic<<"\'s"<<endl;
    star("Miset elements is: ");
    MakeDisplaySet(miset);
    cout<<"list the max of elements in multiset miset is :"<<endl;
    cout<<*FindMaxInSet(miset)<<endl;
    cout<<"Delete the max of elemnts......"<<endl;
    cout<<miset.erase(*FindMaxInSet(miset))<<endl;
    cout<<"list the max of elements in multiset miset is :"<<endl;
    MakeDisplaySet(miset);
//    for(int i=0;i<)
    return 0;
}
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

#define ADDMENU(menu,funcname,str)   {\
        str = #funcname;\
        menu.push_back (str);\
        Command.push_back (funcname);\
        }

int TestDcout(int argc,char * argv[] )
{
    ScrOut cout;
    auto tuplea = tuple<int, float, string, string, string>(10, 10.24, "good", "bad", "normal");

    int length = tuple_size<decltype(tuplea)>::value;
    cout << std::is_integral<decltype(length)>::value << el;
    cout << is_empty<tuple<>>::value << el;
    cout.disptup(tuplea)<<el;
    cout<<tuplea<<el;
    cout.type(tuplea);
    vector<int>veca{3,8,9,6,1,8,9,9,2,7,4,9};
    cout<<veca<<el;
    cout<<cut;
    cout<<&length<<el;
    cout<<address(length)<<el;
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

    ADDMENU(Menu,TestDcout,strMenuName)
//    ADDMENU(Menu,ReferenceTest,strMenuName)
//    ADDMENU(Menu,TestGround,DequeTestTwo)
//    ADDMENU(Menu,TestGround,DequeTest)
////    ADDMENU(Menu,TestGround,)
//    ADDMENU(Menu,TestGround,StackTest)
//    ADDMENU(Menu,TestGround,QueueTest)
//    ADDMENU(Menu,TestGround,ListTest)
//    ADDMENU(Menu,TestGround,SetTest)
//    ADDMENU(Menu,TestGround,StdVectorTest)
//    ADDMENU(Menu,TestGround,StdArrayTest)


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

