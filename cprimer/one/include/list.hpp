#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list;
struct list
{
    struct list *pn;
    int nData;
    void *pdata;
};

int RunListLTx (int argc,char * argv[]);
