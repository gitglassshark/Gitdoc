#include <iostream>
#include <vector>
#include <string>
#include "h.hpp"
//#include "fun.hpp"
#include "printmessage.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    //input your program:
    cout << "start main......\n";
    runantestbool ();
    int i;
    if (argc >= 2)
    {
        i = atoi (argv[1]);
    }
    cout << "argc is " << argc << endl;
    togoto(i);
    int x=0;
    int z=0;
    testarraysizeof(i, x, z);
    arradd(5); 
    cout<<"end main.....\n";
    return 0;
}

int arradd(int i)
{
    int  carr[9]={
        9,8,7,6,5,4,3,2,1
    };
    cout<<*carr+2<<endl;
    cout<<*(carr+2)<<endl;
    return 0;
}
