#include<stdio.h>
#include<stdlib.h>


void printArray(Item* V, int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", key(V[i]));
    printf("\n");
}