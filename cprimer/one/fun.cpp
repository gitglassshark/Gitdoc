#include<iostream>
#include "fun.hpp"
#include "number.hpp"

using namespace std;


int print_size(int i)
{
    x=sizeof(i);
    cout<<"The int number size of is "<<x<<endl;
    cout<<"The int number max number is "<<maxsizeofn(i)<<endl;
    return x;
}

long long int maxsizeofn(long long int i)
{
    y=sizeof(i)*8-2;
    long long int max=2;
    for (x=0;x<y;x++)
        max=2*max;
    return (max+max/2);
}
