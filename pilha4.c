#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int valor;
    struct Elem* prox;
} Elem;

typedef struct {
    Elem* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int vazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, int valor) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha* p, int* valor) {
    if (vazia(p)) return 0;
    Elem* temp = p->topo;
    *valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return 1;
}

void inserirOrdenado(Pilha* p, int valor) {
    Pilha aux;
    inicializar(&aux);
    int temp;

    while (!vazia(p) && p->topo->valor < valor) {
        pop(p, &temp);
        push(&aux, temp);
    }

    push(p, valor);

    while (!vazia(&aux)) {
        pop(&aux, &temp);
        push(p, temp);
    }
}

void imprimir(Pilha* p) {
    Elem* atual = p->topo;
    printf("Pilha (menor no topo): ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    inserirOrdenado(&p, 10);
    inserirOrdenado(&p, 5);
    inserirOrdenado(&p, 7);
    inserirOrdenado(&p, 3);
    inserirOrdenado(&p, 9);

    imprimir(&p);

    return 0;
}