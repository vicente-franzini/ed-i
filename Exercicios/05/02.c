// Exercicio 2 • Construir uma função em C que recebe como
// parâmetro duas filas não vazias (Fila1 e Fila2)
// contendo números inteiros ordenados (com no máximo 20
// elementos), e monta uma terceira fila (Fila3),
// circular, com os elementos de Fila1 e Fila2. Fila3
// deverá ter seus elementos inseridos de forma ordenada.
// Não utilizar estrutura auxiliar
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXN 50

typedef struct _fila {
    int array[MAXN];
    // front = indice do elemento imediatamente anterior ao primeiro
    // rear  = indice do último elemento da fila

    // você adiciona elementos no rear e remove do front
    int front, rear;
} Fila;

Fila *f_new() {
    Fila *f = malloc(sizeof(Fila));
    if(f == nullptr) return nullptr;

    f->front = -1;
    f->rear = -1;

    return f;
}

bool f_empty(Fila *fila) {
    return fila->front == fila->rear;
}

bool f_inserir(Fila *fila, int valor) {
    fila->rear = (fila->rear + 1) % MAXN;

    if(fila->rear == fila->front) {
        printf("Overflow!\n");
        return false;
    }

    fila->array[fila->rear] = valor;
}

int f_remover(Fila *fila) {
    if(f_empty(fila)) {
        printf("Underflow!\n");
        return -1;
    }

    fila->front = (fila->front + 1) % MAXN;

    return fila->array[fila->front];
}

int main(void) {
    
    /**
     * ALOCAÇÃO DAS FILAS E PREENCHIMENTO DAS DUAS INICIAIS
     */
    Fila *f1 = f_new();
    Fila *f2 = f_new();
    Fila *f3 = f_new();

    if(f1 == nullptr || f2 == nullptr || f3 == nullptr) {
        printf("Erro na alocação! Saindo.\n");
        return -1;
    }

    srand(time(NULL));

    int n1 = rand() % 5 + 1;
    int n2 = rand() % 5 + 1;
    for(int i = 0; i < 20; i++) {
        printf("%d ", n1);
        f_inserir(f1, n1);
        n1 += rand() % 5 + 1;
    }
    putchar('\n');

    for(int i = 0; i < 20; i++) {
        printf("%d ", n2);
        f_inserir(f2, n2);
        n2 += rand() % 5 + 1;
    }
    putchar('\n');


    /**
     * JUNÇÃO DAS DUAS FILAS
     */
    n1 = f_remover(f1);
    n2 = f_remover(f2);

    while(!(f_empty(f1) || f_empty(f2))) {
        if(n1 < n2) {
            f_inserir(f3, n1);
            n1 = f_remover(f1);
        } else {
            f_inserir(f3, n2);
            n2 = f_remover(f2);
        }
    }

    if(n1 < n2) {
        f_inserir(f3, n1);
        f_inserir(f3, n2);
    } else {
        f_inserir(f3, n2);
        f_inserir(f3, n1);
    }

    while(!f_empty(f1))
        f_inserir(f3, f_remover(f1));

    while(!f_empty(f2))
        f_inserir(f3, f_remover(f2));


    // IMPRIME A FILA RESULTANTE
    while(!f_empty(f3))
        printf("%d ", f_remover(f3));

    putchar('\n');

    return 0;
}