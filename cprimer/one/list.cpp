#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.hpp"
// 数组列表
//
#define SIZE 100
int nListSize = 30;
int nLineNumber = 3;
int ERR_CODE_1 = 1;
int nInitData = 0;

int RunListLTx (int argc,char * argv[]);

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


int RunListLTx (int argc,char * argv[])
{
    // git test modified text
    int nListSize = SIZE;
    struct list *pListOne = NULL;
    pListOne =(list *) malloc (sizeof (struct list) * nListSize);
    int nInitData = 8;
    InitList (pListOne, nListSize, nInitData);
    char cChoiceMenu=0;
//     char cGetforMenu=0;
    int nSingExit = 0;
    while (nSingExit == 0)
    {
        cChoiceMenu = MakeMenu ();
        if('\n'==cChoiceMenu)
            continue;
        switch (cChoiceMenu)
        {
        case '1':
            InitList (pListOne, nListSize, nInitData);
            break;
        case '2':
            RandMakeList (pListOne, nListSize, 200, nInitData);
            break;
        case '3':
            PutListnData (pListOne, 4, 7);
            break;
        case '4':
            PrintList (pListOne, nLineNumber);
            break;
        case '5':
            PrintListP (pListOne, nListSize, nLineNumber);
            break;
        case '6':
            printf ("List total is:%d\n", TotalList (pListOne, nListSize));
            break;
        case '7':
            {
                int gdata = 0;
                int locate = 0;
                gdata = GetData (pListOne, &locate);
                printf ("The locate %d data is %d\n", locate + 1, gdata);
            }
            break;
        case '8':
            {
                nListSize = GetNewSize (pListOne);
                ReSizeList (&pListOne, nListSize);
            }
            break;
        case '9':
            {
                printf ("List size is %d\n", GetListSize (pListOne));
            }
            break;
        case '0':
            nSingExit = 1;
            break;
        default:
            printf ("error cChoiceMenu can't be run.....\n");
        }
    }

    free (pListOne);
    pListOne = NULL;
    return 0;
}

char MakeMenu ()
{
    printf ("===== List fuction menu=====\n");
    printf ("(Right Author by yan:bbc@sina.com)\n");
    printf ("(版权作者：yan:bbc@sina.com)，在GPL下\n");
    printf ("请选择一个项目执行，选择数字\n");
    printf ("1.Reinital List\n");
    printf ("1.重新初始化数组\n");
    printf ("2.Use random data make List\n");
    printf ("2.使用随机数生成列表结构\n");
    printf ("3.Put data to List\n");
    printf ("3.放入数值至列表\n");
    printf ("4.Print List\n");
    printf ("4.打印列表值\n");
    printf ("5.Print List data memory Address\n");
    printf ("5.打印列表数据内存地址\n");
    printf ("6.Total List data\n");
    printf ("6.列表数据值累计值\n");
    printf ("7.Get List data\n");
    printf ("7.得到列表数据\n");
    printf ("8.Resize List\n");
    printf ("8.重新设置列表大小尺寸\n");
    printf ("9.Get List size\n");
    printf ("9.得到列表尺寸\n");
    printf ("0.Exit\n");
    printf ("0.退出\n");
    char i='\n';
    while('\n'==(i=getchar()));
    getchar();
    printf ("%c\n", i);
    return i;
};

int TotalList (struct list *p, int datasize)
{
    int total = 0;
    for (int i = 0; i < datasize; i++)
    {
        total += p[i].nData;
    }
    return total;
};

int InitList (struct list *p, int datasize, int nInitData)
{
    for (int i = 0; i < datasize; i++)
    {
        p[i].nData = nInitData;
        if (i == datasize - 1)
        {
            p[i].pn = NULL;
        }
        else
        {
            p[i].pn = &p[i + 1];
        }
    }
    printf ("初始化列表......\n");
    return 0;
};

