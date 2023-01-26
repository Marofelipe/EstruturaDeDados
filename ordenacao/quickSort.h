#include<stdio.h>
#include<stdlib.h>
#include"macros.h"

void quickSort(Item *V, int l, int r);
int separa(Item *V, int l, int r);

void quickSort(Item *V, int l, int r) {
    if(r >= l) return;
    int aux = separa(V, l, r);
    quickSort(V, l, aux);
    quickSort(V, aux + 1, r);
}

int separa(Item *V, int l, int r) {
    Item pivo = V[r];
    int j = l;
    for (int k = l;k < r;k++) if(less(V[k], pivo))  exch(V[k], V[j]);
    exch(V[j], V[r]);
    return j;
}

int better_separa(Item *V, int l, int r) {
    Item pivo = V[r];
    int i = l - 1, j = r;
    for (;;)
    {
        while (less(V[i++], pivo));
        while (less(pivo, V[--j])) if(j == i) break;
        if(i >= j) break;
        exch(V[i], V[j]);
    }
    exch(V[i], V[r]);
    return i;
}


