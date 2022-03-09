/***************************************************************************
**
**************************************************************************/
#pragma once

//


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


