#include <iostream>

using namespace std;

int PrintS (char const *const cmessage)
{
    cout << cmessage;
    return 0;
}

int PrintSL (char const *const cmessage)
{
    cout << cmessage << endl;
    return 0;
}

int PrintST (char const *const cmessage)
{
    cout << cmessage << "\t";
    return 0;
}

int Print_NChar (char c, int inum)
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
