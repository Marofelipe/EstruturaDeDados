#include<stdio.h>
#include<stdlib.h>
#include"../../ordenacao/macros.h"
#define TAM 280001

int id(Item valor) {
    return key(valor) % TAM;
}

int main() {
    Item* hash = calloc(TAM,sizeof(Item));

    int numberOfStudents, input, index;
    scanf("%d", &numberOfStudents);
    for (int i = 0; i < numberOfStudents; i++)
    {
        scanf("%d", &input);
        index = id(input);
        hash[index]++;
    }
    
    free(hash);
    return 0;
}