#include <iostream>
#include "readme.hpp"
#include <vector>
#include <string>
#include "h.hpp"
#include "test.hpp"
#include "sizeof.hpp"

using namespace std;

int RunMainL(int nArgc1,int nArgc2,int nArgc3,char *argv[],int nMenuSign );

int main (int argc, char *argv[])
{
    //input your program:
    int nArgc1;
    int nArgc2;
    int nArgc3;
    if (argc== 1)
        {
            cout << "缺少参数...." << endl;
            RunReadmeRE (argc, argv);
            return 0;
        }
    else
        {
            nArgc1 = atoi (argv[1]);
            if(nArgc1==0)
                {
                    // begin run and test
                    RunMyTestFN(argc,argv);
                    return 0;
                }
            //input your program:
            if (argc >= 4)
                {
                    nArgc2 = atoi (argv[2]);
                    nArgc3 = atoi (argv[3]);
                    int nMenuSign=0;
                    RunMainL(nArgc1,nArgc2,nArgc3,argv,nMenuSign);
                }
        }
    return 0;
}


int RunMainL(int nArgc1,int nArgc2,int nArgc3,char *argv[],int nMenuSign )
{
    //
    RunPickInitalFN (nArgc1,nArgc2,nArgc3);
    getchar();
    Run_BoolTestFN(nArgc1, argv);
    getchar();
    RunTestArraySizeofFN(nArgc1);
    getchar();
    RunArrAddFN(5);
    getchar();
    RunPrint_MonthFN(nArgc1 );
    getchar();
    RunOneSFx();
    getchar();
    RunListLTx(nArgc1,argv);
    getchar();
    return 0;
}



