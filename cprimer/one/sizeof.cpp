#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100
#define LUI long unsigned int
#define I  int
const int nSize=100;
struct pn;
struct pn
{
    struct pn *lp;
    int l;
};

int InitPN (struct pn *p, int nSizeT);
int RunSFLl (struct pn *arstart, int nSizeT);
int RunOneSFx();

int RunOneSFx()
{
    int iROSizeL=nSize;
    struct pn pasSizeRO[nSize];
    RunSFLl (pasSizeRO, nSize);
    int inOddNumber = 0;
    int inEvenNumber = 0;
    int iTotalRO = 0, iNumRO = 0;
    srand (time (NULL));
    while (iROSizeL > 0)
        {
            iNumRO = rand () % 100;
            if (iNumRO % 2)
                {
                    inOddNumber++;
                }
            else
                {
                    inEvenNumber++;
                }
            printf ("%d:%d\t", iROSizeL, iNumRO);
            iTotalRO += iNumRO;
            iROSizeL--;
            if (!(iROSizeL % 18))
                {
                    printf ("\n");
                }
        }

    printf
    ("total number is :%d,EvenNumber is %d,OddNumber is %d,Avage number is %f.\n",
     iTotalRO, inEvenNumber, inOddNumber, (double) (iTotalRO / NUM));
    printf ("char型数据尺寸大小是：%d\n", (I) sizeof (char));
    printf ("int型数据尺寸大小是： %d\n", (I) sizeof (int));
    printf ("long型数据尺寸大小是：%d\n", (I) sizeof (long));
    printf ("float型数据尺寸大小是：%d\n", (I) sizeof (float));
    printf ("double型数据尺寸大小是：%d\n", (I) sizeof (double));
    printf ("%d mod(取余) 11 是：%d\n", iTotalRO, iTotalRO % 11);

    return 0;

}

int RunSFLl (struct pn *arstart, int nSizeT)
{
    //int i = 0;
    for (int i = 0; i < nSizeT; i++)
        printf ("i值：%d\t", i);
    InitPN (arstart, nSizeT);
    return 0;
};

int InitPN (struct pn *p, int nSizeT)
{
    if (p == NULL || nSizeT == 0)
        return 100;
    int i = 0;
    while (nSizeT > 0)
        {
            p[i].lp = &p[i + 1];
            p[i].l = nSizeT;
            i++;
            nSizeT--;
        }

    return 0;
}
