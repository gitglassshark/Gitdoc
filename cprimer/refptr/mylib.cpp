#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

extern char t = '\t';
extern char e = '\n';
const int linelen = 80;

int newline ()
{
    cout << endl;
    return 0;
}

int blankline ()
{
    cout << endl << endl;
    return 0;
}

int star (const char *p, const char c)
{
    string strStarLine = string (linelen - strlen (p) - 1, c);

    cout << p << ':' << strStarLine << endl;
    return 0;
}

int star (const char c, const char *p)
{
    string strStarLine = string (linelen - strlen (p) - 1, c);

    cout << p << ':' << strStarLine << endl;
    return 0;
}

int star (const char c, const int n)
{
    string strStarLine = string (n, c);

    cout << strStarLine << endl;
    return 0;
}

int star (const int c, const int n)
{
    string strStarLine = string (n, c);

    cout << strStarLine << endl;
    return 0;
}

int star (const char *const p)
{
    string strStarLine = string (linelen - strlen (p) - 1, '*');

    cout << p << ':' << strStarLine << endl;
    return 0;
}

int star (const char c)
{
    string strStarLine = string (linelen, c);

    cout << strStarLine << endl;
    return 0;
}

int starn ()
{
    static int n = 0;

    n++;
    string strStarLine = string (linelen - 2, '*');

    cout << n << ':' << strStarLine << endl;
    return 0;
}

int star (const int &n = 0)
{
    string strStarLine;

    if (n == 0) {
        strStarLine = string (linelen, '*');
        cout << strStarLine << endl;
    } else {
        strStarLine = string (linelen - 2, '*');
        cout << n << ':' << strStarLine << endl;
    }
    return 0;
}

int starline (int nStartLen = 60)
{
    string strStarLine;

    strStarLine = "****************************"
                  "**************************\n";
    if (nStartLen == 60) {
        cout << strStarLine;
    } else {
        string strStarn (nStartLen, '*');

        cout << strStarn << endl;
    }
    return 0;
}
