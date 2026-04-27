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

void removerNegativos(Fila* f) {
    Fila temp;
    inicializarFila(&temp);

    int valor;
    while (desenfileirar(f, &valor)) {
        if (valor >= 0)
            enfileirar(&temp, valor);
    }

    *f = temp;
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
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, -3);
    enfileirar(&f, 7);
    enfileirar(&f, -1);
    enfileirar(&f, 10);
    enfileirar(&f, -5);

    removerNegativos(&f);
    imprimirFila(&f);

    return 0;
}