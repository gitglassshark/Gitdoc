#include <iostream>
#include "readme.hpp"
#include <vector>
#include <string>
#include "h.hpp"
#include "test.hpp"
#include "menu.hpp"
#include "sizeof.hpp"


using namespace std;

int ReTurn(int argc, char *argv[]);
int RunTest(int argc, char *argv[]);
int RunMainL(int argc,int Argc1,int nArgc2,int nArgc3,char *argv[],int nMenuSign );

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
                    RunTest(argc,argv);
                    return 0;
                }
            //input your program:
            if (argc >= 4)
                {
                    RunMainShell(argc,argv);
                }
        }
    return 0;
}

int RunMainShell(int argc,char *argv[])
{
    int nArgc1;
    int nArgc2;
    int nArgc3;
    if(argc>4)
        {
            nArgc1 = atoi (argv[1]);
            nArgc2 = atoi (argv[2]);
            nArgc3 = atoi (argv[3]);
        }
    int nMenuSign=0;
    RunMainL(argc,nArgc1,nArgc2,nArgc3,argv,nMenuSign);
    return 0;
}

int RunMainL(int argc,int nArgc1,int nArgc2,int nArgc3,char *argv[],int nMenuSign )
{
    vector<string>Menu;
    vector<PFp>Command;
    string strMenuTitle="Please choice a Menu command No to run a command,choice 0 = exit...";
    Menu.push_back(strMenuTitle);
    Command.push_back(nullptr);
    string strMenuName="Run Print Bool Table";

    Menu.push_back(strMenuName);
    Command.push_back(Run_BoolTestFN);

    strMenuName="Run Print Martix and Pick Number Table";
    Menu.push_back(strMenuName);
    Command.push_back(RunPickInitalFN);

    strMenuName="Run Print Array and Element Size Count Table";
    Menu.push_back(strMenuName);
    Command.push_back(RunTestArraySizeofFN);

    strMenuName="Run Array Add Table";
    Menu.push_back(strMenuName);
    Command.push_back(RunArrAddFN);

    strMenuName="Run and Prinit Month's Day Table";
    Menu.push_back(strMenuName);
    Command.push_back(RunPrint_MonthFN);

    strMenuName="Run and Prinit Arrary Random and Size Table";
    Menu.push_back(strMenuName);
    Command.push_back(RunOneSFx);

    strMenuName="Run List Sub Program Moudle";
    Menu.push_back(strMenuName);
    Command.push_back(RunListLTx);
    RunMenuMU(argc, argv,Menu,Command);

    return 0;
}

int RunTest(int argc, char *argv[])
{
    //    cout<<"Enter Test Moudle ......\n";
    RunMyTestFN(argc,argv);
    return 0;
}


