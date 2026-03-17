// Exercicio 1 • Faça um programa em C que cria uma lista encadeada 
// dinâmica cujos nós têm dois campos: info e prox (info do tipo
// inteiro e prox ponteiro de nó). Inicialize propriamente o vetor
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox;
} No;

No *lista = NULL;

// Faça uma função para inserir nós numa lista ordenada, sem
// repetição, apontada por L o nó inicial.
int inserirNo(int info, No *L) {

    // Ache o último nó da lista
    No *atual = L;
    while(atual->prox != NULL) atual = atual->prox;

    // Aloque um novo nó, e retorne erro caso falhe
    atual->prox = (No*) malloc(sizeof(No));
    if(atual->prox == NULL) return -1;

    // Defina os valores corretos para o nó
    atual->prox->info = info;
    atual->prox->prox = NULL;
    return 0;
}

// Faça uma função que receba como parâmetros Vi e Vf (números
// inteiros), sendo Vi < Vf. A função deverá eliminar da lista
// os nós cujos valores do campo info estejam compreendidos entre
// Vi e Vf (inclusive eles).
int removerNos(int Vi, int Vf, No **L) {
    if(Vi >= Vf) return -1;
    No *atual = *L;
    No *ant   = NULL;

    while(true) {
        if(atual == NULL) return -1;
        
        if(atual->info < Vi || atual->info > Vf) {
            // Caso esteja fora do alcance que queremos deletar,
            // "ande" um nó tanto na variavel atual quanto anterior.
            // Saia do laço caso esteja no último nó
            if(atual->prox == NULL) break;
            ant = atual;
            atual = atual->prox;
        } else {
            // Salve o endereço para liberá-lo depois.
            No *lib = atual;

            // Caso o ponteiro para o nó anterior não seja nulo,
            // modifique seu ponteiro prox para o prox do atual.
            // Se não, modifique o ponteiro inicial da lista.
            if(ant != NULL) ant->prox = atual->prox;
            else *L = atual->prox;

            // Ande um passo com o ponteiro atual e libere o
            // nó excluído
            atual = atual->prox;
            free(lib);

            // Saia caso seja o último nó da lista.
            if(atual == NULL) break;
        }
    }

    return 0;
}

int main(void) {
    lista = (No*) malloc(sizeof(No));
    lista->prox = NULL;

    for(int i = 1; i < 10; i++) inserirNo(i, lista);

    printf("[ ");
    No *atual = lista;
    while(atual->prox != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("%d ]\n", atual->info);

    removerNos(0, 4, &lista);
    atual = lista;

    printf("[ ");
    atual = lista;
    while(atual->prox != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("%d ]\n", atual->info);

    return 0;
}
