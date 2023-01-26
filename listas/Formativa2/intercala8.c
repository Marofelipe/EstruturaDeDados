#include<stdio.h>
#include<stdlib.h>
#define Item int
#define MAX 100001

void merge(Item *V, int V_length, int *V2, int V2_length);

int main() {
    int length, final_length = 0;
    Item * V = malloc(sizeof(Item) * MAX);
    Item * Final = malloc(sizeof(Item) * MAX);
    for(int i = 0;i < 8;i++) {
        length = 0;
        scanf("%d", &length);
        for (int j = 0; j < length; j++)
            scanf("%d", &V[j]);
        merge(Final, final_length, V, length);
        final_length+= length;
    }

    for (int i = 0; i < final_length; i++)
        printf("%d", Final[i]);
    printf("\n");
    
    return 0;
}

void merge(Item *V, int V_length, int *V2, int V2_length)
{
    int *Aux = (int *)malloc((V_length + V2_length) * sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < V_length && j < V2_length; k++)
    {
        if (V[i] <= V2[j])
            Aux[k] = V[i++];
        else
            Aux[k] = V2[j++];
    }

    while (i < V_length)
        Aux[k++] = V[i++];
    while (j < V2_length)
        Aux[k++] = V[j++];

    for (k = 0, i = 0; i < (V_length + V2_length); i++, k++)
        V[i] = Aux[k];

    free(Aux);
}
