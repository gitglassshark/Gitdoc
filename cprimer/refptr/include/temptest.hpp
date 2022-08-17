#pragma once

#include <typeinfo>
#include <cstdlib>
#include "mylib.hpp"
#include <iostream>

#define bigtosmall true
#define smalltobig false
#define UP true
#define UPPER true
#define LOWER false
#define LOW false
//#define DOWN false
#define RESET -1
#define REVERSE -2
#define KEEPSTATUS -3
#define NOT !
#define nonull(v) (( (v )!=nullptr  )&&((&v)!=nullptr ) )

#define NTIME(N)  for(size_t ix=0;ix<(N);++ix)
#define STEP(I,STEP,N)  for(size_t (ix)=I;(ix)<(N);ix+=(STEP))
#define STEPTO(I,STEP,N)  for(size_t (ix)=I;(ix)<=(N);ix+=(STEP))
#define UNTIL(N) for(size_t ix=0;ix++<(N);)
#define FORTO(I,N) for(size_t ix=(I);ix<=(N);++ix)
#define FORDOWNTO(N,I) for(size_t ix=(N);ix>=(I);--ix)
#define pointer *
#define NOTHING
#define EMPTY(...)
#define ref &

#define gett(name)  decltype(name)
#define getI(name)  gett(name.begin())
#define getCI(name)  gett(name)::const_iterator
#define ALL(V)  V.begin(),V.end()
#define FORALL(V,iterator)  for(getCI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORALLW(V,iterator)  for(getCI(V) V##iterator = V.begin(); V##iterator != V.end();++V##iterator)
#define FORN(N,icountn)  for(size_t icountn=0;icountn<(N);++icountn)
#define FORV(ielement,V)  for(const auto &ielement:V)
#define FORW(ielement,V)  for(auto &ielement:V)

#define sst(code,...)  #code##","#__VA_ARGS__;

#define code(...)   cout<<"{ "#__VA_ARGS__<<L"  }"<<el;\
                    __VA_ARGS__;

#define lcode(...)  cout<<"{ "#__VA_ARGS__<<L"  }"<<el;\
                    __VA_ARGS__;

#define showcode(...)   lcode(__VA_ARGS__)
#define showcodes(...)  lcode(__VA_ARGS__)
#define lscode(...)  lcode(__VA_ARGS__)

