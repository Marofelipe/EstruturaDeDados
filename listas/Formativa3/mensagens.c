#include<stdio.h>
#include<stdlib.h>
#define HASH 1572869u
#define MAX 2046576
#define key(A) (A.numero)
#define less(A, B) (key(A) < key(B))
#define lessaq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item aux; aux = A;A = B;B = aux; }
#define cmp(A, B) (key(A) == key(B))

typedef struct entrada
{
    int numero;
    char valor;
}entrada;

#define Item entrada


void mergeSort(Item *V, int l, int r);
void merge(Item *V, int l, int m, int r);
int id(int valor);

int main() {
    int quantidade, numero, index, aux = 0;
    char valor;
    int *table = calloc(MAX, sizeof(int));
    entrada *entradas = malloc(sizeof(entrada) * MAX);
    while (scanf("%d %c", &numero, &valor) != EOF)
    {
        index = id(numero);
        table[index] = table[index] + 1;
        if(table[index] == 1) {
            entradas[aux].valor = valor;
            entradas[aux].numero = numero;
            aux++;
        }
    }

    mergeSort(entradas, 0, aux - 1);
    
    for(int i = 0;i < aux;i++) {
        printf("%c", entradas[i].valor);
    }
    printf("\n");

    free(entradas);
    free(table);
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

int id(int valor)  {
    return valor % HASH;
}
