#include<stdio.h>
#include<stdlib.h>
#define Item int
#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))

void mergeSort(Item *V, int l, int r);
void merge(Item *V, int l, int m, int r);
int search(Item *V, int n, Item valor);

int main() {
    int numeroDeProibidos, entrada;
    scanf("%d", &numeroDeProibidos);
    Item *V = (Item *)malloc(sizeof(Item) * numeroDeProibidos);
    for (int i = 0; i < numeroDeProibidos; i++)
       scanf("%d", &V[i]);

    mergeSort(V, 0, numeroDeProibidos - 1);

    while (scanf("%d", &entrada) == 1)
    {
        printf("%s\n", search(V, numeroDeProibidos, entrada) == 1? "sim": "nao");
    }
    
    free(V);
    return 0;
}


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
        if(lesseq(V[i], V[j])) 
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

int search(Item *V, int n, Item valor) {
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r)/ 2;
        if(V[m] == valor) return 1;
        else if(V[m] < valor) l = m + 1;
        else r = m - 1;   
    }
    return 0;
    
}

