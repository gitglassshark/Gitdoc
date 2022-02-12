#pragma once

struct pn;
struct pn
{
  struct pn *lp;
  int l;
};

int initpn (struct pn *p, int size);
int run (int *arstart, int size);
int runone ();
