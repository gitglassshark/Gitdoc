#include <iostream>
#include <stdio.h>
using namespace std;


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
