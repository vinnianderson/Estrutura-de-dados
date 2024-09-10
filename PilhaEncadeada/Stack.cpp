#include <stdlib.h>
#include <stdio.h>

typedef struct stackNode {
    int info;
    struct stackNode* prox;
} StackNode;

typedef struct stack {
    StackNode* topo;
} Stack;

// Função para inicializar a pilha
void inicializar(Stack* s) {
    s->topo = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack s) {
    return s.topo == NULL;
}

// Função para verificar se a pilha está cheia
int isFull(Stack s) {
    // Para a pilha baseada em lista encadeada, nunca está cheia a menos que falte memória.
    return 0;
}

// Função para adicionar um elemento no topo da pilha
void push(Stack* s, int valor) {
    StackNode* novoNo = (StackNode*)malloc(sizeof(StackNode));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novoNo->info = valor;
    novoNo->prox = s->topo;
    s->topo = novoNo;
}

// Função para remover o elemento do topo da pilha
int pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Pilha vazia.\n");
        return -1; // Valor de erro ou pode-se usar um código de erro específico
    }
    StackNode* temp = s->topo;
    int valor = temp->info;
    s->topo = temp->prox;
    free(temp);
    return valor;
}

// Função para olhar o elemento no topo da pilha sem removê-lo
int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Pilha vazia.\n");
        return -1; // Valor de erro ou pode-se usar um código de erro específico
    }
    return s.topo->info;
}

// Função para liberar a memória alocada para a pilha
void liberar(Stack* s) {
    while (!isEmpty(*s)) {
        pop(s);
    }
}

int main() {
    Stack s;
    inicializar(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Topo da pilha: %d\n", peek(s));

    while (!isEmpty(s)) {
        printf("Removido: %d\n", pop(&s));
    }

    liberar(&s);
    return 0;
}
