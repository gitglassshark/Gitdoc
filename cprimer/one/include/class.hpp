#include <iostream>
using namespace std;
// class declare
//
class Fish
{
protected:
    int size;
    int * weight;
public:
    Fish():size(20),weight(nullptr)
    {
        weight=new int(size*4);
        cout<<"+Fish is borning ...,size is "<<size<<__func__<<endl;
    };
    Fish(int nsize,int nweight):size(nsize),weight(nullptr)
    {
        weight=new int(nweight);
        cout<<"+Fish is borning ...,size is "<<size<<__func__<<endl;
    };
    Fish(int bornsize):size(bornsize),weight(nullptr)
    {
        size=bornsize;
        weight=new int(size*4);
        cout<<"+Fish is borning ...,size is "<<size<<__func__<<endl;
    };
    Fish(Fish &r)
    {
        size=r.getsize();
        weight=new int(*r.weight);
        cout<<"+Fish is borning copy ...,size is "<<size<<__func__<<endl;
    };
    Fish &operator =(Fish &r)
    {
        size=r.getsize();
        if(weight)
            weight=new int(*r.weight);
        cout<<"+Fish is = ...,size is "<<size<<__func__<<endl;
        return *this;
    };
    virtual void baby()
    {
        cout<<"My baby is small fish!"<<endl;
    };
    ~Fish()
    {
        delete weight;
        weight=NULL;
        cout<<"~Fish is dying...,size is "<<size<<endl;
    };
    int getweight()
    {
        return *weight;
    };
    int getsize()
    {
        return size;
    };
    int setsize(int newsize)
    {
        return size=newsize;
    };
    void name()
    {
        cout<<"I am a Fish";
    };
    void name(char *pname)
    {
        cout<<"I am a Fish "<<pname<<endl;
    };
};
class Whole:public Fish
{
protected:
    Fish smallfish;
public:
    Whole():Fish(100),smallfish(100)
    {
        size=100;
        cout<<"+whole is borning......,size is "<<size<<__func__<<endl;
    };
    Whole(int nsize):Fish(nsize),smallfish(nsize*2)
    {
        size=nsize;
        cout<<"+whole is borning......,size is "<<size<<__func__<<endl;
    };
    Whole& operator ++()
    {
        cout<<"in ++Whole"<<endl;
        return *this;
    }
    Whole & operator ++(int a)
    {
        cout<<"in Whole++"<<endl;
        return *this;
    }
    virtual void baby()
    {
        cout<<"My baby is small whole!"<<endl;
    };
    ~Whole()
    {
        cout<<"~whole is dying......,size is "<<size<<__func__<<endl;
    };
    using Fish::name;
    void name()
    {
        cout<<"I am a Whole.";
    };
    void name(char *pname)
    {
        cout<<"I am a Whole "<<pname<<endl;
    };
};
