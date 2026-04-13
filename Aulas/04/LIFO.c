#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main(void) {
    Stack *pilha = s_new();
    if(pilha == NULL) goto BAD_ALLOC;

    int n;
    for(int i = 0; i < 64; i++) {
        n = rand()%128;
        printf("%d: %d (%d)\n", i, n, (int) s_push(pilha, n));
    }

    printf("\n");
    while(!s_empty(pilha)) {
        printf("%d ", s_top(pilha));
        s_pop(pilha);
    }

    printf("\n");

    return 0;

    // Caso haja alguma falha de alocação de memória
    BAD_ALLOC:
    printf("Falha na alocação de memória! Saindo.\n");
    return -1;
}