#define SHOW(name) cout<<st(name)<<_T("  is: ")<<name<<tab
#define showv(vname) cout<<st(vname)<<_T(" value: ")<<vname<<sp<<_T(" type: ")<<(typeid(vname).name())<<sp
#define showtype(...)  cout<<#__VA_ARGS__<<":  type: ";\
                            cout<< typeid( ##__VA_ARGS__  ).name( );\
                        cout<<"  size: ";\
                        cout<<sizeof(##__VA_ARGS__);\
                        cout<<"  HASH :"<<typeid(##__VA_ARGS__).hash_code()<<el


#define Mptr(va,tp) unique_ptr<tp>va=make_unique<tp>();
#define Msptr(va,tp) shared_ptr<tp>va=make_shared<tp>();
#define Mptrs(va,tp,n) unique_ptr<tp[]>va=make_unique<tp[]>(n);
#define Msptrs(va,tp,n) shared_ptr<tp[]>va=make_shared<tp[]>(n);


#define abstype(a)      {std::string sc = "";\
                        if ( std::is_const<decltype( a  )>::value  )\
                        sc = "const ";\
                        sc += typeid( a  ).name( );\
                        if ( std::is_reference<decltype( a  )>::value  )\
                        sc += "&";\
                        if ( std::is_rvalue_reference<decltype( a  )>::value  )\
                        sc += "&";\
                        cout << "type:  " << sc << "  size:  ";\
                        cout<< sizeof( a  );\
                        cout<<"  HASH: " << typeid( a  ).hash_code( ) << el;}



template < typename T >
T * arrayset (T * const ar, const size_t size, const T x)
{
    for (size_t i = 0; i < size; ++i)
        ar[i] = x;
    return ar;
}

template < typename T > void arrayprintadress (T * ar, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        cout << "ar[i] adress is " << &ar[i] << '\t' << "value is " <<
             ar[i] << endl;
        cout << "ar+i adress is " << ar +
             i << '\t' << "value is " << *(ar + i) << endl;
    }
}

template < typename T > void arrayprint (T * ar, size_t size, int lc = 10)
{
    int l = 0;

    if (ar == nullptr)
        return;
    for (size_t i = 0; i < size; ++i) {
//        cout << ar[i] << '\t';
        if (++l % lc == 0)
            cout << endl;
    }
    cout << endl;
}

template < typename T > void *printptr (T * r)
{
    cout << "point adress is " << r << " pointer size is " << sizeof (T *)
         << endl;
    return (void *) r;
}

template < typename T > void *printadress (T & r)
{
    cout << &r << endl;
    return (void *) &r;
}

template < typename T > T * safemalloc (size_t memsize, size_t elesize = 1)
{
    void *p = nullptr;

    p = malloc (memsize * elesize);
    if (!p)
        cout << "malloc fail..." << endl;
    else
        cout << "in adress: " << p << " malloc " << memsize *
             elesize << "  byte memory in " << __func__ << " T size is " <<
             sizeof (T) << endl;
    return (T *) p;
}

template < typename T > T * &safefree (T * &p)
{
    cout << "safefree " << p << __func__ << endl;
    if (p)
        free (p);
    p = nullptr;
    return p;
}

template < typename T > bool negate_1 (T r)
{
    *r = -*r;
    return true;
}

template < typename T > bool plus_1 (T r)
{
    ++*r;
    return true;
}

template < typename T > bool disp (T r)
{
    cout << *r << '\t';
    return true;
}

template < typename T > T foreach (T * b, T * e, bool (*Fun) (T * r))
{
    for (auto i = b; i != e; ++i)
        Fun (i);
    return *b;
}

template < typename T > bool Print (T * r)
{
    cout << *r << t;
    return true;
}

template < typename T > bool PrintSingleEle (T & r)
{
    cout << r << t;
    return true;
}



template < typename T > bool PrintEle (const T & r)
{
    int il = 0;

    if (r.empty ())
        return false;
    for (const auto & i:r) {
        if (++il % 10 == 0) {
            PrintSingleEle (i);
            cout << endl;
        } else
            PrintSingleEle (i);
    }
    cout << endl;
    return true;
}

template < typename T >
void MakeSingleEleRandom (T & r, const int mod)
{
    r = rand () % mod;
}

template < typename T > bool MakeEleRandom (T & r, const int mod)
{
    if (r.empty ())return false;
    for (auto & i:r)
        MakeSingleEleRandom (i, mod);
    return true;
}

template < class T > int listvector (const vector < T > &r)
{
    int il = 0;
    cout << "vector capacity is " << r.capacity () << endl;
    for (auto i:r) {
        cout << i;
        //            if((ic++%10)==9)
        if (++il % 10 == 0) cout << e;
        else
            cout << "\t";
    }
    cout << endl;
    return 0;
}

template < class X, class Y > class Lion
{
public:
    int teeth;
    string * name;
    unsigned age;
    Lion ()
    {
        cout << typeid (*this).
             name () << t << "lion is borning no argument constroator...." <<
             endl;
        name = nullptr;
        age = 0;
    }
    Lion (X oname, Y oage)
    {
        cout << typeid (*this).
             name () << t << "lion is borning ...." << endl;
        name = new string (oname);
        age = oage;
    }
    Lion (const Lion & r)
    {
        cout << typeid (*this).
             name () << t << "Lion(const Lion &r)" << endl;
        this->teeth = r.teeth;
        this->age = r.age;
        name = new string (*r.name);
    }
    Lion & operator= (const Lion & r)
    {
        cout << typeid (*this).name () << t << "Lion=" << endl;
        this->teeth = r.teeth;
        this->age = r.age;
        star ("this->sex=r.sex");
        this->sex = r.sex;
        if (name != nullptr)
            delete name;
        name = new string (*r.name);
        return *this;
    }
    ~Lion ()
    {
        cout << typeid (*this).
             name () << t << "~lion is vanish...." << endl;
        delete name;
    }
    void yell ()
    {
        cout << typeid (*this).name () << t << "OwOw....." << endl;
    }
    void yell (const Lion & r)
    {
        cout << "r sex is  " << r.sex << endl;
    }
protected:
    int killn;
private:
    int sex;
};
template < class X > X add (X a, X b)

{
    cout << "temp x add" << endl;
    X c;
    c = a + b;
    return c;
}


template < typename X, typename T > X sub (X a, T b)
{
    cout << "temp x sub" << endl;
    X c;
    c = a - (X) b;
    return c;
}

template < typename T > T tadd (T a, T b)
{
    cout << "temp T tadd" << endl;
    T c;
    c = a + b;
    return c;
}

template < class X > class demoArray
{
private:
    X * h_ArrayMem;
    unsigned int maxsize = 1000;
protected:
    unsigned int memsize;
    unsigned int currentsize;
public:
    demoArray ():currentsize (0), memsize (10),
        h_ArrayMem (nullptr)
    {
        h_ArrayMem = new X[memsize];
        for (int i = 0; i < memsize; ++i)
            h_ArrayMem[i] = 0;
        cout << __func__ << endl;
    }

    demoArray (const unsigned int isize)
    {
        if (isize >= maxsize) memsize = maxsize;
        else
            memsize = isize;
        h_ArrayMem = new X[memsize];
        for (int i = 0; i < memsize; ++i)
            h_ArrayMem[i] = 0;
        currentsize = 0;
        cout << __func__ << endl;
    }

    demoArray (const demoArray & r)
    {
        h_ArrayMem = new X[r.memsize];
        for (int i = 0; i < r.currentsize; ++i)
            h_ArrayMem[i] = r.h_ArrayMem[i];
        cout << __func__ << endl;
    }

    demoArray & operator= (const demoArray & r)
    {
        if (h_ArrayMem != nullptr)
            delete[]h_ArrayMem;
        currentsize = r.currentsize;
        memsize = r.memsize;
        maxsize = r.maxsize;
        h_ArrayMem = new X[memsize];
        for (int i = 0; i < r.currentsize; ++i)
            h_ArrayMem[i] = r.h_ArrayMem[i];
        cout << __func__ << endl;
        return *this;
    }

    ~demoArray ()
    {
        cout << __func__ << endl;
        if (h_ArrayMem) delete[]h_ArrayMem;
    }

    X & operator= (const X r)
    {
        cout << __func__ << endl;
        return r;
    }

    X & operator[](const unsigned int i) const
    {
        cout << __func__ << endl;
        if (i < memsize) return h_ArrayMem[i];
    }

    bool list (const unsigned int start = 0, const unsigned int end =
                   0)
    {
        if (end == 0) {
            for (int i = 0; i < memsize; ++i) {
                cout << h_ArrayMem[i] << " ";
                if ((i + 1) % 10 == 0) cout << endl;
            }
            cout << endl;
        }
        return true;
    }

    bool pushback (X iu)
    {
        bool isscusses = false;
        if (currentsize < memsize) {
            h_ArrayMem[currentsize] = iu;
            ++currentsize;
            isscusses = true;
        } else {
            X * h = h_ArrayMem;
            if (memsize <= maxsize - 10) {
                memsize += 10;
                h_ArrayMem = new X[memsize];
                for (int i = 0; i < currentsize; ++i)
                    h_ArrayMem[i] = h[i];
                h_ArrayMem[currentsize] = iu;
                ++currentsize;
                delete[]h;
                isscusses = true;
            }
        }
        return isscusses;
    }

    bool popback (unsigned int i)
    {
        bool isscusses = false;
        if (currentsize == 0) {
            return isscusses;
        } else {
            --currentsize;
            isscusses = true;
        }
        return isscusses;
    }
    bool setallrandom ()
    {
        bool isscusses = false;
        if (memsize != 0) {
            for (int i = 0; i < memsize; ++i)
                h_ArrayMem[i] = rand () % 1000;
            isscusses = true;
        }
        return isscusses;
    }

    unsigned int getmaxsize ()const
    {
        return maxsize;
    }

    unsigned int getmemsize ()const
    {
        return memsize;
    }

    unsigned int getcurrentsize ()const
    {
        return currentsize;
    }
};
template < class X > class demo

{
public:

protected:

private:

};
