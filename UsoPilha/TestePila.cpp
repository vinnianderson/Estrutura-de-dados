

#include <stdlib.h>
#include "../FilaSequencial/Queue.h"

typedef struct stackNode {
    int info;
    struct stackNode* prox;
} StackNode;

typedef StackNode* Stack;

void inicializar (Stack* s) {
    *s = NULL;
}

int isEmpty (Stack s) {
    if (s == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Stack s) {
    return 0;
}

void push (Stack* s, int valor) {
    StackNode* novo;
    novo = (StackNode*) malloc (sizeof(StackNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*s) == 1) {
        *s = novo;
    }
    else {
        novo->prox = *s;
        *s = novo;
    }
}

int pop (Stack* s) {
    StackNode* aux = *s;
    int valor;
    *s = (*s)->prox;
    valor = aux->info;
    free(aux);
    return valor;
}

int top (Stack s) {
    return s->info;
}


// Aplicação para testar a Stack implementada

// Arquivo "TestaStackInt.cpp" criado na pasta (folder) "UsoPilha"

#include <stdio.h>
#include "..\PilhaEncadeada\Stack.h"  // <<<<< ÚNICA LINHA DE CÓDIGO MODIFICADA!!!!

void exibirOpcoes () {
    printf ("Opções \n");
    printf ("1 - Empilhar \n");
    printf ("2 - Desempilhar \n");
    printf ("3 - Ver topo \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opção desejada: ");
}

int main () {
    Stack pilha1;
    int num, op;
    Queue fila;
     inicializar(&fila);
    inicializar(&pilha1);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: if (isFull (fila) == 1) {
                        printf ("Stack full! \n");
                    }
                    else {
                        printf ("Informe o valor a ser empilhado: ");
                        scanf ("%d",&num);
                        enqueue (&pilha1,num);
                    }
                    break;
            case 2: if (isEmpty (fila) == 1) {
                        printf ("queue empty! \n");
                    }
                    else {
                        num = dequeue (&fila);
                        printf ("Valor desempilhado: %d \n", num);
                    }
                    break;
            case 3: if (isEmpty (pilha1) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        num = top (pilha1);
                        printf ("Valor no topo da pilha: %d \n", num);
                    }
                    break;
            case 0: printf ("Bye bye \n");
                    break;
            default: printf ("Opção inválida \n");
        }
    } while (op != 0);
    return 0;
}
