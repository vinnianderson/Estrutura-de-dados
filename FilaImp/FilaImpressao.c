#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct queueNode {
    char info[MAX_STRING_LENGTH]; 
    struct queueNode* prox;
} QueueNode;

typedef struct queue {
    QueueNode* inicio;
    QueueNode* fim;
} Queue;

// Inicializa a fila
void inicializar(Queue* f) {
    f->inicio = NULL;
    f->fim = NULL;
}


int isEmpty(Queue f) {
    return (f.inicio == NULL);
}

int isFull(Queue f) {
    return 0; 
}


void enQueue(Queue* f, const char* nome_arquivo) {
    QueueNode* novo = (QueueNode*) malloc(sizeof(QueueNode));
    strncpy(novo->info, nome_arquivo, MAX_STRING_LENGTH);
    novo->info[MAX_STRING_LENGTH - 1] = '\0'; 
    novo->prox = NULL;
    if (isEmpty(*f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    printf("Arquivo '%s' adicionado à fila.\n", nome_arquivo);
}


void deQueue(Queue* f) {
    if (isEmpty(*f)) {
        printf("A fila está vazia. Não há arquivos para remover.\n");
        return;
    }
    QueueNode* aux = f->inicio;
    f->inicio = aux->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    printf("Arquivo '%s' removido da fila.\n", aux->info);
    free(aux);
}


const char* head(Queue f) {
    if (isEmpty(f)) {
        return NULL;
    }
    return f.inicio->info;
}


void cancel(Queue* f, const char* nome_arquivo) {
    if (isEmpty(*f)) {
        printf("A fila está vazia. Não há arquivos para cancelar.\n");
        return;
    }

    QueueNode *atual = f->inicio, *anterior = NULL;
    while (atual != NULL && strcmp(atual->info, nome_arquivo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Arquivo '%s' não encontrado na fila.\n", nome_arquivo);
        return;
    }

    if (anterior == NULL) {
        f->inicio = atual->prox;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
    } else {
        anterior->prox = atual->prox;
        if (atual == f->fim) {
            f->fim = anterior;
        }
    }

    printf("Arquivo '%s' removido da fila.\n", atual->info);
    free(atual);
}


void list(Queue f) {
    if (isEmpty(f)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Arquivos na fila de impressão:\n");
    QueueNode* atual = f.inicio;
    while (atual != NULL) {
        printf("%s\n", atual->info);
        atual = atual->prox;
    }

void exibirOpcoes() {
    printf("Opções\n");
    printf("1 - Enfileirar\n");
    printf("2 - Desenfileirar\n");
    printf("3 - Ver início da fila (head)\n");
    printf("4 - Cancelar um arquivo\n");
    printf("5 - Listar todos os arquivos\n");
    printf("0 - Encerrar programa\n");
    printf("Informe a opção desejada: ");
}

int main() {
    Queue fila;
    char nome_arquivo[MAX_STRING_LENGTH];
    int op;

    inicializar(&fila);

    do {
        exibirOpcoes();
        scanf("%d", &op);
        getchar(); 

        switch (op) {
            case 1:
                printf("Informe o nome do arquivo a ser enfileirado: ");
                fgets(nome_arquivo, MAX_STRING_LENGTH, stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
                enQueue(&fila, nome_arquivo);
                break;
            case 2:
                deQueue(&fila);
                break;
            case 3:
                if (isEmpty(fila)) {
                    printf("A fila está vazia.\n");
                } else {
                    printf("Arquivo no início da fila: %s\n", head(fila));
                }
                break;
            case 4:
                printf("Informe o nome do arquivo a ser cancelado: ");
                fgets(nome_arquivo, MAX_STRING_LENGTH, stdin);
                nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0'; 
                cancel(&fila, nome_arquivo);
                break;
            case 5:
                list(fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (op != 0);


    while (!isEmpty(fila)) {
        deQueue(&fila);
    }

    return 0;
}
