// Exercicio 1 • Faça um programa em C que cria uma lista estática 
// encadeada cujos nós têm dois campos: info e prox (ambos do tipo
// inteiro). Inicialize propriamente o vetor, criando a lista de 
// nós livres (apontada por dispo)

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct ListaEE {
    int info;
    int prox;
};

struct ListaEE no[MAX];
int dispo = 0;
int L = 0;

// a) Faça uma função para inserir nós numa lista ordenada sem
// repetição, apontada por L (indica a posição do primeiro nó).
// Para inserir nós em L, primeiramente deve-se obtê-los da lista
// dispo.
int inserir_no(int valor) {
    int no_i = dispo;
    no[no_i].info = valor;
    dispo = no[no_i].prox;

    return no_i;
}

// b) Faça uma função que receba como parâmetros Vi e Vf (números
// inteiros), sendo Vi < Vf. A função deverá eliminar da lista os
// nós cujos valores do campo info estejam compreendidos entre Vi
// e Vf (inclusive eles). Assuma que os valores de Vi e Vf estão
// contidos em L, e que Vi não é o primeiro nó e Vf não é o último
// nó da lista. Os nós eliminados deverão ser inseridos
// apropriadamente na lista indicada por dispo.
int remover_nos(int Vi, int Vf) {
    if(Vi >= Vf) return -1;

    int i = L;
    do {
        int ind = i;
        i = no[i].prox;

        if(no[ind].info >= Vi && no[ind].info <= Vf) {
            no[ind].prox = dispo;
            dispo = ind;
        }

    } while(no[i].prox != -1);

    return 0;
}

int main(void) {
    for(int i = 0; i < MAX-1; i++) {
        no[i].prox = i+1;
    }
    no[MAX - 1].prox = -1;

    return 0;
}