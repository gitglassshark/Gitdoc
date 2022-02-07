#include<iostream>
#include "h.hpp"
//#include "fun.hpp"
//#include "number.hpp"

using namespace std;

const int print_size (const bool *const imessage)
{
	if (*imessage == true)
		cout << "in print_size......" << endl;
	bool btest_a = false;
	bool btest_b = true;
	bool btest_c = false;

	btest_c = btest_a + btest_a;
	cout << "btest_c is \t" << btest_c << "\tsize of is \t" <<
		sizeof (btest_c) << endl;

	btest_c = btest_b + btest_b;
	cout << "btest_c is \t" << btest_c << "\tsize of is \t" <<
		sizeof (btest_c) << endl;

	btest_c = btest_b + btest_a;
	cout << "btest_c is \t" << btest_c << "\tsize of is \t" <<
		sizeof (btest_c) << endl;

	cout << "true+true is......" << sizeof ((bool) (true + true)) << endl;
	cout << "true+false is......" << true + false << endl;
	cout << "false + false is......" << false + false << endl;
	cout << "end print_size......" << endl;
	return 0;
}
