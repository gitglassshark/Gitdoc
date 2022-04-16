#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <pthread.h>
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
#include <tuple>

#include <iostream>
#include <fstream>

#include "mylib.hpp"
#include "temptest.hpp"
#include "menu.hpp"

using namespace std;
int TestGround (int argc, char *argv[]);
int Test (int argc, char *argv[]);

class cre
{
public:
    cre (int m):int_mit (m)
    {
        me.push_back (&cre::one);
        auto i = me[0];
        cout << "start mfun ......" << __func__ << endl;
        cout << typeid (pFmp).name () << endl;
        cout << typeid (pf).name () << endl;
        cout << "is ok" << endl;
        cout << typeid (Fmp).name () << endl;
        cout << typeid (&cre::one).name () << endl;
        cout << typeid (me[0]).name () << endl;
        cout << typeid (i).name () << endl;
        cout << " ....is ok" << endl;
        (*this.*me[0]) ();
        (this->*me[0]) ();
        (this->*i) ();
        (*this.*i) ();
        (this->*me.back ()) ();
        cout << "*this.*i id is " << typeid (this).name () << endl;
        cout << "end mfun ......" << __func__ << endl;
    }
    void one ()
    {
        cout << "start " << __func__ << endl;
    }
    void two ()
    {
        cout << __func__ << endl;
    };
public:
    const int int_mit;
    static const int maxint_mit = 100;
    typedef decltype (&cre::one) * pFmp;
    typedef decltype (&cre::one) Fmp;
    typedef void (*pf) ();

    vector < pFmp > menu;
    vector < Fmp > me;
};

int ReferenceTest (int argc, char *argv[])
{
    typedef void (cre::*pmf) ();
    pmf p[2];
    pmf *lp[2];

    cout << typeid (p).name () << endl;
    cout << sizeof (p) << endl;
    int size = 1;
    cre c1 (size);

    p[0] = &cre::one;
    p[1] = &cre::two;
    for (int i = 0; i < size; i++)
        (c1.*p[i]) ();
    star ("ref", '_');
    cout << "PFP " << typeid (PFp).name () << endl;
    cout << "pPF " << typeid (pPF).name () << endl;
    cout << "fPF " << typeid (fPF).name () << endl;
    cout << "ffP " << typeid (ffP).name () << endl;
    cout << "PF " << typeid (PF).name () << endl;
    cout << "p " << typeid (p).name () << endl;
    cout << "p[0] " << typeid (p[0]).name () << endl;
    cout << "lp[0] " << typeid (lp[0]).name () << endl;
    cout << "lp " << typeid (lp).name () << endl;
    star ("unique_ptr", '_');
    unique_ptr < cre > pcre = make_unique < cre > (2);
    return 0;
}

class Spk
{
public:
    Spk ():mcint (0)
    {
        name = "  null";
        cout << "start mfun ......" << __func__ << name << endl;
    }
    Spk (int m):mcint (m), mint (m)
    {
        name = "  null";
        cout << "start  mfun ......" << __func__ << "(int m)" << name <<
             "#" << mint << endl;
    }
    Spk (string nm):mcint (0), name (nm), mint (0)
    {
        cout << "start mfun ......" << __func__ << "(name)" << name <<
             endl;
    }
    Spk (const Spk & r):mcint (r.mcint)
    {
        cout << "start mfun ......" << __func__ << "(const Spk&)" << name
             << endl;
    }
    Spk & operator = (const Spk & r)
    {
        cout << "start mfun ......" << __func__ << "=(const Spk&) " << name
             << endl;
        return *this;
    }
    ~Spk ()
    {
        cout << "start mfun ......" << __func__ << name << endl;
    }
    void one ()
    {
        cout << "start mfun ......" << __func__ << name << endl;
    }
    void two ()
    {
        cout << "start mfun ......" << __func__ << name << endl;
    };
    void speak (string str)
    {
        cout << str << "  start mfun ......" << __func__ << " adress is "
             << this << name << " #" << mint << endl;
    };
    void setname (string nm)
    {
        name = nm;
        cout << "start mfun ......" << __func__ << name << endl;
    }
    void setm (int n)
    {
        mint = n;
        //cout << "start mfun ......" << __func__ << name << " #"<<mint << endl;
    }
public:
    int mint;
    const int mcint;
    string name;
    static const int mstint = 100;
    typedef decltype (&cre::one) Fmp;

    vector < Fmp > me;
};


void tranarray (int ar[])
{
    cout << " in " << __func__ << '\t' << ar << " size of is ar " <<
         sizeof (ar) << endl;
}

void arrayaddone (int *ar, size_t size)
{
    for (int i = 0; i < size; ++i)
        ar[i] += 1;
}

