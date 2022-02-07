#include<iostream>
#include "h.hpp"
//#include "fun.hpp"
//#include "number.hpp"

using namespace std;

const int print_size (const bool *const imessage)
{
	if (*imessage == true)
		cout << "in print_size......" << endl;
	printsl ("print line");
	prints ("print s");
	printst ("print t");

	cout << "end print_size......" << endl;
	return 0;
}
