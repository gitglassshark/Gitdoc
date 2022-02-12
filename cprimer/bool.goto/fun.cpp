#include<iostream>
#include "h.hpp"
//#include "fun.hpp"
#include "printmessage.hpp"

using namespace std;


int printnameandvalue (const char *pname, const bool bi)
{
	if (bi == true)
	{
		cout << pname << "\t\t\t\t";
		cout << "true\n";
	}
	else
	{
		cout << pname << "\t\t\t\t";
		cout << "false\n";
	}
	return 0;
}


int printtb (const char *cmessage[], int n, const char *ptitle)
{
	cout << ptitle;
	print_nchar ('=', 60);
	for (int i = 0; i < n; i++)
	{
		cout << cmessage[i];
		cout << "\t\t";
	}
	cout << "\n";
	return 0;
}


int runantestbool ()
{
	bool a = true;
	bool b = false;
	bool c = true;
	bool d = false;
	const char *Aname = "A";
	const char *Bname = "B";
	const char *Cname = "C";
	const char *Dname = "D";
	const int n = 2;
	const char *ptitle =
		"The program run and print bool operator operation :\n";
	const char *cmessage[n] = {
		"bool varible name",
		"bool value "
	};
	//input your program:
	printtb (cmessage, n, ptitle);

	printnameandvalue (Aname, a);
	printnameandvalue (Bname, b);
	printnameandvalue (Cname, c);
	printnameandvalue (Dname, d);
	cout << endl;

	const char *rtitle = "The bool  operation and operation result:\n";

	const char *rmessage[n] = {
		"Operation",
		"Bool value operation result"
	};
	//input your program:
	printtb (rmessage, n, rtitle);
	print_nchar ('=', 60);

	printnameandvalue ("A+B", a + b);
	printnameandvalue ("A+C", a + c);
	printnameandvalue ("B+D", b + d);
	print_nchar ('=', 60);


	printnameandvalue ("A and B", a and b);
	printnameandvalue ("A and C", a and c);
	printnameandvalue ("B and D", b and d);
	print_nchar ('=', 60);


	printnameandvalue ("A or B", a or b);
	printnameandvalue ("A or C", a or c);
	printnameandvalue ("B or D", b or d);
	print_nchar ('=', 60);


	printnameandvalue ("not  A", not a);
	printnameandvalue ("not  B", not b);
	print_nchar ('=', 60);
	printnameandvalue ("A xor B", a xor b);
	printnameandvalue ("A xor C", a xor c);
	printnameandvalue ("d xor b", d xor b);
	print_nchar ('=', 60);

	cout << "end runantestbool......\n";
	return 0;
}


int togoto(int i)
{
    int n=0;
start:
    cout << "start in togoto......\n";
    if (n < i)
    {
        cout<<n<<endl;
        n++;
        goto start;
    }
    else
    {
        cout << "under the exit......";
        goto neverget;
    }
    cout << "end togoto......\n";
neverget:
    cout << "neverget ......\n";
    return 0;
}

int    testarraysizeof(int a, int b, int c)
{
    //     int [][][]={0, }

    int arraya[x][y][z]={0,[x-1][y-1][z-1]=0};
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
