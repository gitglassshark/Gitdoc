#include <iostream>
#include <vector>
#include <string>
#include "h.hpp"
//#include "fun.hpp"
//#include "number.hpp"

using namespace std;

bool cbtrue = true;

int main ()
{
	//input your program:
	const bool *const bpass = &cbtrue;

	cout << "in main......\n";
	print_size (bpass);

	cout << "end main......\n";
	return 0;
}
