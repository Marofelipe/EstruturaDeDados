#include<stdio.h>
#include<stdlib.h>
#define MAX 100001
#define Item int
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define lessaq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item aux; aux = A;A = B;B = aux; }
#define cmp(A, B) (key(A) == key(B))

void mergeSort(Item *V, int l, int r);
void merge(Item *V, int l, int m, int r);

int main() {
    int entrada[MAX], i = 0;
    while (scanf("%d", &entrada[i]) == 1){ i++; };
    mergeSort(entrada, 0, i - 1);
    for (int j = 0; j < i; j++){ 
        printf("%d%c", entrada[j], (j < i - 1)? ' ': '\n'); 
    }
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
