#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100
#define LUI long unsigned int
#define I  int
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
  i = NUM;
  run (&i, i);
  int inOddNumber = 0;
  int inEvenNumber = 0;
  int total = 0, num = 0;
  srand (time (NULL));
  while (i > 0)
    {
      num = rand () % 100;
      if (num % 2)
	{
	  inOddNumber++;
	}
      else
	{
	  inEvenNumber++;
	}
      printf ("%d:%d\t", i, num);
      total += num;
      i--;
      if (!(i % 18))
	{
	  printf ("\n");
	}
    }

  printf
    ("total number is :%d,EvenNumber is %d,OddNumber is %d,Avage number is %f.\n",
     total, inEvenNumber, inOddNumber, (double) (total / NUM));
  printf ("char size of %d\n", (I) sizeof (char));
  printf ("int size of %d\n", (I) sizeof (int));
  printf ("long size of %d\n", (I) sizeof (long));
  printf ("float size of %d\n", (I) sizeof (float));
  printf ("double size of %d\n", (I) sizeof (double));
  printf ("%d mod 11 is %d\n", total, total % 11);

  return 0;

}

int
run (int *arstart, int size)
{
  struct pn a[size];
  //int i = 0;
  for (int i = 0; i < size; i++)
    printf ("i is %d\t", i);
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
