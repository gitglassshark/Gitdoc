#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list;
struct list
{
  struct list *pn;
  int data;
};

int initlist (struct list *p, int datasize, int initdata);
int printlist (struct list *p, int ncol);
int totallist (struct list *p, int datasize);
int printlistp (struct list *p, int datasize, int ncol);
int randmakelist (struct list *p, int datasize, int mod, int listdata);
int putlistndata (struct list *p, int datalocate, int data);
int getlistndata (struct list *p, int datalocate);
int getlistsize (struct list *p);
int getdata (struct list *p, int *loc);
int resizelist (struct list **pplist, int nnewsize);
int getnewsize (struct list *poldlist);
char makemenu ();
int run ();
