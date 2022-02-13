#pragma once

struct pn;
struct pn
{
    struct pn *lp;
    int l;
};

int InitPNL (struct pn *p, int size);
int RunSF (int *arstart, int size);
int RunOneSF ();
