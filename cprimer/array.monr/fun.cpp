#include<iostream>
#include<cstring>
#include "fun.hpp"
#include "number.hpp"

using namespace std;
const int months = 12;

const int days[months] = {
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
		return inum;
	}
	else
	{
		return 0;
	}
}
