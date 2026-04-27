#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int valor;
    struct Elem* prox;
} Elem;

typedef struct {
    Elem* frente;
    Elem* tras;
} Fila;

void inicializar(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
}

int vazia(Fila* f) {
    return f->frente == NULL;
}

void enfileirar(Fila* f, int valor) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->valor = valor;
    novo->prox = NULL;
    if (f->tras != NULL)
        f->tras->prox = novo;
    else
        f->frente = novo;
    f->tras = novo;
}

int desenfileirar(Fila* f, int* valor) {
    if (vazia(f)) return 0;
    Elem* temp = f->frente;
    *valor = temp->valor;
    f->frente = temp->prox;
    if (f->frente == NULL)
        f->tras = NULL;
    free(temp);
    return 1;
}

typedef struct {
    Fila f1;
    Fila f2;
} PilhaComFilas;

void inicializarPilha(PilhaComFilas* p) {
    inicializar(&p->f1);
    inicializar(&p->f2);
}

void push(PilhaComFilas* p, int valor) {
    enfileirar(&p->f2, valor);

    int temp;
    while (!vazia(&p->f1)) {
        desenfileirar(&p->f1, &temp);
        enfileirar(&p->f2, temp);
    }

    // troca as filas
    Fila tempFila = p->f1;
    p->f1 = p->f2;
    p->f2 = tempFila;
}

int pop(PilhaComFilas* p, int* valor) {
    return desenfileirar(&p->f1, valor);
}

void imprimir(PilhaComFilas* p) {
    Elem* atual = p->f1.frente;
    printf("Pilha (topo → base): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    PilhaComFilas pilha;
    inicializarPilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    imprimir(&pilha);

    int valor;
    pop(&pilha, &valor);
    printf("Pop: %d\n", valor);
    imprimir(&pilha);

    return 0;
}