#include <iostream>
#include "readme.hpp"
#include <vector>
#include <string>
#include "h.hpp"
#include "sizeof.hpp"
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
        if(argc1==0)
            readme(argc,argv);
    }


    //input your program:
    if (argc >= 4)
    {
        int ic = atoi (argv[1]);
        int il = atoi (argv[2]);
        int icp = atoi (argv[3]);
        runpickinital (icp, ic, il);
    }
    else
    {
        readme (argc, argv);
        cout << "Lost input number...exit." << endl;
    }

    // begin run and test
    //
    runmytest(argc, argv);
    getchar();
    run_booltest(argc, argv);
    togoto(argc1);
    getchar();
    getchar();
    testarraysizeof(argc1);
    getchar();
    arradd(5); 
    getchar();
    runprint_month(argc1);
    getchar();
    runone ();
    getchar();
    runlist(argc,argv);
    getchar();

    cout<<"end main.....\n";
    return 0;
}


