// Exercicio 6 • Considerando alocação dinâmica de memória,
// implemente em C funções para:
//  - Inserir nós
//  - Remover nós
//  - Contar o número de nós
//
// Resolva para Listas Duplamente Ligadas
#include <stdlib.h>

typedef struct _node {
    int          info;
    struct _node *prox;
    struct _node *ant;
} Node;

// Inserir nós
bool ldl_inserir_antes(Node *no, int valor) {
    if(no == nullptr) return false;

    Node *novo = calloc(1, sizeof(Node));
    if(novo == nullptr) return false;

    Node *ant = no->ant;
    
    if(ant != nullptr)
        ant->prox = novo;
   
    no->ant = novo;

    novo->ant = ant;
    novo->prox = no;
    novo->info = valor;

    return true;
}

bool ldl_inserir_depois(Node *no, int valor) {
    if(no == nullptr) return false;

    Node *novo = calloc(1, sizeof(Node));
    if(novo == nullptr) return false;

    Node *prox = no->prox;
    
    if(prox != nullptr)
        prox->ant = novo;

    no->prox = novo;

    novo->prox = prox;
    novo->ant = no;
    novo->info = valor;

    return true;
}

// Remover nós
bool ldl_remover(Node *no) {
    if(no == nullptr) return false;

    if(no->ant != nullptr)
        no->ant->prox = no->prox;

    if(no->prox != nullptr)
        no->prox->ant = no->ant;
    
    free(no);

    return true;
}

// Contar o número de nós
int ldl_tamanho(Node *no) {
    if(no == nullptr) return 0;

    int n = 1;
    Node *atual = no;
    while(atual->prox != nullptr) {
        n++;
        atual = atual->prox;
    }

    atual = no;
    while(atual->ant != nullptr) {
        n++;
        atual = atual->ant;
    }

    return n;
}