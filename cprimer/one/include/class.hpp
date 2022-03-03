 #include <iostream>
using namespace std;
// class declare
//
class Fish
{
protected:
    int size;
public:
    Fish():size(20)
    {
        cout<<"+Fish is borning ...,size is "<<size<<__func__<<endl;
    };
    Fish(int bornsize):size(bornsize)
    {
        size=bornsize;
        cout<<"+Fish is borning ...,size is "<<size<<__func__<<endl;
    };
    virtual void baby()
    {
        cout<<"My baby is small fish!"<<endl;
    };
    ~Fish()
    {
        cout<<"~Fish is dying...,size is "<<size<<endl;
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
public:
    Whole():Fish()
    {
        size=100;
        cout<<"+whole is borning......,size is "<<size<<__func__<<endl;
    };
    Whole& operator ++(){
        cout<<"in ++Whole"<<endl;
        return *this;
    }
    Whole & operator ++(int a){
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
