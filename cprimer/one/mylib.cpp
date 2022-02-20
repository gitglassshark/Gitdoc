#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int newline()
{
    cout<<endl;
    return 0;
}

int blankline()
{
    cout<<endl<<endl;
    return 0;
}

int star(const char c,const int n)
{
    string strStarLine=string(n,c);
    cout<<strStarLine<<endl;
    return 0;
}

int star(const int c,const int n)
{
    string strStarLine=string(n,'*');
    cout<<c<<'\t'<<strStarLine<<endl;
    return 0;
}

int star(const char * const p)
{
    string strStarLine=string(80-strlen(p)-1,'*');
    cout<<p<<':'<<strStarLine<<endl;
    return 0;
}

int star(const char c)
{
    string strStarLine=string(78,'*');
    cout<<c<<':'<<strStarLine<<endl;
    return 0;
}

int starn()
{
    static int n=0;
    n++;
    string strStarLine=string(78,'*');
    cout<<n<<':'<<strStarLine<<endl;
    return 0;
}

int star(const int &n=0)
{
    string strStarLine;
    if(n==0)
        {
            strStarLine=string(80,'*');
            cout<<strStarLine<<endl;
        }
    else
        {
            strStarLine=string(78,'*');
            cout<<n<<':'<<strStarLine<<endl;
        }
    return 0;
}
int PrintSx (char const *const cmessage)
{
    cout << cmessage;
    return 0;
}

int PrintSLx (char const *const cmessage)
{
    cout << cmessage << endl;
    return 0;
}

int PrintSTx (char const *const cmessage)
{
    cout << cmessage << "\t";
    return 0;
}

int    PrintClassSize()
{
    cout<<"size is start......\n";
    printf ("char型数据尺寸大小是：%ld\n", sizeof (char));
    printf ("int型数据尺寸大小是： %ld\n", sizeof (int));
    printf ("long型数据尺寸大小是：%ld\n", sizeof (long));
    printf ("long long型数据尺寸大小是：%ld\n", sizeof (long long));
    printf ("float型数据尺寸大小是：%ld\n", sizeof (float));
    return 0;
}

int Print_NCharx (char c, int inum)
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

int FCopyFileDelteNCharFN(char *pcFormFile,char *pcDestFile,char cCharIsNDelete)
{
    //编写一个程序，将输入文件复制到输出文件，在复制过程中，要求将输入
    //文件中的多个连续空格转化为一个空格并复制到输出文件中，其它字符不
    //变，原样复制。。
    FILE *fIn,*fOut;
    fIn=fopen(pcFormFile,"r");
    fOut=fopen(pcDestFile,"w+");
    if((!fIn)||(!fOut))
        {
            cout<<"File error!exit......\n";
            exit(0);
        }
    int c;
    cCharIsNDelete=' ';
    long long iS=0;
    while((c=fgetc(fIn))!=EOF)
        {
            if(c==cCharIsNDelete)
                {
                    if(!iS++)
                        fputc(c,fOut);
                }
            else
                {
                    fputc(c,fOut);
                    iS=0;
                }

        }
    fclose(fIn);
    fclose(fOut);
    return 0;
}


int starline(int nStartLen=60)
{
    string strStarLine;
    strStarLine="****************************"
                "**************************\n";
    if(nStartLen==60)
        {
            cout<<strStarLine;
        }
    else
        {
            string strStarn(nStartLen,'*');
            cout<<strStarn<<endl;
        }
    return 0;
}
