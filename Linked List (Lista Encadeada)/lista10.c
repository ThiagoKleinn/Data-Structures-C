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

int estaOrdenada(Celula *lista) {
    if (lista == NULL || lista->prox == NULL) {
        return 1; // lista vazia ou com um elemento está ordenada
    }

    Celula *atual = lista;
    while (atual->prox != NULL) {
        if (atual->dado > atual->prox->dado) {
            return 0; // encontrou elemento fora da ordem crescente
        }
        atual = atual->prox;
    }

    return 1; // está ordenada
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
    Celula *lista = NULL;

    inserirFinal(&lista, 1);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 5);
    inserirFinal(&lista, 7);
    inserirFinal(&lista, 9);

    imprimirLista(lista);

    if (estaOrdenada(lista)) {
        printf("A lista está ordenada em ordem crescente.\n");
    } else {
        printf("A lista não está ordenada.\n");
    }

    liberarLista(lista);

    return 0;
}