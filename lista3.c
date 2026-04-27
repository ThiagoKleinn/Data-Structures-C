#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int dado;
    struct Celula *prox;
} Celula;

Celula* criarCelula(int valor) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    nova->dado = valor;
    nova->prox = NULL;
    return nova;
}

void inserirFinal(Celula **lista, int valor) {
    Celula *nova = criarCelula(valor);
    if (*lista == NULL) {
        *lista = nova;
    } else {
        Celula *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = nova;
    }
}

void concatenarListas(Celula **lista1, Celula *lista2) {
    if (*lista1 == NULL) {
        *lista1 = lista2;
        return;
    }
    Celula *atual = *lista1;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = lista2;
}

void imprimirLista(Celula *lista) {
    Celula *atual = lista;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarLista(Celula *lista) {
    Celula *atual = lista;
    while (atual != NULL) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    inserirFinal(&lista1, 1);
    inserirFinal(&lista1, 2);
    inserirFinal(&lista1, 3);

    inserirFinal(&lista2, 4);
    inserirFinal(&lista2, 5);
    inserirFinal(&lista2, 6);

    printf("Lista 1 antes da concatenação:\n");
    imprimirLista(lista1);

    printf("Lista 2 antes da concatenação:\n");
    imprimirLista(lista2);

    concatenarListas(&lista1, lista2);

    printf("Lista 1 após concatenar lista 2:\n");
    imprimirLista(lista1);

    // lista2 agora está "presa" no final de lista1, não deve liberar separadamente
    liberarLista(lista1);

    return 0;
}