int PrintListP (struct list *p, int datasize, int ncol)
{
    printf ("LIST STRUCT PIONTER :\n");
    for (int i = 0; i < datasize; i++)
    {
        printf ("No%d 结构内存地址%p,No%d->P 是 %p\t", i,
                (void *) &p[i], i, (void *) p[i].pn);
        if ((i + 1) % ncol == 0)
            printf ("\n");
    }
    printf ("\n");
    return 0;
};

int PrintList (struct list *p, int ncol)
{
    printf ("列出列表数据：\n");
    int i;
    for (i = 0; p != NULL; i++)
    {
        printf ("No%d 数据:%d\t", i + 1, p->nData);
        p = p->pn;
        if ((i + 1) % ncol == 0)
            printf ("\n");
    }
    printf ("\n");
    return i;
};

int RandMakeList (struct list *p, int datasize, int mod, int nInitData)
{
    srand (time (NULL));
    /*  for (int i = 0; i < datasize; i++)
        {
        p[i].nData = rand () % mod;
        if (i == datasize - 1)
        {
        p[i].pn = NULL;
        }
        else
        {
        p[i].pn = &p[i + 1];
        }
        }
        */
    struct list *pc = p;
    for (int i = 0; i < datasize; i++)
    {
        pc->nData = rand () % mod;
        if (i == datasize - 1)
        {
            pc->pn = NULL;
        }
        else
        {
            pc->pn = (pc + 1);
        }
        pc++;
    }
    //
    return 0;
};

int PutListnData (struct list *p, int datalocate, int data)
{

    int i = 0;
    struct list *pmark = p;
    for (i = 0; i < datalocate; i++)
        if (pmark->pn != NULL)
        {
            pmark = pmark->pn;
        }
        else
        {
            return ERR_CODE_1;
        }
    pmark->nData = data;
    printf ("置入数据项No%d 数据is %d.\n", datalocate + 1, pmark->nData);
    return 0;
};

int GetListNData (struct list *p, int datalocate)
{

    int i = 0;
    struct list *pmark = p;
    int listsize = GetListSize (p);
    if (datalocate > listsize)
        return ERR_CODE_1;
    else
    {
        for (i = 0; i < datalocate; i++)
        {
            if (pmark->pn != NULL)
            {
                pmark = pmark->pn;
            }
            else
            {
                return ERR_CODE_1;
            }
        }
    }
    return pmark->nData;
};

int GetData (struct list *p, int *loc)
{
    int listsize = 0;
    listsize = GetListSize (p);
    printf ("请输入准备取值的数据位置-%d)\n", listsize);
    scanf ("%d", loc);
    return GetListNData (p, *loc);
};

int GetListSize (struct list *p)
{
    int icount;
    for (icount = 0; p != NULL; icount++)
        p = p->pn;
    return icount;
};

int ReSizeList (struct list **pplist, int nnewsize)
{
    if (*pplist == NULL || nnewsize == 0)
        return ERR_CODE_1;
    else
    {
        free (*pplist);
        *pplist = (list*)malloc (sizeof (struct list) * nnewsize);
        InitList (*pplist, nnewsize, nInitData);
    }
    return nnewsize;
};

int GetNewSize (struct list *poldlist)
{
    int oldlistsize = 0;
    int newlistsize = 0;
    oldlistsize = GetListSize (poldlist);
    printf ("请输入新尺寸(当前列表尺寸是： %d)\n",
            oldlistsize);
    scanf ("%d", &newlistsize);
    if (oldlistsize != newlistsize)
        return newlistsize;
    else
        return ERR_CODE_1;
};

int InsertToList (struct list *plist, int insertlocate, int insertdata)
{
    int i = 0;
    struct list *pcurrentlist;
    for (i = 0; i < GetListSize (plist) && i < insertlocate; i++)
    {
        pcurrentlist = plist->pn;
        pcurrentlist = pcurrentlist->pn;
    }
    pcurrentlist->nData = insertdata;
    return 0;
};
