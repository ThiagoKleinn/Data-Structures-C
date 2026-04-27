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

void removerValor(Celula **lista, int valor) {
    while (*lista != NULL && (*lista)->dado == valor) {
        Celula *temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }

    Celula *atual = *lista;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->prox->dado == valor) {
            Celula *temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
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

    inserirFinal(&lista, 5);
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 5);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 5);
    inserirFinal(&lista, 30);

    printf("Lista antes da remoção:\n");
    imprimirLista(lista);

    int valorRemover = 5;
    removerValor(&lista, valorRemover);

    printf("Lista após remover todos os %d:\n", valorRemover);
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}