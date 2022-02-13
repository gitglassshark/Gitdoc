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
    cout << "主程序开始运行......\n";
    int argc1;
    if (argc >= 2)
    {
        argc1 = atoi (argv[1]);
        if(argc1==0)
            RunReadmeRE(argc,argv);
    }


    //input your program:
    if (argc >= 4)
    {
        int ic = atoi (argv[1]);
        int il = atoi (argv[2]);
        int icp = atoi (argv[3]);
        RunPickInitalFN (icp, ic, il);
    }
    else
    {
        cout << "缺少参数...exit." << endl;
        RunReadmeRE (argc, argv);
    }

    // begin run and test
    //
    RunMyTestFN(argc, argv);
    getchar();
    Run_BoolTestFN(argc, argv);
    (argc1);
    getchar();
    RunTestArraySizeofFN(argc1);
    getchar();
    RunArrAddFN(5);
    getchar();
    RunPrint_MonthFN(argc1);
    getchar();
    RunOneSF();
    getchar();
    RunListLT(argc,argv);
    getchar();

    cout<<"结束程序，退出.....\n";
    return 0;
}


