#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct stack {
    int dados[TAM];
    int topo;
} Stack;

// Função para inicializar a pilha
void inicialize(Stack* s) {
    s->topo = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack s) {
    return s.topo == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack s) {
    return s.topo == TAM - 1;
}

// Função para adicionar um elemento no topo da pilha
void push(Stack* s, int valor) {
    if (isFull(*s)) {
        printf("Pilha cheia. Não é possível adicionar o elemento.\n");
        return;
    }
    s->dados[++s->topo] = valor;
}

// Função para remover e retornar o elemento do topo da pilha
int pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Pilha vazia. Não é possível remover o elemento.\n");
        return -1; // Indicador de erro
    }
    return s->dados[s->topo--];
}

// Função para olhar o elemento no topo da pilha sem removê-lo
int top(Stack s) {
    if (isEmpty(s)) {
        printf("Pilha vazia.\n");
        return -1; // Indicador de erro
    }
    return s.dados[s.topo];
}

// Função para exibir todos os elementos da pilha
void printStack(Stack s) {
    if (isEmpty(s)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = 0; i <= s.topo; i++) {
        printf("%d ", s.dados[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    inicialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Topo da pilha: %d\n", top(s));

    printStack(s);

    while (!isEmpty(s)) {
        printf("Removido: %d\n", pop(&s));
    }

    printStack(s);

    return 0;
}
