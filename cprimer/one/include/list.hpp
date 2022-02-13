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

int InitList (struct list *pListT, int nDataSizeT, int initdata);
int PrintList (struct list *pListT, int ncol);
int TotalList (struct list *pListT, int nDataSizeT);
int PrintListP (struct list *pListT, int nDataSizeT, int ncol);
int RandMakeList (struct list *pListT, int nDataSizeT, int nMod, int nListdata);
int PutListnData (struct list *pListT, int nDataLocate, int nData);
int GetListNData (struct list *pListT, int nDataLocate);
int GetListSize (struct list *pListT);
int GetData (struct list *pListT, int *nLoc);
int ReSizeList (struct list **pPList, int nNewSize);
int GetNewSize (struct list *pOldList);
char MakeMenu ();
int RunListLT (int argc,char * argv[]);