void arrayaddself (int *ar, size_t size)
{
    for (int i = 0; i < size; ++i)
        ar[i] += ar[i];
}

void arraydynm (int size = 10)
{
    size = 10;
    int arr[10];

    for (int i = 0; i < size; ++i)
        {
            arr[i] = i;
            cout << arr[i] << '\t';
        }
    cout << endl;
}

int gai = 0;

int TestPrintAdd (int argc, char *argv[])
{

    const size_t size = 10;
    const int initalvalue = 2;
    const int mm = 0;
    static int ai = 0;
    int ar[size * 2];

    printadress (size);
    printadress (ar[0]);
    printadress (mm);
    printadress (gai);
    printadress (ai);
    arraydynm (10);
    tranarray (ar);
    cout << " in " << __func__ << '\t' << ar << " size of is ar " <<
         sizeof (ar) << endl;
    arrayset (ar, size, initalvalue);
    arrayprint (ar, size);
    arrayprintadress (ar, size);
    arrayaddself (ar, size);
    arrayprint (ar, size);
    arrayaddone (ar, size);
    arrayprint (ar, size);

    int A[10] = { 7 };
    for (int i = 0; i < 10; ++i)
        {
            *(A + i) = i;
            cout << i << '\t' << (A + i) << '\t' << *(A + i) << endl;
        }
    star ();
    int *pmark = safemalloc < int >(10, sizeof (int));
    int *p = pmark;

    for (int i = 0; i < 10; ++i)
        {
            *(p + i) = i;
            cout << i << '\t' << p + i << '\t' << *(p + i) << endl;
        }
    star ();
    for (int i = 0; i < 10; ++i)
        {
            cout << i << '\t' << p << '\t' << *p << endl;
            *p++;
        }
    p = nullptr;
    safefree (pmark);
    int *pa3[3];
    int (*pa4)[300];

    cout << sizeof (pa3) << endl;
    cout << sizeof (pa4) << endl;
    return 0;
}

template < typename T > T & selfadd (T & r, T & l)
{
    return r += l;
}

typedef int &(*fptr) (int &r, int &l);
typedef int &(**pfptr) (int &r, int &l);

int TestMalloc (int argc, char *argv[])
{
    int a = 4;
    int a1 = 5;
    int a2 = 6;
    fptr *fp;
    pfptr ff;
    fptr f;
    f = selfadd < int >;

    fp = safemalloc < fptr > (sizeof (fptr));
    *fp = selfadd < int >;

    ff = safemalloc < fptr > (sizeof (fptr));
    *ff = selfadd < int >;
    f = selfadd < int >;

    cout << (*ff) (a1, a1) << endl;
    cout << f (a, a) << endl;
    cout << (*fp) (a2, a2) << endl;
    printptr (fp);
    printptr (ff);
    printptr (f);
    safefree (fp);
    safefree (ff);
    cout << fp << endl;
    star ('_');
    int &b = selfadd (a, a);

    cout << a << '\t' << &a << endl;
    cout << b << '\t' << &b << endl;
    double c = 2.2;
    double d = 3.3;

    cout << selfadd (c, d) << endl;
    int *p;
    int *p2;
    int *p3;
    long *p5;
    int nu = 8;

    cout << "please input want malloc memeory for element number:" << endl;
    cin >> nu;

    if (p = safemalloc < int >(nu, sizeof (int)))
        cout << "malloc is ok...... address is " << p << endl;
    if (p2 = (int *) malloc (nu * sizeof (int)))
        cout << "malloc is ok...... address is " << p2 << endl;
    int pt = max (p, p2) - min (p, p2);
    int pr = (long) max (p, p2) - (long) min (p, p2);

    cout << pt << endl;
    cout << pr << endl;
    cout << sizeof (int) << endl;
    free (p2);
    safefree (p);
    cout << "safe free after p is " << p << endl;
    if (p3 = (int *) malloc (nu * sizeof (int)))
        cout << "malloc is ok...... address is " << p3 << endl;
    free (p3);
    p5 = safemalloc < long >(nu, sizeof (long));

    safefree (p5);
    return 0;
}

Spk ga ("ga");
static Spk gsa ("gsa");

int TestSubClass (int argc, char *argv[])
{
    cout << __func__ << "#" << __LINE__ << endl;
    static Spk sa ("sa");
    static Spk sb ("sb");
    static Spk sc ("sc");

    sa.speak ("sa is speak");
    sb.speak ("sb is speak");
    sc.speak ("sc is speak");
    ga.speak ("ga is speak");
    gsa.speak ("gsa is speak");
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}

