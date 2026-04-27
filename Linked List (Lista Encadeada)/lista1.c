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

int contarCelulas(Celula *lista) {
    int contador = 0;
    Celula *atual = lista;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

void liberarLista(Celula *lista) {
    Celula *atual = lista;
    while (atual != NULL) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
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

int main() {
    Celula *lista = NULL;

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    imprimirLista(lista);

    printf("Número de células na lista: %d\n", contarCelulas(lista));

    liberarLista(lista);

    return 0;
}