#include <stddef.h>

typedef struct _stack {
    char    *stack;
    size_t allocated;
    int    stack_pointer;
} Stack;

/*----------------------------
--       versão C23+        --
-- com tipos bool & nullptr --
----------------------------*/
#if __STDC_VERSION__ >= 202311L

// Aloca uma nova pilha e retorna um ponteiro para ela.
// Retorna nullptr caso haja uma falha.
Stack* s_new() {
    Stack *s = malloc(sizeof(Stack));
    if(s == nullptr) return nullptr;

    s->stack = malloc(sizeof(char) * 8);
    if(s->stack == nullptr) {
        free(s);
        return nullptr;
    }

    s->allocated     =  8;
    s->stack_pointer = -1;

    return s;
}

// Verifica se a pilha está vazia ou não.
// Retorna true em caso de pilha nula.
bool s_empty(Stack *stack) {
    if(stack == nullptr) return true;
    return stack->stack_pointer == -1;
}

// Adiciona um elemento ao topo da pilha.
// Retorna true se a operação foi bem sucedida.
bool s_push(Stack *stack, char valor) {
    if(stack == nullptr) return false;
    if(stack->stack == nullptr) return false;

    // Caso precise aumentar o tamanho da lista
    if((size_t) (stack->stack_pointer + 2) > stack->allocated) {
        stack->allocated -= stack->allocated & 7;
        stack->allocated += 8;

        stack->stack = (char *) realloc(stack->stack, 
            sizeof(char) * stack->allocated);

        if(stack->stack == nullptr) return false;
    }

    stack->stack[++stack->stack_pointer] = valor;
    return true;
}

// Remove o elemento do topo da pilha.
// Retorna true se a operação for bem sucedida.
bool s_pop(Stack *stack) {
    if(stack == nullptr) return false;
    if(stack->stack == nullptr) return false;

    // Caso tenha 64 espaços vazios ou mais, diminua
    // o tamanho alocado
    if(stack->allocated - stack->stack_pointer >= 64) {
        stack->allocated -= 48;
        stack->stack = (char *) realloc(stack->stack, 
            sizeof(char) * stack->allocated);

        if(stack->stack == nullptr) return false;
    }

    stack->stack_pointer--;
    return true;
}

// Retorna o elemento no topo da pilha.
// Retorna -1 caso haja alguma falha.
char s_top(Stack *stack) {
    if(stack->stack == nullptr) return -1;
    if(stack->stack == NULL) return -1;
    if(stack->stack_pointer < 0) return -1;

    return stack->stack[stack->stack_pointer];
}

#else
/*----------------------------
--       versão C23-        --
-- sem tipos bool & nullptr --
----------------------------*/

// Aloca uma nova pilha e retorna um ponteiro para ela.
// Retorna NULL caso haja uma falha.
Stack* s_new() {
    Stack *s = malloc(sizeof(Stack));
    if(s == NULL) return NULL;

    s->stack = malloc(sizeof(char) * 8);
    if(s->stack == NULL) {
        free(s);
        return NULL;
    }

    s->allocated     =  8;
    s->stack_pointer = -1;

    return s;
}

// Verifica se a pilha está vazia ou não.
// Retorna 0 em caso de pilha nula.
int s_empty(Stack *stack) {
    if(stack == NULL) return 0;
    return stack->stack_pointer == -1;
}

// Adiciona um elemento ao topo da pilha.
// Retorna 0 se a operação foi bem sucedida.
int s_push(Stack *stack, char valor) {
    if(stack == NULL) return -1;
    if(stack->stack == NULL) return -1;

    // Caso precise aumentar o tamanho da lista
    if((size_t) (stack->stack_pointer + 2) > stack->allocated) {
        stack->allocated >>= 3;
        stack->allocated +=  1;
        stack->allocated <<= 3;

        stack->stack = (char *) realloc(stack->stack, 
            sizeof(char) * stack->allocated);

        if(stack->stack == NULL) return -1;
    }

    stack->stack[++stack->stack_pointer] = valor;
    return 0;
}

// Remove o elemento do topo da pilha.
// Retorna 0 se a operação for bem sucedida.
int s_pop(Stack *stack) {
    if(stack == NULL) return -1;
    if(stack->stack == NULL) return -1;

    // Caso tenha 64 espaços vazios ou mais, diminua
    // o tamanho alocado
    if(stack->allocated - stack->stack_pointer >= 64) {
        stack->allocated -= 48;
        stack->stack = (char *) realloc(stack->stack, 
            sizeof(char) * stack->allocated);

        if(stack->stack == NULL) return -1;
    }

    stack->stack_pointer--;
    return 0;
}

// Retorna o elemento no topo da pilha.
// Retorna -1 caso haja alguma falha.
char s_top(Stack *stack) {
    if(stack->stack == NULL) return -1;
    if(stack->stack_pointer < 0) return -1;

    return stack->stack[stack->stack_pointer];
}

#endif