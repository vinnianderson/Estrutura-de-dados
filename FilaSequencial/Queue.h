#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct queue {
    int dados[TAM];
    int inicio;
    int fim;
    int tamanho;
} Queue;

void inicialize(Queue* q) {
    q->inicio = 0;
    q->fim = -1;
    q->tamanho = 0;
}

int isEmpty(Queue q) {
    return q.tamanho == 0;
}

int isFull(Queue q) {
    return q.tamanho == TAM;
}

void enqueue(Queue* q, int valor) {
    if (isFull(*q)) {
        printf("Fila cheia. Não é possível adicionar o elemento.\n");
        return;
    }
    q->fim = (q->fim + 1) % TAM;
    q->dados[q->fim] = valor;
    q->tamanho++;
}

int dequeue(Queue* q) {
    if (isEmpty(*q)) {
        printf("Fila vazia. Não é possível remover o elemento.\n");
        return -1;
    }
   int retorno = f->dados[f->inicio];
   for (int i = 0; i < f->fim; i++){
    f->dados[i] = f->dados[i+1];
   }
   f->fim--;
   return retorno;
}

int front(Queue q) {
    if (isEmpty(q)) {
        printf("Fila vazia.\n");
        return -1;
    }
    return q.dados[q.inicio];
}

void printQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos da fila: ");
    for (int i = 0; i < q.tamanho; i++) {
        int index = (q.inicio + i) % TAM;
        printf("%d ", q.dados[index]);
    }
    printf("\n");
}

int main() {
    Queue q;
    inicialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Início da fila: %d\n", front(q));

    printQueue(q);

    while (!isEmpty(q)) {
        printf("Removido: %d\n", dequeue(&q));
    }

    printQueue(q);

    return 0;
}
