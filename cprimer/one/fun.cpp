#include<iostream>
#include<time.h>
#include<cstring>
#include "h.hpp"
#include "printmessage.hpp"

using namespace std;

int ToGotoL(int argc1);
int Init_MartixL (int i[h][v], int argc1);
bool PickUpBigL (int i[h][v], int argc3);
int InitalArrayL(int arrayb[x][y][z], int argc1);
int InitalArrayL(int arrayb[x][y][z], int argc1);


int PrintNameAndValueL (const char *vname, const bool bi)
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


int PrintTBL (const char *cmessage[], int n, const char *ptitle)
{
    cout << ptitle;
    Print_NCharx ('=', 70);
    Print_NCharx ('=', 70);
    for (int i = 0; i < n; i++)
    {
        cout <<'\t'<<cmessage[i]<<"\t\t\t";
    }
    cout<<endl;
    Print_NCharx ('=', 70);
    return 0;
}


int Run_BoolTestFN(int argc,char * argv[])
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
        "本程序模块运行逻辑运算并打印运行结果...\n";
    const char *cmessage[n] =
    {
        "变量名",
        "变量值"
    };
    //input your program:
    PrintTBL (cmessage, n, ptitle);

    PrintNameAndValueL (Aname, a);
    PrintNameAndValueL (Bname, b);
    PrintNameAndValueL (Cname, c);
    PrintNameAndValueL (Dname, d);
    cout << endl;

    const char *rtitle = "逻辑运算及运算结果.....\n";

    const char *rmessage[n] =
    {
        "运算模式",
        "运算模式结果"
    };
    //input your program:
    PrintTBL (rmessage, n, rtitle);
    Print_NCharx ('=', nbarlen);

    PrintNameAndValueL ("A+B(和)", a + b);
    PrintNameAndValueL ("A+C(和)", a + c);
    PrintNameAndValueL ("B+D(和)", b + d);
    Print_NCharx ('=', nbarlen);


    PrintNameAndValueL ("A and B(并)", a and b);
    PrintNameAndValueL ("A and C(并)", a and c);
    PrintNameAndValueL ("B and D(并)", b and d);
    Print_NCharx ('=', nbarlen);


    PrintNameAndValueL ("A or B(或)", a or b);
    PrintNameAndValueL ("A or C(或)", a or c);
    PrintNameAndValueL ("B or D(或)", b or d);
    Print_NCharx ('=', nbarlen);


    PrintNameAndValueL ("not  A(取反)", not a);
    PrintNameAndValueL ("not  B(取反)", not b);
    Print_NCharx ('=', nbarlen);
    PrintNameAndValueL ("A xor B(异或)", a xor b);
    PrintNameAndValueL ("A xor C(异或)", a xor c);
    PrintNameAndValueL ("d xor b(异或)", d xor b);
    Print_NCharx ('=', nbarlen);

    return 0;
}


int RunToGotoFN(int argc1)
{
    int n=0;
    cout << "开始跳转模块......\n";
start:
    if (n <  argc1)
    {
        cout<<n<<'\t';
        n++;
        goto start;
    }
    else
    {
        cout << "\n超过循环次数，退出....\n";
        goto get;
    }
neverget:
    cout << "跳转从来不会到达的地方......\n";
get:
    cout << "模块结束......\n";
    return 0;
}

int RunTestArraySizeofFN(int argc1)
{
    //     int [][][]={0, }

    int arraya[x][y][z]= {0,[x-1][y-1][z-1]=0};
    cout<<"数组尺寸大小是： "<<sizeof(arraya)<<endl;
    InitalArrayL(arraya, argc1);
    cout<<"测试对象尺寸模块结束.....\n";
    return 0;
}

int InitalArrayL(int arrayb[x][y][z], int argc1)
{
    int a=0;
    int b=0;
    int c=0;
    cout<<"数组尺寸大小是:  "<<sizeof(arrayb)<<endl;
    for(a=0; a<x; a++)
    {
        for(b=0; b<y; b++)
        {
            for(c=0; c<z; c++)
            {
                cout<<arrayb[a][b][c]<<"|*";
                arrayb[a][b][c]=argc1;
                cout<<arrayb[a][b][c]<<"|+\t";
            }
            cout<<"||**\n"<<endl;
        }
        cout<<"|||***\n\n"<<endl;
    }
    cout<<"数组尺寸大小是：  "<<sizeof(arrayb)<<endl;
    cout<<"数组尺寸大小是：  "<<sizeof(arrayb[x][y][z])<<endl;
    cout<<"数组总计元素空间大小是： "<<x*y*z<<endl;
    cout<<"数组元素单元大小size是：（整型）"<<sizeof(int)<<endl;
    return 0;
};


int RunArrAddFN(int i)
{
    int  carr[9]=
    {
        9,8,7,6,5,4,3,2,1
    };
    cout<<*carr+2<<endl;
    cout<<*(carr+2)<<endl;
    return 0;
}

const int months = 12;
int martix[h][v];

int MartxL(int argc1)
{
    Init_MartixL (martix, argc1);
    return 0;
}


int days[months] =
{
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

const char *names[months] =
{
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

int RunPrint_MonthFN (int argc1)
{
    int	x = 0;
    int	y = 0;
    int	z = 0;

    char *title = "一年中各月的天数是：";

    cout << title << endl;
    Print_NCharx ('=', strlen (title));
    cout << endl;
    while (x < 12 && x <argc1)
    {
        cout << x + 1 << ".\t" << names[x];
        y = strlen (names[x]);
        for (z = 0; z < strlen (title) - y - 20; z++)
            cout << " ";
        cout << "天数是：" << days[x] << endl;
        x++;
    }
    return 0;
}


int RunPickInitalFN (int icp, int ic, int il)
{
    Init_MartixL (martix, icp);
    PickUpBigL (martix, icp);
    return 0;
}

int Init_MartixL (int i[h][v], int argc1)
{
    Print_NCharx ('=', 8 * v);
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
        Print_NCharx ('=', 8 * v);
    }
    cout << endl;
    return 0;
}

bool PickUpBigL (int i[h][v], int argc3)
{
    int ibig = 0, ismall = 0, iequal = 0;

    cout << "挑选数字去和矩阵中的值去比较筛选" <<  argc3<< endl;
    Print_NCharx ('=', 8 * v);
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
        Print_NCharx ('=', 8 * v);
    }
    cout << "比"<< argc3<<"更大的数字个数是：\t" << ibig << endl;
    cout << "比"<< argc3<<"更小的数字个数是：\t" << ismall << endl;
    cout << "比"<< argc3<<"相等的数字个数是：\t" << iequal << endl;
    cout << "合计:\t" << iequal + ismall + ibig << endl;
    cout << "数组大小为：\t" << h * v << endl;
    return true;
}

