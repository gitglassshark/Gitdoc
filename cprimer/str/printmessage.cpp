#include <iostream>

using namespace std;

int prints (char const *const cmessage)
{
	cout << cmessage;
	return 0;
}

int printsl (char const *const cmessage)
{
	cout << cmessage << endl;
	return 0;
}

int printst (char const *const cmessage)
{
	cout << cmessage << "\t";
	return 0;
}
