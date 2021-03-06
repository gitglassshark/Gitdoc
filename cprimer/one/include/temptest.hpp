/*******************************************
 **
 **********************************************/
#pragma once

#include <typeinfo>
#include <cstdlib>
#include "mylib.hpp"

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

int add(int a,int b)
{
    cout<<"int add"<<endl;
    int c;
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

