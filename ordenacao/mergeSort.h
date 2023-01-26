#include "macros.h"

void mergeSort(Item *V, int l, int r);
void merge(Item *V, int l, int m, int r);

void mergeSort(Item *V, int l, int r) {
    if(l >= r) return;
    int meio = ((r + l)/ 2);
    mergeSort(V, l, meio);
    mergeSort(V, meio + 1, r);
    merge(V, l, meio, r);
}

void merge(Item *V, int l, int m, int r) {
    Item *R = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if(less(V[i], V[j])) 
            R[k++] = V[i++];
        else 
            R[k++] = V[j++];
    }

    while (i <= m) R[k++] = V[i++]; 
    while (j <= r) R[k++] = V[j++]; 

    k = 0;
    for (i = l; i <= r; i++) V[i] = R[k++];
    free(R);
}