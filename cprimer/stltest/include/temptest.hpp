/*******************************************
 **
 **********************************************/
#pragma once

#include <typeinfo>
#include <cstdlib>
#include "mylib.hpp"


template <typename T>
bool negate_1(T r)
{
    *r=-*r;
    return true;
}

template <typename T>
bool plus_1(T r)
{
    ++*r;
    return true;
}

template <typename T>
bool disp(T r)
{
    cout<<*r<<'\t';
    return true;
}

template <typename T>
T foreach(T b,T e,bool (*Fun)(T r))
    {
        for(auto i=b; i!=e; ++i)
            Fun(i);
        return b;
    }

template <typename T>
void PrintSingleEle(const T&r)
{
    cout<<r<<t;
}

template <typename T>
bool PrintEle(const T&r)
{
    int il=0;
    if(r.empty())
        return false;
    for(const auto &i:r)
        {
            if(++il%10==0)
                {
                    PrintSingleEle(i);
                    cout<<endl;
                }
            else
                PrintSingleEle(i);
        }
    cout<<endl;
    return true;
}

template <typename T>
void MakeSingleEleRandom(T&r,const int mod)
{
    r=random()%mod;
}
template <class T>
int makedeque(deque<T>&r,int nsize,int mod)
{
    for(int i=0; i<nsize; ++i)
        r.push_back(rand()%mod);
    return 0;
}

template <class T>
int listlist(const list<T>&r)
{
    int il=0;
    star('_');
    for(auto i:r)
        {
            cout<<i;
            //            if((ic++%10)==9)
            if(++il%10==0)
                cout<<e;
            else
                cout<<"\t";
        }
    if(il%10!=0)
        cout<<endl;
    return 0;
}


template <class T>
int MakeList(list<T>&r,int mod)
{
    for(auto &i:r)
        i=random()%mod;
    return 0;
}

template <typename T>
int printList(list<T>&r)
{
    int il=0;
    for(typename list<T>::iterator it=r.begin(); it!=r.end(); ++it)
        {
            cout<<*it;
            if(++il%10==0)
                cout<<e;
            else
                cout<<"\t";
        }
    if(il%10!=0)
        cout<<endl;
    return 0;
}

template<typename T>
bool rcmp(T a,T b)
{
    return a<b;
}

template<typename T>
bool cmp(T a,T b)
{
    return a>b;
}

template <class T>
int MakeStack(stack<T>&r,int num,int mod)
{
    for(int i=0; i<num; ++i)
        r.push(random()%mod);
    return 0;
}


template <class T>
int listdeque(const deque<T>&r)
{
    int il=0;
    star('_');
    for(auto i:r)
        {
            cout<<i;
            //            if((ic++%10)==9)
            if(++il%10==0)
                cout<<e;
            else
                cout<<"\t";
        }
    if(il%10!=0)
        cout<<endl;
    return 0;
}

template <typename T>
bool MakeEleRandom(T&r,const int mod)
{
    if(r.empty())
        return false;
    for(auto &i:r)
        MakeSingleEleRandom(i,mod);
    return true;
}

template<typename T>
int MakeDisplaySet(T &r)
{
    int ic=0;
    for(auto i:r)
        {
            cout<<i;
            if(++ic%10==0)
                cout<<endl;
            else
                cout<<'\t';
        }
    cout<<endl;
    return 0;
}

template<typename T>
int MakeRandomSet(T &r,const int num,const int mod)
{
    for(int i=0; i<num; ++i)
        r.insert(random()%(mod?mod:1));
    return 0;
}

template<typename T>
auto FindMaxInSet(const T &r)
{
//    typename T::iterator itmax=r.begin();
    auto itmax=r.begin();
    if(r.begin()==r.end())
        return itmax;
    for(auto it=r.begin(); it!=r.end(); ++it)
        {
            if(*itmax<*it)
                itmax=it;
        }
    return itmax;
}

//template <typename T,typename S>
//typename T::iterator DeleteSelementInSet(T &r,S &s)


template<typename T,typename X>
int TransferSet(T &s,X&d)
{
    for(auto &i:s)
        d.insert(i);
    return 0;
}
template <class T>
int listvector(const vector<T>&r)
{
    int il=0;
    cout<<"vector capacity is "<<r.capacity()<<endl;
    for(auto i:r)
        {
            cout<<i;
            //            if((ic++%10)==9)
            if(++il%10==0)
                cout<<e;
            else
                cout<<"\t";
        }
    cout<<endl;
    return 0;
}

