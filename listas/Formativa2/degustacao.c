#include<stdio.h>
#include<stdlib.h>
#define MAX 100001
#include"../../ordenacao/macros.h"

typedef struct node {
    int index, count;
    char letter;
}node;

int main() {
    node seq[MAX];
    int index = 0, aux = 0, count = 0;
    char entrada;
    while(scanf("%c", &entrada) == 1) {
        if(entrada != seq[aux].letter || index == 0){
            if(index == 0) aux++;

            seq[aux].index = index;
            seq[aux].count = 0;
        }
        seq[aux].letter = entrada;
        seq[aux].count = seq[aux].count + 1;
        index++;
    }
    mergeSort(seq, 0, aux);
    return 0;
}