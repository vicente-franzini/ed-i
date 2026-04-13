// Exercicio 1 • Elaborar uma função em C que recebe como
// parâmetro uma fila não vazia contendo números inteiros
// e constrói duas outras filas, sendo que uma deve conter
// os pares e a outra os ímpares da sequência armazenada
// na fila inicial. Não usar estrutura auxiliar.
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int valor;
    struct _no *prox;
} No;

typedef struct _fila {
    No *inicio, *fim;
} Fila;

Fila *f_new() {
    Fila *f = calloc(1, sizeof(Fila));
    
    return f;
}

bool f_empty(Fila *fila) {
    return fila->inicio == nullptr;
}

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

void separarPares(Fila *inp, Fila **impares, Fila **pares) {
    *impares = f_new();
    *pares   = f_new();

    while(!f_empty(inp)) {
        if(f_topo(inp) % 2)
            f_inserir(*impares, f_topo(inp));
        else
            f_inserir(*pares, f_topo(inp));
        
        f_eliminar(inp);
    }
}

int main(void) {
        Fila *inp = f_new(), *impares, *pares;

    for(int i = 0; i < 50; i++) {
        f_inserir(inp, rand()%1000);
    }

    separarPares(inp, &impares, &pares);

    printf("Pares: ");
    while(!f_empty(pares)) {
        printf("%d ", f_topo(pares));
        f_eliminar(pares);
    }

    printf("\nImpares: ");
    while(!f_empty(impares)) {
        printf("%d ", f_topo(impares));
        f_eliminar(impares);
    }

    return 0;
}