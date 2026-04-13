#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _no {
    int valor;
    struct _no *prox;
} No;

typedef struct _fila {
    No *inicio, *fim;
} Fila;

bool f_inserir(Fila *fila, int valor) {
    if(fila == nullptr) return false;

    if(fila->fim == nullptr) {
        fila->fim = calloc(1, sizeof(No));
        if(fila->fim == nullptr) return false;

        fila->fim->valor = valor;
        if(fila->inicio == nullptr)
            fila->inicio = fila->fim;
    } else {
        fila->fim->prox = calloc(1, sizeof(No));
        if(fila->fim->prox == nullptr) return false;

        fila->fim = fila->fim->prox;
        fila->fim->valor = valor;
    }

    return true;
}

bool f_eliminar(Fila *fila) {
    if(fila == nullptr) return false;
    if(fila->inicio == nullptr) return true;

    No *aux = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == nullptr)
        fila->fim = nullptr;

    free(aux);
    return true;
}

int f_topo(Fila *fila) {
    if(fila == nullptr) return -1;
    if(fila->inicio == nullptr) return -1;

    return fila->inicio->valor;
}

int main(void) {
    Fila *fila = calloc(1, sizeof(Fila));

    for(int i = 0; i < 10; i++)
        f_inserir(fila, i);

    while(fila->fim != nullptr) {
        printf("%d ", f_topo(fila));
        f_eliminar(fila);
    }

    return 0;
}