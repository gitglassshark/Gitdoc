#include<iostream>
#include "fun.hpp"
#include "number.hpp"

using namespace std;
int len = 0;
char cbinary[sizeof (int) * 8];


int print_size (int i)
{
	cout << "the number " << i << " binary mode number is :";
	while (i > 2)
	{
		x = i % 2;
		cout << x;
		i = i / 2;
	}
	cout << i << endl;
	cout << endl;
	return 0;
}
