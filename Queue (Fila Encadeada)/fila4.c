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

int desenfileirar(Fila* f, int* valor) {
    if (f->inicio == NULL)
        return 0;

    Elem* temp = f->inicio;
    *valor = temp->valor;
    f->inicio = temp->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return 1;
}

void mesclarFilasOrdenadas(Fila* f1, Fila* f2, Fila* f3) {
    int v1, v2;
    int ok1 = desenfileirar(f1, &v1);
    int ok2 = desenfileirar(f2, &v2);

    while (ok1 && ok2) {
        if (v1 <= v2) {
            enfileirar(f3, v1);
            ok1 = desenfileirar(f1, &v1);
        } else {
            enfileirar(f3, v2);
            ok2 = desenfileirar(f2, &v2);
        }
    }

    while (ok1) {
        enfileirar(f3, v1);
        ok1 = desenfileirar(f1, &v1);
    }

    while (ok2) {
        enfileirar(f3, v2);
        ok2 = desenfileirar(f2, &v2);
    }
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
    Fila f1, f2, f3;
    inicializarFila(&f1);
    inicializarFila(&f2);
    inicializarFila(&f3);

    enfileirar(&f1, 1);
    enfileirar(&f1, 4);
    enfileirar(&f1, 7);

    enfileirar(&f2, 2);
    enfileirar(&f2, 5);
    enfileirar(&f2, 8);

    mesclarFilasOrdenadas(&f1, &f2, &f3);

    imprimirFila(&f3);

    return 0;
}