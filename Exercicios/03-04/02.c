// Exercicio 2 • Em algumas aplicações tem-se que trabalhar com
// mais de uma pilha ao mesmo tempo. Pode-se implementar essas
// pilhas num mesmo array, de forma que cada uma ocupe parte
// desse array. Considerando um array de inteiros, declarado de
// forma global, com 100 posições e duas pilhas, cada uma
// crescendo em sentido oposto (uma iniciando na posição 0
// e a outra em 99), implemente em C as operações básicas de:
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct _pilha {
    int pilha[100];
    int sp_1;
    int sp_2;
} Pilha;

Pilha pilha = {{}, -1, 100};

// a) verificar se as pilhas estão vazias (retornar “V ou F”;
// uma função para cada pilha);
bool p1_empty() {
    return pilha.sp_1 <= -1;
}

bool p2_empty() {
    return pilha.sp_2 >= 100;
}

// b) verificar se as pilhas estão cheias (retornar “V ou F”);
bool p_full() {
    return pilha.sp_1 >= (pilha.sp_2 - 1);
}

// c) empilhar um mesmo elemento em cada uma das pilhas;
void p_empilhar(int valor) {
    pilha.pilha[++pilha.sp_1] = valor;
    pilha.pilha[--pilha.sp_2] = valor;
}

// d) desempilhar um elemento de cada uma das pilhas.
void p_desempilhar() {
    if(!p1_empty()) --pilha.sp_1;
    if(!p2_empty()) ++pilha.sp_2;
}

int p1_top() {
    return pilha.pilha[pilha.sp_1];
}

int p2_top() {
    return pilha.pilha[pilha.sp_2];
}

int main(void) {
    int n, s = 0;

    srand(time(NULL));
    for(; !p_full(); s++) {
        p_empilhar(rand() % 1000);
    }

    printf("s: %d\n", s);

    for(int i = 0; i < s; i++) {
        int p1_t = p1_top();
        int p2_t = p2_top();

        p_desempilhar();

        printf("p1_t: %d, p2_t: %d\n", p1_t, p2_t);
    }

    return 0;
}