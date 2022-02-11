#include <iostream>
#include <vector>
#include <string>
#include "h.hpp"
//#include "fun.hpp"
#include "printmessage.hpp"

using namespace std;

int main (int argc,char * argv[] )
{
    //input your program:
    int i=atoi(argv[1]);
    cout<<"argc is "<<argc<<endl;
    int n=0;
start:
    cout << "start main......\n";

    runantestbool ();
    if(n<i)
    {
        n++; 
        goto start;
    }
    cout << "end main......\n";
    return 0;
}
