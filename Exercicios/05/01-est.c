// Exercicio 1 • Elaborar uma função em C que recebe como
// parâmetro uma fila não vazia contendo números inteiros
// e constrói duas outras filas, sendo que uma deve conter
// os pares e a outra os ímpares da sequência armazenada
// na fila inicial. Não usar estrutura auxiliar.
#include <stdlib.h>
#include <stdio.h>

#define MAX 128

typedef struct _fila {
    int fila[128];
    int inicio, fim;
} Fila;

Fila *f_new() {
    Fila *f = malloc(sizeof(Fila));
    if(f == nullptr) return nullptr;

    f->inicio, f->fim = -1;
}

bool f_empty(Fila *fila) {
    return fila->inicio == fila->fim;
}

bool f_inserir(Fila *fila, int valor) {
    if(fila == nullptr) return false;
    if(fila->fim > MAX-1) return false;

    fila->fila[++fila->fim] = valor;
    return true;
}

int f_remover(Fila *fila) {
    if(fila == nullptr) return -1;
    if(fila->fim == fila->inicio) return -1;

    return fila->fila[++fila->inicio];
}

void separarPares(Fila *inp, Fila **impares, Fila **pares) {
    *impares = f_new();
    *pares   = f_new();

    while(!f_empty(inp)) {
        if(inp->fila[inp->inicio + 1] % 2)
            f_inserir(*impares, f_remover(inp));
        else
            f_inserir(*pares, f_remover(inp));
    }
}

int main(void) {
    Fila *inp = f_new(), *impares, *pares;

    for(int i = 0; i < 50; i++) {
        f_inserir(inp, rand()%1000);
    }

    separarPares(inp, &impares, &pares);

    printf("Pares: ");
    while(!f_empty(pares)) printf("%d ", f_remover(pares));

    printf("\nImpares: ");
    while(!f_empty(impares)) printf("%d ", f_remover(impares));

    return 0;
}