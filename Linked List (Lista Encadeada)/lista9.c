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

Celula* filtrarPares(Celula *lista) {
    Celula *novaLista = NULL;
    Celula *atual = lista;

    while (atual != NULL) {
        if (atual->dado % 2 == 0) {
            inserirFinal(&novaLista, atual->dado);
        }
        atual = atual->prox;
    }

    return novaLista;
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

    inserirFinal(&lista, 3);
    inserirFinal(&lista, 4);
    inserirFinal(&lista, 7);
    inserirFinal(&lista, 8);
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 13);

    printf("Lista original:\n");
    imprimirLista(lista);

    Celula *pares = filtrarPares(lista);

    printf("Lista só com pares:\n");
    imprimirLista(pares);

    liberarLista(lista);
    liberarLista(pares);

    return 0;
}