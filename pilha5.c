#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* criarPilha(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) return NULL;
    p->capacidade = capacidade;
    p->topo = -1;
    p->dados = (int*) malloc(sizeof(int) * capacidade);
    if (p->dados == NULL) {
        free(p);
        return NULL;
    }
    return p;
}

int empilhar(Pilha *p, int valor) {
    if (p->topo == p->capacidade - 1) return 0;
    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) return 0;
    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}

void liberarPilha(Pilha *p) {
    if (p != NULL) {
        free(p->dados);
        free(p);
    }
}

Pilha* copiarPilha(const Pilha *p1) {
    if (p1 == NULL) return NULL;
    Pilha *p2 = criarPilha(p1->capacidade);
    if (p2 == NULL) return NULL;
    p2->topo = p1->topo;
    for (int i = 0; i <= p1->topo; i++) {
        p2->dados[i] = p1->dados[i];
    }
    return p2;
}

void imprimirPilha(Pilha *p) {
    if (p->topo == -1) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha (topo->base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha *p1 = criarPilha(10);
    empilhar(p1, 5);
    empilhar(p1, 10);
    empilhar(p1, 20);

    printf("Pilha p1 original:\n");
    imprimirPilha(p1);

    Pilha *p2 = copiarPilha(p1);

    printf("Pilha p2 (cópia de p1):\n");
    imprimirPilha(p2);

    liberarPilha(p1);
    liberarPilha(p2);

    return 0;
}