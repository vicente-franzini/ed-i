// Exercicio 3 • Considere as sequências de caracteres: 'C',
// 'aCa', 'abCba', 'baCab', 'aabCbaa', 'abaaCaaba'... .
// Uma sequência típica nesse conjunto pode ser descrita como
// wCwR, na qual w contém a sequência de a's e b's, ou w é vazia,
// e wR é o reverso de w. Por exemplo, se w = 'abb', então
// wR = 'bba'. Dada uma sequência de caracteres X de entrada
// qualquer (lida caractere por caractere a partir do teclado),
// faça um programa em C que use uma ÚNICA estrutura do tipo
// pilha (não é permitido usar nenhuma outra estrutura auxiliar)
// para responder (na forma de mensagem) se X pertence ou não
// ao conjunto de sequências, podendo ser descrito por wCwR.
// Considerar que a sequência de entrada nunca é vazia, que
// 'C' aparece uma única vez e que somente a's e b's aparecem
// em w.
//
//
// Obs.: para resolver será necessário criar programas que
// inicializem adequadamente as estruturas utilizadas.
// Resolva utilizando alocação estática e dinâmica 
// (dois programas).
#include <stdlib.h>
#include <stdio.h>

#include "pilha_dinamica.h"

int main(void) {
    Stack *pilha = s_new();
    // Caso a pilha não possa ser alocada, encerre o programa.
    if(pilha == nullptr) goto BAD_ALLOC;

    printf("Digite abaixo a sequencia de caracteres. Aperte enter quando ela acabar.\n");

    // Obtém todos os caracteres até 'C' e insere na pilha.
    char c = '\0';
    while((c = getchar()) != 'C') {
        if(!s_push(pilha, c)) goto BAD_ALLOC;
    }

    // Para cada caractere subsequente no input, verifique
    // se ele é igual ao topo da pilha.
    bool seguePadrao = true;
    while((c = getchar()) != '\n' && !s_empty(pilha)) {
        if(c != s_top(pilha)) {
            seguePadrao = false;
        }

        if(!s_pop(pilha)) goto BAD_ALLOC;
    }

    // Verificação para caso tenha mais caracters antes ou
    // depois do 'C'.
    if(!(c == '\n' && s_empty(pilha))) seguePadrao = false;

    if(seguePadrao) {
        printf("O input segue o padrao!\n");
    } else {
        printf("O input NAO segue o padrao.\n");
    }

    return 0;

    // Código caso haja algum erro de alocação de memória
    BAD_ALLOC:
    printf("Erro na alocação de memória! Encerrando.\n");
    return -1;
}