template <class X,class Y>
class Lion
{
public:
    int teeth;
    string *name;
    unsigned age;
    Lion()
    {
        cout<<typeid(*this).name()<<t<<"lion is borning no argument constroator...."<<endl;
        name=nullptr;
        age=0;
    }
    Lion(X oname,Y oage)
    {
        cout<<typeid(*this).name()<<t<<"lion is borning ...."<<endl;
        name=new string(oname);
        age=oage;
    }
    Lion(const Lion &r)
    {
        cout<<typeid(*this).name()<<t<<"Lion(const Lion &r)"<<endl;
        this->teeth=r.teeth;
        this->age=r.age;
        name=new string(*r.name);
    }
    Lion &operator=(const Lion &r)
    {
        cout<<typeid(*this).name()<<t<<"Lion="<<endl;
        this->teeth=r.teeth;
        this->age=r.age;
        star("this->sex=r.sex");
        this->sex=r.sex;
        if(name!=nullptr)
            delete name;
        name=new string(*r.name);
        return *this;
    }
    ~Lion()
    {
        cout<<typeid(*this).name()<<t<<"~lion is vanish...."<<endl;
        delete name;
    }
    void yell()
    {
        cout<<typeid(*this).name()<<t<<"OwOw....."<<endl;
    }
    void yell(const Lion &r)
    {
        cout<<"r sex is  "<<r.sex<<endl;
    }
protected:
    int killn;
private:
    int sex;
};

template <class X>
X add(X a,X b)
{
    cout<<"temp x add"<<endl;
    X c;
    c=a+b;
    return c;
}


template <typename X,typename T>
X sub(X a,T b)
{
    cout<<"temp x sub"<<endl;
    X c;
    c=a-(X)b;
    return c;
}

template <typename T>
T tadd(T a,T b)
{
    cout<<"temp T tadd"<<endl;
    T c;
    c=a+b;
    return c;
}

template <class X>
class demoArray
{
private:
    X *h_ArrayMem;
    unsigned int maxsize=1000;
protected:
    unsigned int memsize;
    unsigned int currentsize;

public:
    demoArray():currentsize(0),memsize(10),h_ArrayMem(nullptr)
    {
        h_ArrayMem=new X[memsize];
        for(int i=0; i<memsize; ++i)
            h_ArrayMem[i]=0;
        cout<<__func__<<endl;
    }

    demoArray(const unsigned int isize)
    {
        if(isize>=maxsize)
            memsize=maxsize;
        else
            memsize=isize;
        h_ArrayMem=new X[memsize];
        for(int i=0; i<memsize; ++i)
            h_ArrayMem[i]=0;
        currentsize=0;
        cout<<__func__<<endl;
    }

    demoArray(const demoArray &r)
    {
        h_ArrayMem=new X[r.memsize];
        for(int i=0; i<r.currentsize; ++i)
            h_ArrayMem[i]=r.h_ArrayMem[i];
        cout<<__func__<<endl;
    }

    demoArray& operator=(const demoArray &r)
    {
        if(h_ArrayMem!=nullptr)
            delete []h_ArrayMem;
        currentsize=r.currentsize;
        memsize=r.memsize;
        maxsize=r.maxsize;
        h_ArrayMem=new X[memsize];
        for(int i=0; i<r.currentsize; ++i)
            h_ArrayMem[i]=r.h_ArrayMem[i];
        cout<<__func__<<endl;
        return *this;
    }

    ~demoArray()
    {
        cout<<__func__<<endl;
        if(h_ArrayMem)
            delete [] h_ArrayMem;
    }

    X& operator=(const X r)
    {
        cout<<__func__<<endl;
        return r;
    }

    X& operator[](const unsigned int i)const
    {
        cout<<__func__<<endl;
        if(i<memsize)
            return h_ArrayMem[i];
    }

    bool list(const unsigned int start=0,const unsigned int end=0)
    {
        if(end==0)
            {
                for(int i=0; i<memsize; ++i)
                    {
                        cout<<h_ArrayMem[i]<<" ";
                        if((i+1)%10==0)
                            cout<<endl;
                    }
                cout<<endl;
            }
        return true;
    }

    bool pushback(X iu)
    {
        bool isscusses=false;
        if(currentsize<memsize)
            {
                h_ArrayMem[currentsize]=iu;
                ++currentsize;
                isscusses=true;
            }
        else
            {
                X *h=h_ArrayMem;
                if(memsize<=maxsize-10)
                    {
                        memsize+=10;
                        h_ArrayMem=new X[memsize];
                        for(int i=0; i<currentsize; ++i)
                            h_ArrayMem[i]=h[i];
                        h_ArrayMem[currentsize]=iu;
                        ++currentsize;
                        delete [] h;
                        isscusses=true;
                    }
            }
        return isscusses;
    }

    bool popback(unsigned int i)
    {
        bool isscusses=false;
        if(currentsize==0)
            {
                return isscusses;
            }
        else
            {
                --currentsize;
                isscusses=true;
            }
        return isscusses;
    }
    bool setallrandom()
    {
        bool isscusses=false;
        if(memsize!=0)
            {
                for(int i=0; i<memsize; ++i)
                    h_ArrayMem[i]=random()%1000;
                isscusses=true;
            }
        return isscusses;
    }

    unsigned int getmaxsize()const
    {
        return maxsize;
    }

    unsigned int getmemsize()const
    {
        return  memsize;
    }

    unsigned int  getcurrentsize()const
    {
        return   currentsize;
    }
};


template <class X>
class demo
{
public:

protected:

private:

};

