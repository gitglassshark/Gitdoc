#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#include <memory>
#include <functional>
#include <bitset>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>

#include <iostream>
#include <fstream>

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
    return 0;
}

class Spk
{
public:
    Spk():mcint(0)
    {
        name="  null";
        cout<<"start mfun ......"<<__func__<<name<<endl;
    }
    Spk(int m):mcint(m)
    {
        name="  null";
        cout<<"start  mfun ......"<<__func__<<"(int m)"<<name<<endl;
    }
    Spk(string  nm):mcint(1),name(nm)
    {
        cout<<"start mfun ......"<<__func__<<"(name)"<<name<<endl;
    }
    Spk(const Spk&r):mcint(r.mcint)
    {
        cout<<"start mfun ......"<<__func__<<"(const Spk&)"<<name<<endl;
    }
    Spk &operator =(const Spk&r)
    {
        cout<<"start mfun ......"<<__func__<<"=(const Spk&) "<<name<<endl;
        return *this;
    }
    ~Spk()
    {
        cout<<"start mfun ......"<<__func__<<name<<endl;
    }
    void one()
    {
        cout<<"start mfun ......"<<__func__<<name<<endl;
    }
    void two()
    {
        cout<<"start mfun ......"<<__func__<<name<<endl;
    };
    void speak(string str)
    {
        cout<<str<<"  start mfun ......"<<__func__<<" adress is "<<this<<name<<endl;
    };
    void setname(string nm)
    {
        name=nm;
        cout<<"start mfun ......"<<__func__<<name<<endl;
    }
public:
    int mint;
    const int mcint;
    string name;
    static const int mstint=100;
    typedef decltype(&cre::one) Fmp;
    vector<Fmp> me;
};

int Test3(int argc,char * argv[] )
{
    unique_ptr<Spk> pSpk(new Spk);
    pSpk->setname("  pSpk #1");
    pSpk->one();
    unique_ptr<Spk> pSpka(new Spk(2));
    pSpka->setname("  pSpka #2");
    pSpka->one();
    shared_ptr<Spk> pshSpka(new Spk("#3"));
    cout<<&pSpka<<endl;
    cout<<&Spk::one<<endl;
    cout<<&Spk::two<<endl;
    auto p1=pshSpka;
    auto p2=pshSpka;
    auto p3=p2;
    pshSpka->one();
    p3->one();
    shared_ptr<Spk> pSpknull;
    pSpknull =move(pSpk);
    pSpknull->speak("pSpknull speak");
    cout<<pshSpka.use_count()<<endl;
    auto_ptr<Spk>pnt(new Spk("\t  Make to auto_ptr"));
    auto_ptr<Spk>pnt2;
    pnt2=pnt;
    if(pnt.get()==NULL)
        cout<<"pnt is empty"<<endl;
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
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}

void tranarray(int ar[])
{
    cout<<" in "<<__func__<<'\t'<<ar<<" size of is ar "<<sizeof(ar)<<endl;
}

void arrayaddone(int *ar,size_t size)
{
    for(int i=0; i<size; ++i)
        ar[i]+=1;
}

void arrayaddself(int *ar,size_t size)
{
    for(int i=0; i<size; ++i)
        ar[i]+=ar[i];
}

void arraydynm(size_t size)
{
    int arr[size];
    for(int i=0; i<size; ++i)
        {
            arr[i]=i;
            cout<<arr[i]<<'\t';
        }
    cout<<endl;
}

int  gai=0;

int Test2(int argc,char * argv[] )
{

    const size_t size=10;
    const int initalvalue=2;
    const int mm=0;
    static int  ai=0;
    int ar[size*2];
    printadress(size);
    printadress(ar[0]);
    printadress(mm);
    printadress(gai);
    printadress(ai);
    arraydynm(10);
    tranarray(ar);
    cout<<" in "<<__func__<<'\t'<<ar<<" size of is ar "<<sizeof(ar)<<endl;
    arrayset(ar,size,initalvalue);
    arrayprint(ar,size);
    arrayprintadress(ar,size);
    arrayaddself(ar,size);
    arrayprint(ar,size);
    arrayaddone(ar,size);
    arrayprint(ar,size);

    int A[10]= {7};
    for(int i=0; i<10; ++i)
        {
            *(A+i)=i;
            cout<<i<<'\t'<<(A+i)<<'\t'<<*(A+i)<<endl;
        }
    star();
    int *pmark=safemalloc<int>(10,sizeof(int));
    int *p=pmark;
    for(int i=0; i<10; ++i)
        {
            *(p+i)=i;
            cout<<i<<'\t'<<p+i<<'\t'<<*(p+i)<<endl;
        }
    star();
    for(int i=0; i<10; ++i)
        {
            cout<<i<<'\t'<<p<<'\t'<<*p<<endl;
            *p++;
        }
    p=nullptr;
    safefree(pmark);
    int *pa3[3];
    int (*pa4)[300];
    cout<<sizeof(pa3)<<endl;
    cout<<sizeof(pa4)<<endl;
    return 0;
}

