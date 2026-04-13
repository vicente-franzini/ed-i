// Exercicio 6 • Considerando alocação dinâmica de memória,
// implemente em C funções para:
//  - Inserir nós
//  - Remover nós
//  - Contar o número de nós
//
// Resolva para Listas Circulares
#include <stdlib.h>

typedef struct _node {
    int          info;
    struct _node *prox;
} Node;

// Inserir nós
bool lc_inserir_antes(Node *no, int valor) {
    if(no == nullptr) return false;

    Node *final = no;
    while(final->prox != no)
        final = final->prox;

    Node *novo = calloc(1, sizeof(Node));
    if(novo == nullptr) return false;

    final->prox = novo;
    novo->info = valor;
    novo->prox = no;

    return true;
}

bool lc_inserir_depois(Node *no, int valor) {
    if(no == nullptr) return false;

    Node *novo = calloc(1, sizeof(Node));
    if(novo == nullptr) return false;

    novo->prox = no->prox;
    novo->info = valor;
    no->prox = novo;

    return true;
}

// Remover nós
bool lc_remover(Node *no) {
    if(no == nullptr) return false;

    Node *final = no;
    while(final->prox != no)
        final = final->prox;

    final->prox = no->prox;
    free(no);

    return true;
}

// Contar o número de nós
int lc_tamanho(Node *no) {
    if(no == nullptr) return 0;

    int n = 1;
    Node *final = no;
    while(final->prox != no) {
        n++;
        final = final->prox;
    }

    return n;
}