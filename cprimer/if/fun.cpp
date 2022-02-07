#include<iostream>
#include<time.h>
#include<cstring>
#include "fun.hpp"
#include "number.hpp"

using namespace std;

const int months = 12;
int martix[h][v];

int inital (int i)
{
	init_martix (martix, i);
	pickupbig (martix, i);
	return 0;
}

int init_martix (int i[h][v], int inum)
{
	print_char ('=', 8 * v);
	srand (time (NULL) * inum);
	for (int c = 0; c < h; c++)
	{
		for (int l = 0; l < v; l++)
		{
			i[c][l] = rand ();
			i[c][l] = ((i[c][l] % 10000) + (i[c][l] / 10000)) / 1000;
			cout << i[c][l] << "\t|";
		}
		cout << endl;
		print_char ('=', 8 * v);
	}
	cout << endl;
	return 0;
}

bool pickupbig (int i[h][v], int ipicknum)
{
	int ibig = 0, ismall = 0, iequal = 0;

	cout << "Pick up the numbers to compare :" << ipicknum << endl;
	print_char ('=', 8 * v);
	for (int c = 0; c < h; c++)
	{
		for (int l = 0; l < v; l++)
		{
			if (i[c][l] < ipicknum)
			{
				ismall++;
				cout << i[c][l] << "-\t|";
			}
			else
			{
				if (i[c][l] == ipicknum)
				{
					iequal++;
					cout << i[c][l] << "=\t|";
				}
				else
				{
					ibig++;
					cout << i[c][l] << "+\t|";
				}
			}
		}
		cout << endl;
		print_char ('=', 8 * v);
	}
	cout << "The more big numbers number is :\t" << ibig << endl;
	cout << "The more small numbers number is :\t" << ismall << endl;
	cout << "The more equal numbers number is :\t" << iequal << endl;
	cout << "The total numbers number is :\t" << iequal + ismall +
		ibig << endl;
	cout << "The total numbers array element's number is :\t" << h *
		v << endl;
	return true;
}

int days[months] = {
	31,							//1
	28,							//2
	31,							//3
	30,							//4
	31,							//5
	30,							//6
	31,							//7
	31,							//8
	30,							//9
	31,							//10
	30,							//11
	31							//12
};

const char *names[months] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

int print_month (int i)
{
	x = 0;
	char *title = "The numbers of day in month of year is :";

	cout << title << endl;
	print_char ('=', strlen (title));
	cout << endl;
	while (x < 12 && x < i)
	{
		cout << x + 1 << ".\t" << names[x];
		y = strlen (names[x]);
		for (z = 0; z < strlen (title) - y - 20; z++)
			cout << " ";
		cout << "days is " << days[x] << endl;
		x++;
	}
	return 0;
}

int print_char (char c, int inum)
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
