#include <iostream>
#include <vector>
#include <string>
#include "h.hpp"
//#include "fun.hpp"
#include "printmessage.hpp"

using namespace std;

const int x=10;
const int y=10;
const int z=10;
int initalarray(int array[x][y][z], int i);

int    testarraysizeof(int i, int x, int y);

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
    cout<<"end main.....\n";
    return 0;
}

int    testarraysizeof(int a, int b, int c)
{
    //     int [][][]={0, }

    int arraya[x][y][z]={0,[9][9][9]=0};
    cout<<"array size of is "<<sizeof(arraya)<<endl;
    initalarray(arraya, a);
    cout<<"end testarraysizeof.....\n";
    return 0;
}

int initalarray(int arrayb[x][y][z], int i)
{
    int a=0; int b=0; int c=0;
    cout<<"array size of is "<<sizeof(arrayb)<<endl;
    for(a=0;a<x;a++){
        for(b=0;b<y;b++){
            for(c=0;c<z;c++)
                cout<<arrayb[a][b][c]<<"|*\t";
            cout<<"||**\n"<<endl;
        }
        cout<<"|||***\n\n"<<endl;
    }   
    cout<<"array size of is "<<sizeof(arrayb)<<endl;
    cout<<"array size of is "<<sizeof(arrayb[x][y][z])<<endl;
    cout<<"array number elements numbe of is "<<x*y*z<<endl;
    cout<<"array element size of is "<<sizeof(int)<<endl;
    return 0;
};
