#include"../ordenacao/macros.h"
#include"../uteis.h"

#define HASH_CHAVE 280001
#define MAX 280001

int id(Item valor) {
    return key(valor) % HASH_CHAVE;
}

void incrementSize(Item *hash_table, int size) {
    Item *newTable = malloc(sizeof(Item) * (size * 2));
    for (int i = 0; i < size; i++)
        newTable[i] = hash_table[i];
    
    hash_table = newTable;
}

void insert(Item *hash_table, Item valor, int count) {
    if(count >= MAX) incrementSize(hash_table, MAX);
    int index = id(valor);
    while(hash_table[index] != 0) {
        index = id(index + 1);
    }
    hash_table[index] = valor;
}

int search(Item *hash_table, Item valor) {
    int index = id(valor);
    while (index != 0)
    {
        if(cmp(hash_table[index], valor))
            return index;
        else
            index = id(index + 1);
    }
    return -1;
}


