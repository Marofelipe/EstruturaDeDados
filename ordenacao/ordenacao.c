#include<stdio.h>
#include<stdlib.h>
#include"mergeSort.h"
#include"quickSort.h"
#include"../busca/binary_search.h"

#define TAM 10
#define BUSCA 16807

int main() {
    Item *V = malloc(sizeof(Item) * TAM);
    for (int i = 0; i < TAM; i++)
        V[i] = rand();

    //quickSort(V, 0, TAM);
    mergeSort(V, 0, TAM - 1);
    printArray(V, TAM);

    int index = binary_search(V, 0, TAM, BUSCA);

    if(index > -1) printf("Numero %d foi encontrado na %dª posicao\n", V[index], index + 1);
    else printf("Numero %d não foi encontrado \n", BUSCA);

    free(V);
    return 0;
}