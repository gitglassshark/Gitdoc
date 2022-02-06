#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include "fun.hpp"
#include "number.hpp"

using namespace std;

int main ()
{
	//input your program:
	int x = 100;

	print_size (x);

	cout << "二进制： " << bitset < sizeof (x) * 8 > (x) << endl;

	return 0;
}
