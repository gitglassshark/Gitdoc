#include <iostream>
#include <vector>
#include <string>
#include "fun.hpp"
#include "number.hpp"

using namespace std;
int readme (int argc, char *argv[]);

int main (int argc, char *argv[])
{
	//input your program:
	if (argc >= 2)
	{
		inital (atoi (argv[1]));
	}
	else
	{
		readme (argc, argv);
		cout << "Lost input number...exit." << endl;
		return 0;
	}

	return 0;
}

int readme (int argc, char *argv[]);
int readme (int argc, char *argv[])
{
	cout << "Compare random number's arrary 0.10\n";
	cout << "Copyright (C) 2022 Free Software Nothing, Inc.\n";
	cout <<
		"This is free software;\nsee the source for copying conditions.\nThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";
	return 0;
}
