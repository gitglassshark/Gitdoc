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
int Test(int argc,char * argv[] );

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
    Spk(int m):mcint(m),mint(m)
    {
        name="  null";
        cout<<"start  mfun ......"<<__func__<<"(int m)"<<name<<"#"<<mint<< endl;
    }
    Spk(string  nm):mcint(0),name(nm),mint(0)
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
        cout<<str<<"  start mfun ......"<<__func__<<" adress is "<<this<<name<<" #"<<mint << endl;
    };
    void setname(string nm)
    {
        name=nm;
        cout<<"start mfun ......"<<__func__<<name<<endl;
    }
    void setm(int n)
    {
        mint= n;
        //cout << "start mfun ......" << __func__ << name << " #"<<mint << endl;
    }
public:
    int mint;
    const int mcint;
    string name;
    static const int mstint=100;
    typedef decltype(&cre::one) Fmp;
    vector<Fmp> me;
};


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

void arraydynm(int size = 10)
{
    size = 10;
    int arr[10];
    for(int i=0; i<size; ++i)
        {
            arr[i]=i;
            cout<<arr[i]<<'\t';
        }
    cout<<endl;
}

int  gai=0;

int TestPrintAdd(int argc,char * argv[] )
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

int TestMalloc(int argc,char * argv[] )
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

int TestSubClass(int argc,char * argv[] )
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

int TestSubTwo(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    static Spk sa("sa");
    static Spk sb("sb");
    sa.speak("sa is speak");
    sb.speak("sb is speak");
    ga.speak("ga is speak");
    gsa.speak("gsa is speak");
    TestSubClass(argc, argv);
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}


int TestArrayMalloc(int argc, char* argv[])
{
    cout << __func__ << "#" << __LINE__ << endl;
    size_t l = 10;
    size_t c = 10;
    size_t size = l * sizeof(int*) + l * c * sizeof(int);
    cout << size << endl;
    int* p = safemalloc<int>(size);
    const int initval = 20;
    int** pint = (int**)p;
    char* pc = (char*)p;
    pint += l;
    pc += l * sizeof(int*);
    cout << pc << endl;
    cout << sizeof(int**) << '\t' << sizeof(int*) << '\t' << sizeof(int) << endl;
    int* pu = (int*)pint;
    star();
    cout << dec << "p is " << p << '\t' << "pint is  " << pint << '\t' << "ps is " << (long)pc << '\t' << pu << endl;

    arrayset(pu, l * c, initval);
    arrayprint(pu, l * c);
    foreach<int>(pu, pu + l * c, disp<int*>);
    safefree(p);
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}

template <typename T>
bool add(T *e)
{
    ++*e;
    return true;
}
void phello()
{
    cout << "hello" << endl;
}

int TestGround(int argc,char * argv[] )
{
    cout<<"start test ......"<<endl;
    Spk one;
    one.setm(1);
    one.speak("One");
    Spk *pOne=new Spk(" in heap new Spk");
    pOne->setm(2);
    pOne->speak("pOne");
    cout << TestGround << endl;
    using funp = void(*)();
    funp fx = phello;
    fx();
    (* fx)();
    auto e = argv[0];
    for (int i=0; i<argc; e=argv[++i])
        cout << e << endl;
    delete pOne;
    return 0;
}

int TestArrayMallocPoint(int argc,char * argv[] )
{
    cout<<__func__<<"#"<<__LINE__<<endl;
    size_t l=10;
    size_t c=10;
    size_t size=l*sizeof(int*)+l*c*sizeof(int);
    int *p=safemalloc<int>(size);
    const int initval = 20;
    int** pint = (int**)p;
    pint += l;
    int* pu = (int*)pint;

    arrayset(pu, l * c, initval);
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            *(pu + i*c + j)=(i+1)*(1+j);


    arrayprint(pu, l * c);
    Spk* pspk =(Spk*) new Spk[l*c];
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            (* (pspk + i * c + j)).setm(i*c+j+1);
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            (pspk + i * c + j)->speak("ls");
    pspk[98].speak("ok");
    cout << sizeof(Spk) << endl;
    cout << typeid(Spk).name() << endl;

    cout << boolalpha << true << endl;
    cout << boolalpha << true << endl;
    system("pause");

    delete[]pspk;
    safefree(p);
    cout<<__func__<<"#"<<__LINE__<<endl;
    return 0;
}


