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
    int argc1;
    if (argc >= 2)
    {
        argc1 = atoi (argv[1]);
    }
    cout << "argc is " << argc << endl;
    // begin run and test
    //
    runmytest(argc, argv);
    getchar();
    runtestbool ();
    togoto(argc1);
    getchar();
    getchar();
    testarraysizeof(argc1);
    getchar();
    arradd(5); 
    getchar();
    runprint_month(argc1);
    getchar();
    runmartx(argc1);
    getchar();

    cout<<"end main.....\n";
    return 0;
}

