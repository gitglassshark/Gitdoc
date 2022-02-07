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

int readme (int argc, char *argv[]);
int readme (int argc, char *argv[])
{
	cout << "Compare random number's arrary 0.10\n";
	cout <<
		"Copyleft (C) 2022 Free Software gitglassshark@Nothing, INC:bbc@sina.com.\n";
	cout <<
		"This is free software;see the source for copying conditions.\nThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";
	cout << "Usage:\n\t cparray  [colmun]  [cow]  [compare number]\n";
	cout <<
		"\n\t -[colmun]\t\t The arrary line.\n\t -[cow]\t\t\t The arrary cow.\n\t -[compare number]\t The compare number.\n";
	return 0;
}