class NewMan;

class NewMan
{

public:
    NewMan(int age) :meage(age)
    {

    }
    static int sayage(class NewMan* me)
    {
        cout<<me->meage<<endl;
        return me->meage;
    }
    void say()
    {
        sayage(this);
    }

private:
    int meage;
};

int Test(int argc,char * argv[] )
{
    unsigned long int max=1;
    int ic=sizeof(max)*8;
    for(int i=0; i<ic-1; ++i)
        max*=2;
    cout<<ic<<endl;
    cout<<" max * 63^ is "<<max<<endl;
    cout<<" max * 63^ *2 is "<<max*2<<endl;
    NewMan one(18),two(20);
    one.say();
    two.say();
    NewMan::sayage(&one);
    NewMan::sayage(&two);
    one.sayage(&two);
    one.sayage(&one);
    one.sayage(&two);
    two.sayage(&two);

    return 0;
}


int TestSmartPtr(int argc,char * argv[] )
{
// create nonoyus object pointer
//    unique_ptr<Spk> pSpk1(new Spk);
//    pSpk1->setname("  pSpk1 #1");
//    pSpk1->one();

    shared_ptr<Spk> pSpk2(new Spk);
    pSpk2->setname("  pSpk2 #2");
//    cout<<&Spk::one<<endl;
//    cout<<&Spk::two<<endl;

    unique_ptr<Spk> pSpk3=make_unique<Spk>("pSpk3 #3 unique ptr object");
    auto pSpk4=pSpk2;
    pSpk4->speak("pSpk4 is speak");
    pSpk2->speak("pSpk2 is speak");
    pSpk4->setname ("lisa");
    pSpk2->speak("pSpk2 is speak");
    cout<<pSpk2.use_count()<<endl;
    cout<<pSpk4.use_count()<<endl;
    auto pSpk5=pSpk2;
    cout<<pSpk5.use_count()<<endl;
    cout<<pSpk4.use_count()<<endl;

    pSpk3.release();





//inital assigend = to uniqueptr through make_unique
    /*    unique_ptr<Spk> pSpk2=make_unique<Spk>();
        pSpk2->setname("  pSpk2 #2");

        unique_ptr<Spk> pSpk3(new Spk(3));
        pSpk3->setname("  pSpk3 #3");
        pSpk3->one();
        shared_ptr<Spk> pSpk4(new Spk("shared_ptr pSpk4 #4"));
        cout<<"pSpk3 adress is "<<&pSpk3<<endl;
        cout<<"pSpk4 adress is "<<&pSpk4<<endl;
        cout<<&Spk::two<<endl;
        auto p1=pSpk4;
        cout<<pSpk4.use_count()<<endl;
        auto p2=pSpk4;
        auto p3=p2;
        pSpk4->one();
        p3->one();
        cout<<pSpk4.use_count()<<endl;

        shared_ptr<Spk> pSpk5;
        auto pSpk6=move(pSpk4);
        pSpk6->speak("pSpk6 speak");
        auto_ptr<Spk>pnt(new Spk("\t  Make to auto_ptr"));
        auto_ptr<Spk>pnt2;
        pnt2=pnt;
        if(pnt.get()==NULL)
            cout<<"pnt is empty"<<endl;
            */
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

    strMenuName="TestSmartPtr unique_ptr ,shared_ptr";
    Menu.push_back(strMenuName);
    Command.push_back(TestSmartPtr);

    strMenuName="Test";
    Menu.push_back(strMenuName);
    Command.push_back(Test);

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
