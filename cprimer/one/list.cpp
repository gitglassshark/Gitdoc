#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.hpp"

int SIZE = 30;
int lineitemnumber = 3;
int ERR1 = 1;
int initdata = 0;
int runlist (int argc,char * argv[])
{
// git test modified text
  int size = SIZE;
  struct list *listone = NULL;
  listone =(list *) malloc (sizeof (struct list) * size);
  int listdata = 8;
  initlist (listone, size, initdata);
  char cchoice;
  int isignexit = 0;
  while (isignexit == 0)
    {
      cchoice = makemenu ();
      switch (cchoice)
	{
	case '1':
	  initlist (listone, size, initdata);
	  break;
	case '2':
	  randmakelist (listone, size, 200, listdata);
	  break;
	case '3':
	  putlistndata (listone, 4, 7);
	  break;
	case '4':
	  printlist (listone, lineitemnumber);
	  break;
	case '5':
	  printlistp (listone, size, lineitemnumber);
	  break;
	case '6':
	  printf ("List total is:%d\n", totallist (listone, size));
	  break;
	case '7':
	  {
	    int gdata = 0;
	    int locate = 0;
	    gdata = getdata (listone, &locate);
	    printf ("The locate %d data is %d\n", locate + 1, gdata);
	  }
	  break;
	case '8':
	  {
	    size = getnewsize (listone);
	    resizelist (&listone, size);
	  }
	  break;
	case '9':
	  {
	    printf ("List size is %d\n", getlistsize (listone));
	  }
	  break;
	case '0':
	  isignexit = 1;
	  break;
	default:
	  printf ("error cchoice can't be run.....\n");
	}
      getchar ();
    }

  /*
     int No = 84;
     printf ("THE LIST No%d LOCATE DATA IS:%d.\n", No, getlistndata
     (listone, No)); */
  free (listone);
  listone = NULL;
  return 0;
}

char
makemenu ()
{
  printf ("===== List fuction menu=====\n");
  printf ("(Right Author by yan:bbc@sina.com)\n");
  printf ("1.Reinital List\n");
  printf ("2.Use random data make List\n");
  printf ("3.Put data to List\n");
  printf ("4.Print List\n");
  printf ("5.Print List data memory Address\n");
  printf ("6.Total List data\n");
  printf ("7.Get List data\n");
  printf ("8.Resize List\n");
  printf ("9.Get List size\n");
  printf ("0.Exit\n");
  char i = getchar ();
  printf ("%c\n", i);
  return i;
};

int
totallist (struct list *p, int datasize)
{
  int total = 0;
  for (int i = 0; i < datasize; i++)
    {
      total += p[i].data;
    }
  return total;
};

int
initlist (struct list *p, int datasize, int initdata)
{
  for (int i = 0; i < datasize; i++)
    {
      p[i].data = initdata;
      if (i == datasize - 1)
	{
	  p[i].pn = NULL;
	}
      else
	{
	  p[i].pn = &p[i + 1];
	}
    }
  printf ("initlist......\n");
  return 0;
};

int
printlistp (struct list *p, int datasize, int ncol)
{
  printf ("LIST STRUCT PIONTER :\n");
  for (int i = 0; i < datasize; i++)
    {
      printf ("No%d struct Memaddress is %p,No%d->P is %p\t", i,
	      (void *) &p[i], i, (void *) p[i].pn);
      if ((i + 1) % ncol == 0)
	printf ("\n");
    }
  printf ("\n");
  return 0;
};

int
printlist (struct list *p, int ncol)
{
  printf ("LIST LIST'S DATA\n");
  int i;
  for (i = 0; p != NULL; i++)
    {
      printf ("No%d DATA:%d\t", i + 1, p->data);
      p = p->pn;
      if ((i + 1) % ncol == 0)
	printf ("\n");
    }
  printf ("\n");
  return i;
};

int
randmakelist (struct list *p, int datasize, int mod, int listdata)
{
  srand (time (NULL));
/*  for (int i = 0; i < datasize; i++)
    {
      p[i].data = rand () % mod;
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
      pc->data = rand () % mod;
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

int
putlistndata (struct list *p, int datalocate, int data)
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
	return ERR1;
      }
  pmark->data = data;
  printf ("THE PUT No%d DATA is %d.\n", datalocate + 1, pmark->data);
  return 0;
};

int
getlistndata (struct list *p, int datalocate)
{

  int i = 0;
  struct list *pmark = p;
  int listsize = getlistsize (p);
  if (datalocate > listsize)
    return ERR1;
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
	      return ERR1;
	    }
	}
    }
  return pmark->data;
};

int
getdata (struct list *p, int *loc)
{
  int listsize = 0;
  listsize = getlistsize (p);
  printf ("Please input the locate of want to get data(1-%d)\n", listsize);
  scanf ("%d", loc);
  return getlistndata (p, *loc);
};

int
getlistsize (struct list *p)
{
  int icount;
  for (icount = 0; p != NULL; icount++)
    p = p->pn;
  return icount;
};

int
resizelist (struct list **pplist, int nnewsize)
{
  if (*pplist == NULL || nnewsize == 0)
    return ERR1;
  else
    {
      free (*pplist);
      *pplist = (list*)malloc (sizeof (struct list) * nnewsize);
      initlist (*pplist, nnewsize, initdata);
    }
  return nnewsize;
};

int
getnewsize (struct list *poldlist)
{
  int oldlistsize = 0;
  int newlistsize = 0;
  oldlistsize = getlistsize (poldlist);
  printf ("Please input the new size(Current list size is %d)\n",
	  oldlistsize);
  scanf ("%d", &newlistsize);
  if (oldlistsize != newlistsize)
    return newlistsize;
  else
    return ERR1;
};

int
inserttolist (struct list *plist, int insertlocate, int insertdata)
{
  int i = 0;
  struct list *pcurrentlist;
  for (i = 0; i < getlistsize (plist) && i < insertlocate; i++)
    {
      pcurrentlist = plist->pn;
      pcurrentlist = pcurrentlist->pn;
    }
  pcurrentlist->data = insertdata;
  return 0;
};