int TestSubTwo (int argc, char *argv[])
{
    cout << __func__ << "#" << __LINE__ << endl;
    static Spk sa ("sa");
    static Spk sb ("sb");

    sa.speak ("sa is speak");
    sb.speak ("sb is speak");
    ga.speak ("ga is speak");
    gsa.speak ("gsa is speak");
    TestSubClass (argc, argv);
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}


int TestArrayMalloc (int argc, char *argv[])
{
    cout << __func__ << "#" << __LINE__ << endl;
    size_t l = 10;
    size_t c = 10;
    size_t size = l * sizeof (int *) + l * c * sizeof (int);

    cout << size << endl;
    int *p = safemalloc < int >(size);
    const int initval = 20;
    int **pint = (int **) p;
    char *pc = (char *) p;

    pint += l;
    pc += l * sizeof (int *);
    cout << pc << endl;
    cout << sizeof (int **) << '\t' << sizeof (int *) << '\t' <<
         sizeof (int) << endl;
    int *pu = (int *) pint;

    star ();
    cout << dec << "p is " << p << '\t' << "pint is  " << pint << '\t' <<
         "ps is " << (long) pc << '\t' << pu << endl;

    arrayset (pu, l * c, initval);
    arrayprint (pu, l * c);
    foreach < int >(pu, pu + l * c, disp < int *>);

    safefree (p);
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}

template < typename T > bool add (T * e)
{
    ++*e;
    return true;
}

void phello ()
{
    cout << "hello" << endl;
}

int TestGround (int argc, char *argv[])
{
    cout << "start test ......" << endl;
    Spk one;

    one.setm (1);
    one.speak ("One");
    Spk *pOne = new Spk (" in heap new Spk");

    pOne->setm (2);
    pOne->speak ("pOne");
    cout << TestGround << endl;
    using funp = void (*)();
    funp fx = phello;

    fx ();
    (*fx) ();
//    char * e = argv[0];

//    for (int i = 0; i < argc; e = argv[i],i++)
//        cout << *e << endl;
    auto tab='\t';
    cout<<argc<<endl;
    star('_');
    delete pOne;

    return 0;
}

int TestArrayMallocPoint (int argc, char *argv[])
{
    cout << __func__ << "#" << __LINE__ << endl;
    size_t l = 10;
    size_t c = 10;
    size_t size = l * sizeof (int *) + l * c * sizeof (int);
    int *p = safemalloc < int >(size);
    const int initval = 20;
    int **pint = (int **) p;

    pint += l;
    int *pu = (int *) pint;

    arrayset (pu, l * c, initval);
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            *(pu + i * c + j) = (i + 1) * (1 + j);


    arrayprint (pu, l * c);
    Spk *pspk = (Spk *) new Spk[l * c];

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            (*(pspk + i * c + j)).setm (i * c + j + 1);
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            (pspk + i * c + j)->speak ("ls");
    pspk[98].speak ("ok");
    cout << sizeof (Spk) << endl;
    cout << typeid (Spk).name () << endl;

    cout << boolalpha << true << endl;
    cout << boolalpha << true << endl;
    system ("pause");

    delete[]pspk;
    safefree (p);
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}


class NewMan;

class NewMan
{

public:
    NewMan (int age):meage (age)
    {

    }
    static int sayage (class NewMan * me)
    {
        cout << me->meage << endl;
        return me->meage;
    }
    void say ()
    {
        sayage (this);
    }

private:
    int meage;
};

int Test (int argc, char *argv[])
{
    unsigned long int max = 1;
    int ic = sizeof (max) * 8;

    for (int i = 0; i < ic - 1; ++i)
        max *= 2;
    cout << ic << endl;
    cout << " max * 63^ is " << max << endl;
    cout << " max * 63^ *2 is " << max * 2 << endl;
    NewMan one (18), two (20);

    one.say ();
    two.say ();
    NewMan::sayage (&one);
    NewMan::sayage (&two);
    one.sayage (&two);
    one.sayage (&one);
    one.sayage (&two);
    two.sayage (&two);

    return 0;
}

#include <bitset>

