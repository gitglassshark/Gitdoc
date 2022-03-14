#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include "vectortest.hpp"
#include "temptest.hpp"
#include "mylib.hpp"
#include "menu.hpp"
//
using namespace std;

int VectorTestBCD(int argc,char * argv[] )
{
    vector<int> i_vector_one(10);
    PrintEle(i_vector_one);
    decltype(i_vector_one.size()) j=0;
    for(auto i=i_vector_one.size(),j=i_vector_one.size()-i_vector_one.size(); i>0; --i,++j)
        {
            i_vector_one.push_back(j);
//            cout<<"i is: "<<i<<" --i "<<"plug in j: "<<j<<" ++j"<<endl;
        }
    PrintEle(i_vector_one);
    vector<int>v4;
    if(v4.empty())
        cout<<"V4 is empty"<<endl;
    if(v4.begin()==v4.end())
        cout<<"V4 is empty"<<endl;
    v4.push_back(10);
    cout<<"V4 capicaty is "<<v4.capacity()<<endl;
    cout<<"V4 size is "<<v4.size()<<endl;
    v4.resize(10,50);
    PrintEle(v4);
    for(vector<int>::const_iterator it=v4.begin(); it!=v4.end(); ++it)
        cout<<*it<<"  ";
    cout<<endl;
    int ic=v4.capacity();
    int *ipc=&v4[0];
    int ipcc=0;
    int icc=0;
    for(int i=0; i<10'000; ++i)
        {
            v4.push_back(i*3);
            if(ic!=v4.capacity())
                {
                    ic=v4.capacity();
                    ++icc;
                }
            if(ipc!=&v4[0])
                {
                    ipc=&v4[0];
                    ++ipcc;
                }
        }
    cout<<"resize capactity is "<<icc<<endl;
    cout<<"V4 capicaty is "<<v4.capacity()<<endl;
    cout<<"resize realloc is "<<ipcc<<endl;
    cout<<"V4 size is "<<v4.size()<<endl;
    v4.resize(15);
    cout<<"V4 size is "<<v4.size()<<endl;
    cout<<"V4 capicaty is "<<v4.capacity()<<endl;
    v4.shrink_to_fit();
    cout<<"shrink then V4 capicaty is "<<v4.capacity()<<endl;
    v4.assign(v4.begin(),v4.end());
    cout<<"V4 size is "<<v4.size()<<endl;
    cout<<"V4 capicaty is "<<v4.capacity()<<endl;
    star("list v4",'_');
    PrintEle(v4);
    vector<int>v5(v4.begin()+1,v4.begin()+5);
    PrintEle(v5);
    vector<int>v6(10,*(v4.begin()+3));
    PrintEle(v6);
    return 0;
}

template <typename T>
class compare
{
public:
    bool operator<(const T &r)
    {
        if(r.end())
            return true;
        else
            return false;
    }
    bool operator()(const T &r)
    {
        if(r<5)
            return true;
        else
            return false;
    }
    bool operator()(const T&r,const T& l)
    {
        if(r>l)
            return true;
        else
            return false;
    }
    static bool lcmp(const T &r)
    {
        if(r<5)
            return true;
        else
            return false;
    }
    static  bool rcmp(const T&r,const T& l)
    {
        if(r<l)
            return true;
        else
            return false;
    }
    static bool cmp(const T&r,const T& l)
    {
        if(r>l)
            return true;
        else
            return false;
    }
};

int VectorTestABC(int argc, char *argv[])
{
    vector<int> v1,v2,v3;
    vector<int> v4(30,10);
    vector<int> v5(10);
    vector<int> v6(v4);
    vector<int> v7{10,22,33,44,55};
    vector<vector<int>>vVall;
    vVall.push_back(v4);
    vVall.push_back(v5);
    vVall.push_back(v6);
    vVall.push_back(v7);
    int ic=4;
    for(auto r:vVall)
        {
            cout<<"V"<<ic++<<" is:"<<endl;
            MakeEleRandom(r,10);
            PrintEle(r);
        }
    star("v6 push_back() 100: ");
    v6.push_back(100);
    PrintEle(v6);
    star("v1 assign() v7 begin()-end()");
    v1.assign(v7.begin(),v7.end());
    PrintEle(v1);
    star("V2 assign(10,200)");
    v2.assign(10,200);
    PrintEle(v2);
    star("v3=v1");
    v3=v1;
    PrintEle(v3);
    star("v3.at(1)");
    cout<<v3.at(1);
    v3.at(1)+=10;
    cout<<v3.at(1);
    cout<<v3.back();
    cout<<*v3.begin();
    cout<<*v3.end();
    cout<<*(v3.end()-1);
    cout<<*(v3.begin()+(v3.end()-v3.begin())/2);
    star();
    cout<<"v6 capacity is "<<t<<v6.capacity()<<e;
    cout<<"v7 capacity is "<<t<<v7.capacity()<<e;
    star("v2 clear()");
    v2.clear();
    PrintEle(v2);
    star("v3");
    PrintEle(v3);
    star("v3 resize(2)");
    v3.resize(2);
    PrintEle(v3);
    star("v3 resize(5)");
    v3.resize(5);
    PrintEle(v3);
    star("v3=v4 v3:");
    v3=v4;
    PrintEle(v3);
    star("v2 swap v4 v2 v4");
    v2.swap(v4);
    PrintEle(v2);
    PrintEle(v4);
    cout<<"v3[4]:"<<e;
    cout<<v3[4]<<t<<e;
    v3[4]+=20;
    cout<<v3[4]<<t<<e;
    star();
    decltype(v3) vx(v3);
    cout<<vx[4]<<e;
    cout<<vx[3]<<e;
    cout<<v3.front()<<endl;

    compare <int> com;
    v3.resize(30);
    MakeEleRandom(v3,10);
    auto it=find_if(v3.begin(),v3.end(),compare<int>());
    PrintEle(v3);
    star("V3 compare <5 is ");
    if(it!=v3.end())
        cout<<*it<<endl;
    star("V3 sort  is ");
    sort(v3.begin(),v3.end());
    PrintEle(v3);
    star("V3 sort is  com.rcmp");
    sort(v3.begin(),v3.end(),com.rcmp);
    PrintEle(v3);
    star("V3 sort is  com");
    sort(v3.begin(),v3.end(),com);
    PrintEle(v3);
    star("V3 sort is  com.cmp");
    sort(v3.begin(),v3.end(),com.cmp);
    PrintEle(v3);
    star("V3 sort is  compare<int()");
    sort(v3.begin(),v3.end(),compare<int>());
    PrintEle(v3);
    vector<int>vr(20);
    getchar();
    star("Make Random vector vr");
    MakeEleRandom(vr,100);
    PrintEle(vr);
    vector<int>vl(20);
    MakeEleRandom(vl,100);
    star("Make Random vector vl");
    PrintEle(vl);
    transform(vr.begin(),vr.end(),vl.begin(),negate<int>());
    star("Make negate vector vl");
    PrintEle(vl);
    star("foreach disp  vector vl");
    foreach(vl.begin(),vl.end(),disp);
    cout<<endl;
    star("plus_1");
    foreach(vl.begin(),vl.end(),plus_1);
    foreach(vl.begin(),vl.end(),disp);
    cout<<endl;
    star("negate_1");
    foreach(vl.begin(),vl.end(),negate_1);
    foreach(vl.begin(),vl.end(),disp);
    cout<<endl;
    int largersize=10;
    int smod=5;
    vr.resize( largersize);
    MakeEleRandom(vr, smod );
    int is=8000;
    auto id=find(vr.begin(),vr.end(),is);
    if(id!=vr.end())
        cout<<"scusses find "<<*id<<endl;
    sort(vr.begin(),vr.end(),com);
    foreach(vr.begin(),vr.end(),disp);
    sort(vr.begin(),vr.end(),com.rcmp);
    foreach(vr.begin(),vr.end(),disp);
    cout<<endl;
    star('_');
    sort(vr.begin(),vr.end(),greater<int>());
    foreach(vr.begin(),vr.end(),disp);
    cout<<endl;
    sort(vr.begin(),vr.end(),com.rcmp);
    foreach(vr.begin(),vr.end(),disp);
    cout<<endl;
    star("random_shuffle");
    random_shuffle(vr.begin(),vr.end());
    star("vr");
    foreach(vr.begin(),vr.end(),disp);
    cout<<endl;
    star("vl");
    foreach(vl.begin(),vl.end(),disp);
    cout<<endl;
    vector<int>vend(vr);
    vend.resize(vr.size()+vl.size());
    star("vend");
    foreach(vend.begin(),vend.end(),disp);
    cout<<endl;
    star("merge vl+vr->vend");
    merge(vr.begin(),vr.end(),vl.begin(),vl.end(),vend.begin());
    foreach(vend.begin(),vend.end(),disp);
    cout<<endl;
    star("reverse vend");
    reverse(vend.begin(),vend.end());
    foreach(vend.begin(),vend.end(),disp);
    cout<<endl;
    star("replace vend 2 to 3");
    replace(vend.begin(),vend.end(),2,3);
    foreach(vend.begin(),vend.end(),disp);
    cout<<endl;
    star("accumulate vend ");
    auto accu= accumulate(vend.begin(),vend.end(),0);
    foreach(vend.begin(),vend.end(),disp);
    cout<<" :-> "<<accu<<endl;
    star("vl && vend  ");
    vector<int>vins;

    sort(vl.begin(),vl.end());
    sort(vend.begin(),vend.end());
    vins.resize(min(vl.size(),vend.size()));
    set_intersection(vl.begin(),vl.end(),vend.begin(),vend.end(),vins.begin());
    foreach(vins.begin(),vins.end(),disp);
    cout<<endl;
    star("vl");
    foreach(vl.begin(),vl.end(),disp);
    cout<<endl;
    star(" vend");
    foreach(vend.begin(),vend.end(),disp);
    cout<<endl;
    return 0;
}

int StdVectorTest(int argc,char * argv[] )
{
    vector<string>Menu;
    vector<PFp>Command;
    string strMenuTitle="Please choice a Menu command No to run a command,choice 0 = exit...";
    Menu.push_back(strMenuTitle);
    Command.push_back(nullptr);
    string strMenuName;

    strMenuName="VectorTest:ABC";
    Menu.push_back(strMenuName);
    Command.push_back(VectorTestABC);

    strMenuName="VectorTestBCD";
    Menu.push_back(strMenuName);
    Command.push_back(VectorTestBCD);

    RunMenuMU(argc, argv,Menu,Command);
    return 0;
}

