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

int printnameandvalue (const char *vname, const bool bi)
{
    char *value=0;
    char *ctrue="True";
    char *cfalse="False";
    if (bi == true)
    {
        value=ctrue;
    }
    else
    {
        value=cfalse;
    };
    cout <<'\t'<<vname<<"\t\t\t\t\t"<<value<<endl;
    return 0;
}


int printtb (const char *cmessage[], int n, const char *ptitle)
{
    cout << ptitle;
    print_nchar ('=', 70);
    print_nchar ('=', 70);
    for (int i = 0; i < n; i++)
    {
        cout <<'\t'<<cmessage[i]<<"\t\t\t";
    }
    cout<<endl;
    print_nchar ('=', 70);
    return 0;
}


int run_booltest(int argc,char * argv[])
{
    bool a = true;
    bool b = false;
    bool c = true;
    bool d = false;
    int nbarlen=70;
    const char *Aname = "A(= true)";
    const char *Bname = "B(=false)";
    const char *Cname = "C(= true)";
    const char *Dname = "D(=false)";
    const int n = 2;
    const char *ptitle =
        "The program run and print bool operator operation :\n";
    const char *cmessage[n] = {
        "Varible name",
        "Value"
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
        "Operation Result"
    };
    //input your program:
    printtb (rmessage, n, rtitle);
    print_nchar ('=', nbarlen);

    printnameandvalue ("A+B", a + b);
    printnameandvalue ("A+C", a + c);
    printnameandvalue ("B+D", b + d);
    print_nchar ('=', nbarlen);


    printnameandvalue ("A and B", a and b);
    printnameandvalue ("A and C", a and c);
    printnameandvalue ("B and D", b and d);
    print_nchar ('=', nbarlen);


    printnameandvalue ("A or B", a or b);
    printnameandvalue ("A or C", a or c);
    printnameandvalue ("B or D", b or d);
    print_nchar ('=', nbarlen);


    printnameandvalue ("not  A", not a);
    printnameandvalue ("not  B", not b);
    print_nchar ('=', nbarlen);
    printnameandvalue ("A xor B", a xor b);
    printnameandvalue ("A xor C", a xor c);
    printnameandvalue ("d xor b", d xor b);
    print_nchar ('=', nbarlen);

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
    while (x < 12 && x <argc1)
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


int runpickinital (int icp, int ic, int il)
{
    init_martix (martix, icp);
    pickupbig (martix, icp);
    return 0;
}

int init_martix (int i[h][v], int argc1)
{
    print_char ('=', 8 * v);
        srand (time (NULL) * argc1);
    for (int c = 0; c < h; c++)
    {
        for (int l = 0; l < v; l++)
        {
            i[c][l] = rand ();
            i[c][l] = ((i[c][l] % 10000) + (i[c][l] / 10000)) / 1000;
            cout << i[c][l] << "\t|";
        }
        cout << endl;
        print_char ('=', 8 * v);
    }
    cout << endl;
    return 0;
}

bool pickupbig (int i[h][v], int argc3)
{
    int ibig = 0, ismall = 0, iequal = 0;

    cout << "Pick up the numbers to compare :" <<  argc3<< endl;
    print_char ('=', 8 * v);
    for (int c = 0; c < h; c++)
    {
        for (int l = 0; l < v; l++)
        {
            if (i[c][l] < argc3)
            {
                ismall++;
                cout << i[c][l] << "-\t|";
            }
            else
            {
                if (i[c][l] == argc3)
                {
                    iequal++;
                    cout << i[c][l] << "=\t|";
                }
                else
                {
                    ibig++;
                    cout << i[c][l] << "+\t|";
                }
            }
        }
        cout << endl;
        print_char ('=', 8 * v);
    }
    cout << "The  than "<< argc3<<" more big numbers number is :\t" << ibig << endl;
    cout << "The  than "<< argc3<<" more small numbers number is :\t" << ismall << endl;
    cout << "The  than "<< argc3<<" more equal numbers number is :\t" << iequal << endl;
    cout << "The total numbers number is :\t" << iequal + ismall +
        ibig << endl;
    cout << "The total numbers array element's number is :\t" << h *
        v << endl;
    return true;
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
