#include<iostream>
#include<time.h>
#include<cstring>
#include "h.hpp"
#include "printmessage.hpp"

using namespace std;


int runmytest(int argc, char *argv[])
{
    return 0;
}
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


int runtestbool ()
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

    return 0;
}


int togoto(int argc1)
{
    int n=0;
    cout << "start in togoto......\n";
start:
    if (n <  argc1)
    {
        cout<<n<<'\t';
        n++;
        goto start;
    }
    else
    {
        cout << "\noverflow and exit....\n";
        goto get;
    }
neverget:
    cout << "neverget to be jump to......\n";
get:
    cout << "get in end......\n";
    return 0;
}

int    testarraysizeof(int argc1)
{
    //     int [][][]={0, }

    int arraya[x][y][z]={0,[x-1][y-1][z-1]=0};
    cout<<"array size of is "<<sizeof(arraya)<<endl;
    initalarray(arraya, argc1);
    cout<<"end testarraysizeof.....\n";
    return 0;
}

int initalarray(int arrayb[x][y][z], int argc1)
{
    int a=0; int b=0; int c=0;
    cout<<"array size of is "<<sizeof(arrayb)<<endl;
    for(a=0;a<x;a++){
        for(b=0;b<y;b++){
            for(c=0;c<z;c++){
                cout<<arrayb[a][b][c]<<"|*";
                arrayb[a][b][c]=argc1;
                cout<<arrayb[a][b][c]<<"|+\t";
            }
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


int arradd(int i)
{
    int  carr[9]={
        9,8,7,6,5,4,3,2,1
    };
    cout<<*carr+2<<endl;
    cout<<*(carr+2)<<endl;
    return 0;
}

const int months = 12;
int martix[h][v];

int runmartx(int argc1)
{
    init_martix (martix, argc1);
    return 0;
}

int init_martix (int i[h][v], int argc1)
{
    print_char ('=', 8 * h);
    srand (time (NULL) * argc1);
    for (int c = 0; c < h; c++)
    {
        for (int l = 0; l < v; l++)
        {
            i[c][v] = rand ();
            cout << ((i[c][v] % 10000) +
                     (i[c][v] / 10000)) / 1000 << "\t|";
        }
        cout << endl;
        print_char ('=', 8 * h);
    }
    return 0;
}

int days[months] = {
    31,							//1
    28,							//2
    31,							//3
    30,							//4
    31,							//5
    30,							//6
    31,							//7
    31,							//8
    30,							//9
    31,							//10
    30,							//11
    31							//12
};

const char *names[months] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int runprint_month (int argc1)
{
    int	x = 0;
    int	y = 0;
    int	z = 0;
    char *title = "The numbers of day in month of year is :";

    cout << title << endl;
    print_char ('=', strlen (title));
    cout << endl;
    while (x < 12 && x < argc1)
    {
        cout << x + 1 << ".\t" << names[x];
        y = strlen (names[x]);
        for (z = 0; z < strlen (title) - y - 20; z++)
            cout << " ";
        cout << "days is " << days[x] << endl;
        x++;
    }
    return 0;
}

int print_char (char c, int inum)
{
    if (inum > 0)
    {
        for (int i = 0; i < inum; i++)
            cout << c;
        cout << endl;
        return inum;
    }
    else
    {
        return 0;
    }
}
