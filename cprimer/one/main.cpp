#include <iostream>
#include "readme.hpp"
#include <vector>
#include <string>
#include "h.hpp"
#include "test.hpp"
#include "sizeof.hpp"

extern const int constintest;

using namespace std;

int ReTurn(int argc, char *argv[]);
int RunTest(int argc, char *argv[]);
int RunMainL(int Argc1,int nArgc2,int nArgc3,char *argv[],int nMenuSign );

int main (int argc, char *argv[])
{
    //input your program:
    enum enArgNumStatus {enStatusExit=1,enStatusTest=2,enStatusOK=4,enStatusTooMuch,enStatusEtc};
    enArgNumStatus enStatus=enStatusExit;
    switch(argc)
        {
        case enStatusTest:
            RunTest(argc,argv);
            break;
        case enStatusOK:
            ReTurn(argc, argv);
            break;
        case enStatusExit:
        default:
            RunReadmeRE (argc, argv);
            break;
        }
    return 0;
}

int ReTurn(int argc, char *argv[])
{
    int nArgc1;
    int nArgc2;
    int nArgc3;
    if (argc== 1)
        {
            RunReadmeRE (argc, argv);
            return 0;
        }
    else
        {
            nArgc1 = atoi (argv[1]);
            if(nArgc1==0)
                {
                    // begin run and test
                    RunTest(argc,argv);
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

int RunTest(int argc, char *argv[])
{
    cout<<"Enter Test Moudle ......\n";
    RunMyTestFN(argc,argv);
    return 0;
}


