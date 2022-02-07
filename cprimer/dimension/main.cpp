#include <iostream>
#include <vector>
#include <string>
#include "fun.hpp"
#include "number.hpp"

using namespace std;

int main (int argc, char *argv[])
{
	//input your program:
	if (argc >= 2)
	{
		x = atoi (argv[1]);
	}
	else
	{
		cout << "Lost input number...exit." << endl;
		return 0;
	}
	inital (x);

	return 0;
}
