#include <iostream>
#include <vector>
#include <string>
#include "fun.hpp"

using namespace std;

int main()
{
    int t=0;
    int x=100;
    //int x_unuse=99;
    string start_msg ="Start! ......\n";
    string end_msg="End! ......\n";
    t=sizeof(start_msg);
    cout << start_msg;
    cout << null(t)<<endl;
    cout << null(x)<<endl;
    cout << end_msg;
    return 0;
}
