#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int valor;
    struct Elem* prox;
} Elem;

typedef struct {
    Elem* inicio;
    Elem* fim;
} Fila;

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila* f, int valor) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->valor = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila* f, int* valorRemovido) {
    if (f->inicio == NULL)
        return 0;

    Elem* temp = f->inicio;
    *valorRemovido = temp->valor;
    f->inicio = temp->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return 1;
}

void concatenarFilas(Fila* f1, Fila* f2) {
    if (f2->inicio == NULL)
        return;

    if (f1->fim == NULL) {
        f1->inicio = f2->inicio;
        f1->fim = f2->fim;
    } else {
        f1->fim->prox = f2->inicio;
        f1->fim = f2->fim;
    }

    f2->inicio = NULL;
    f2->fim = NULL;
}

void imprimirFila(Fila* f) {
    Elem* atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Fila f1, f2;
    inicializarFila(&f1);
    inicializarFila(&f2);

    enfileirar(&f1, 1);
    enfileirar(&f1, 2);
    enfileirar(&f2, 3);
    enfileirar(&f2, 4);

    concatenarFilas(&f1, &f2);

    imprimirFila(&f1);
    imprimirFila(&f2);

    return 0;
}