#include<stdio.h>
#include<stdlib.h>
#include"../ordenacao/macros.h"

int binary_search(Item *V, int l, int r, Item valor);

int binary_search(Item *V, int l, int r, Item valor) {
    if(r >= l) {
        int mid = l + (r - l) / 2;
        if(key(V[mid]) == key(valor))
            return mid;
        if (V[mid] > valor)
            return binary_search(V, l, mid - 1, valor);
        return binary_search(V, mid + 1, r, valor);
    }
    return - 1;
}