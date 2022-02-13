#include <iostream>
using namespace std;


int RunListMenu(const int nMenuItemsT,const char * pCMenuListT[] )
{
    int iMenuCountS=0;
    while(nMenuItemsT>=0){
        cout<<++iMenuCountS<<".\t";
        cout<<pCMenuListT[iMenuCountS]<<endl;
    } 
    return 0;
}