template <typename T>
T& selfadd(T &r,T &l)
{
    return r+=l;
}

typedef  int& (*fptr)(int &r,int &l);
typedef  int& (**pfptr)(int &r,int &l);

int Test1(int argc,char * argv[] )
{
    int a=4;
    int a1=5;
    int a2=6;
    fptr *fp;
    pfptr ff;
    fptr f;
    f=selfadd<int>;
    fp=safemalloc<fptr>(sizeof(fptr));
    *fp=selfadd<int>;
    ff=safemalloc<fptr>(sizeof(fptr));
    *ff=selfadd<int>;
    f=selfadd<int>;
    cout<<(*ff)(a1,a1)<<endl;
    cout<<f(a,a)<<endl;
    cout<<(*fp)(a2,a2)<<endl;
    printptr(fp);
    printptr(ff);
    printptr(f);
    safefree(fp);
    safefree(ff);
    cout<<fp<<endl;
    star('_');
    int &b=selfadd(a,a);
    cout<<a<<'\t'<<&a<<endl;
    cout<<b<<'\t'<<&b<<endl;
    double c=2.2;
    double d=3.3;
    cout<<selfadd(c,d)<<endl;
    int *p ;
    int *p2 ;
    int *p3 ;
    long *p5 ;
    int nu=8;
    cout<<"please input want malloc memeory for element number:"<<endl;
    cin>>nu;

    if(p=safemalloc<int>(nu,sizeof(int)))
        cout<<"malloc is ok...... address is "<<p<<endl;
    if(p2=(int *)malloc(nu*sizeof(int)))
        cout<<"malloc is ok...... address is "<<p2<<endl;
    int pt=max(p,p2)-min(p,p2);
    int pr=(long)max(p,p2)-(long)min(p,p2);
    cout<<pt<<endl;
    cout<<pr<<endl;
    cout<<sizeof(int)<<endl;
    free(p2);
    safefree(p);
    cout<<"safe free after p is "<<p<<endl;
    if(p3=(int *)malloc(nu*sizeof(int)))
        cout<<"malloc is ok...... address is "<<p3<<endl;
    free(p3);
    p5=safemalloc<long>(nu,sizeof(long));
    safefree(p5);
    return 0;
}

Spk ga("ga");
static Spk gsa("gsa");

int Testsub2(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    static Spk sa("sa");
    static Spk sb("sb");
    static Spk sc("sc");
    sa.speak("sa is speak");
    sb.speak("sb is speak");
    sc.speak("sc is speak");
    ga.speak("ga is speak");
    gsa.speak("gsa is speak");
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}
int Testsub(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    static Spk sa("sa");
    static Spk sb("sb");
    sa.speak("sa is speak");
    sb.speak("sb is speak");
    ga.speak("ga is speak");
    gsa.speak("gsa is speak");
    Testsub2(argc, argv);
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}
int Test4(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    static Spk sa("sa");
    static Spk sb("sb");
    sa.speak("sa is speak");
    sb.speak("sb is speak");
    ga.speak("ga is speak");
    gsa.speak("gsa is speak");
    Testsub(argc, argv);

    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}
//
int TestGround(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    size_t l=10;
    size_t c=10;
    size_t size=l*sizeof(int*)+l*c*sizeof(int);
    cout<<size<<endl;
    int *p=safemalloc<int>(size);
    const int initval=30;
    int **pint=(int **)p;
    char *pc=(char*)p;
    pint+=l;
    pc+=l*sizeof(int*);
    cout<<pc<<endl;
    cout<<sizeof(int **)<<'\t'<<sizeof(int*)<<'\t'<<sizeof(int)<<endl;
    int *pu=(int*)pint;
    star();
    cout<<"p is "<<p<<'\t'<<"pint is  "<<pint<<'\t'<<"ps is "<<hex<<(long)pc<<'\t'<<pu<<dec<<endl;
    arrayset(pu,l*c,initval);
    arrayprint(pu,l*c);

    safefree(p);
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}


int Test(int argc,char * argv[] )
{
    return 0;
}

