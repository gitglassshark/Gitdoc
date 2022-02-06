#include<iostream>
#include "fun.hpp"
#include "number.hpp"

using namespace std;

int empty (int imin, int imax)
{
	//input you program:
	int isave = 0;

	isave = imin;
	cout << imin;
	while (imin < imax || imax < imin)
	{
		if (imin < imax)
		{
			imin++;
			isave = isave * imin;
		}
		else
		{
			imin--;
			isave = isave * imin;
		}
		cout << "*" << imin;
	}
	cout << "=";
	return isave;
}
