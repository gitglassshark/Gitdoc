#include <iostream>
#include <vector>
#include <string>
#include "fun.hpp"
#include "number.hpp"
#include "readme.hpp"

using namespace std;
int readme (int argc, char *argv[]);

int main (int argc, char *argv[])
{
	//input your program:
	if (argc >= 4)
	{
	int ic = atoi (argv[1]);
		int il = atoi (argv[2]);
        int icp = atoi (argv[3]);

		inital (icp, ic, il);
	}
	else
	{
		readme (argc, argv);
		cout << "Lost input number...exit." << endl;
		return 0;
	}

	return 0;
}
