#define TAM 10
typedef struct stack{
    int dados[TAM];
    int topo;
} Stack;

void inicialize(Stack* s){
    s->topo = -1;
}
int isEmpty (Stack s){
    if(s.topo == -1){
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(Stack s){
    if(s.topo == TAM - 1){
        return 1;
    }
    else {
        return 0;
    }
}
void push (Stack* s, int valor){
    s->topo = s->topo + 1;
s->dados[s->topo] = valor;
}
int pop (Stack* s){
    int retorno = s->dados[s->topo];
    s->dados[s->topo] = 0;
    s->topo = s->topo - 1;
     return retorno;
}
int top (Stack s){
if (isEmpty(s)) {
        printf("Pilha vazia.\n");
        return -1; // Indicador de erro
    } else {
        return s.dados[s.topo];
    }

}