int TestBitSet (int argc, char *argv[])
{
    unsigned int a = 256 * 256 * 256 * 256 - 1;
    int c = a;
    unsigned int b = 256 * 256 * 256 * 256 - 1;

    cout << bitset < 32 > (a) << '\t' << a << '\t' << sizeof (int) << endl;
    cout << bitset < 32 > (c) << '\t' << c << endl;
    c = -3;
    cout << bitset < 32 > (c) << '\t' << c << endl;
    star ("<<8");
    a <<= 8;
    cout << bitset < 32 > (a) << endl;
    cout << bitset < 32 > (b * 256) << endl;
    star (">>8");
    a >>= 8;
    cout << bitset < 32 > (a) << endl;
    cout << bitset < 32 > (b / 256) << endl;
    int d = -8;

    c = 8;
    star ("<<+");
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;
    d <<= 2;
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;

    star ("c+<<");
    cout << bitset < 32 > (c) << '\t' << c << '\t' << sizeof (int) << endl;
    c <<= 2;
    cout << bitset < 32 > (c) << '\t' << c << '\t' << sizeof (int) << endl;
    star ('+c');

    c = 8;
    star ("c+>>");
    cout << bitset < 32 > (c) << '\t' << c << '\t' << sizeof (int) << endl;
    c >>= 2;
    cout << bitset < 32 > (c) << '\t' << c << '\t' << sizeof (int) << endl;

    d = -8;
    star ("d->>-");
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;
    d >>= 2;
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;
    star ("d/8");
    d = -8;
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;
    d /= 4;
    cout << bitset < 32 > (d) << '\t' << d << '\t' << sizeof (int) << endl;
    return 0;
}
#define ADDMENU(menu,funcname,str)   {\
        str = #funcname;\
        menu.push_back (str);\
        Command.push_back (funcname);\
        }

int itestpreath=0;
void *printselfint(void *args)
{
    static int icount=0;
    ++icount;
    ++itestpreath;
    cout<<"# icount is "<<icount<<" itestpreadth is "<< itestpreath<<" pthread id is "<<pthread_self()<<endl;
    return nullptr;
}

int TestPthread(int argc, char *argv[])
{
    pthread_t ptd_1;
    pthread_create(&ptd_1,nullptr,printselfint,nullptr);
    pthread_t ptd_2;
    pthread_create(&ptd_2,nullptr,printselfint,nullptr);
    pthread_join(ptd_1,nullptr);
    pthread_join(ptd_2,nullptr);

    return 0;
}
template<typename T>
concept concanisempty = requires(T v)
{
    v.isempty();
};


int StringTestFN (int argc, char *argv[])
{
    string str1(4,'x');
    cout<<str1<<endl;
    string str2=str1;
    cout<<str2<<endl;
    string str3(str1);
    cout<<str3<<endl;
    string str5="123456";
    string str6(str5,2,2);
    cout<<str5<<endl;
    cout<<str6<<endl;
    cout<<str6.size()<<endl;
    cout<<str6.length()<<endl;
    string str7="123456";
    cout<<str7.length()<<endl;
    char *str8="123456";
    cout<<strlen(str8)<<endl;
    cout<<str7.data()<<endl;
    cout<<str7.c_str()<<endl;
    string str9="456";
    cout<<boolalpha<<(str9>str8)<<endl;
    cout<<boolalpha<<(str8>str9)<<endl;
    str7.append(str9);
    cout<<str7<<endl;
    cout<<string::npos<<endl;
    cout<<str7.find("4")<<endl;
    cout<<str7.rfind("4")<<endl;
    cout<<str7.erase(1,3)<<endl;
//    cout<<str7.insert(1,3,"23456")<<endl;
    return 0;
}

/*template<typename...Args, int N,int SIZE>
void disptuple(tuple<Args...> tu)
{
    if(N<=SIZE)
        return;
    cout<<std::get<N>(tu);
    disptupe<tuple<Args...>,N+1,SIZE>(tu);
}
*/
template<typename...Args>
void display(tuple<Args...> tu)
{
    constexpr size_t length = sizeof...(Args);
    for(int i=0;i<length;++i)
        cout<<get(i)(tu);
}


int TestTuple (int argc, char *argv[])
{
    tuple<int,float,float>tupa{2,4.4,5.6};

    display(tupa);



    return 0;
}

struct menuitem{
    size_t id;
    string name;
    pPF *com;
}



int RunMyTestFN (int argc, char *argv[])
{
    vector < string > Menu;
    vector < pPF > Command;
    string strMenuTitle =
        "Please choice a Menu command No to run a command,choice 0 = exit...";
    Menu.push_back (strMenuTitle);
    Command.push_back (nullptr);
    string strMenuName;

    ADDMENU(Menu,TestTuple,strMenuName)
    ADDMENU(Menu,StringTestFN,strMenuName)
    ADDMENU(Menu,TestPthread,strMenuName)
    ADDMENU(Menu,TestBitSet,strMenuName)
    ADDMENU(Menu,Test,strMenuName)
    ADDMENU(Menu,ReferenceTest,strMenuName)
    ADDMENU(Menu,TestGround,strMenuName)

    RunMenuMU (argc, argv, Menu, Command);
    cout << __func__ << "#" << __LINE__ << endl;
    return 0;
}
