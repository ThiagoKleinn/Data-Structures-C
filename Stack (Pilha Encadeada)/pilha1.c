#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int valor;
    struct Elem* prox;
} Elem;

typedef struct {
    Elem* topo;
} Pilha;

void inicializarPilha(Pilha* p) {
    p->topo = NULL;
}

void empilhar(Pilha* p, int valor) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilhar(Pilha* p, int* valor) {
    if (p->topo == NULL) return 0;

    Elem* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return 1;
}

void inverterPilha(Pilha* p) {
    Pilha aux1, aux2;
    inicializarPilha(&aux1);
    inicializarPilha(&aux2);
    int valor;

    while (desempilhar(p, &valor))
        empilhar(&aux1, valor);
    while (desempilhar(&aux1, &valor))
        empilhar(&aux2, valor);
    while (desempilhar(&aux2, &valor))
        empilhar(p, valor);
}

void imprimirPilha(Pilha* p) {
    Elem* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializarPilha(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    inverterPilha(&p);

    imprimirPilha(&p);

    return 0;
}