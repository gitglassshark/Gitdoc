#include <stdio.h>

int run (int *arstart, int size);
struct pn;
struct pn
{
  struct pn *lp;
  int l;
};
int initpn (struct pn *p, int size);

int runone ();
int
main ()
{
  return runone ();
}

int
runone ()
{
  int i;
  i = 100;
  run (&i, i);
  while (i > 0)
    {
      i--;
      printf ("%d", i);
      if (i % 18)
	{
	  printf ("\t");
	}
      else
	{
	  printf ("\n");
	}
    }
  printf ("\n");
  return 0;

}

int
run (int *arstart, int size)
{
  struct pn a[size];
  int i = 0;
  initpn (a, size);
  return 0;
};

int
initpn (struct pn *p, int size)
{
  if (p == NULL || size == 0)
    return 100;
  int i = 0;
  while (size > 0)
    {
      p[i].lp = &p[i + 1];
      p[i].l = size;
      i++;
      size--;
    }

  return 0;
}
