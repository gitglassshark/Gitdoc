#include<iostream>
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
	while (x < 12 && x < i)
	{
		cout << names[x] << "  days is " << days[x] << endl;
		x++;
	}
	return 0;
}
