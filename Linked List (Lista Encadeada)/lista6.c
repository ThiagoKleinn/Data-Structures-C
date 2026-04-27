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

void ordenarLista(Celula *lista) {
    if (lista == NULL) return;

    int trocou;
    Celula *ptr1;
    Celula *ultimo = NULL;

    do {
        trocou = 0;
        ptr1 = lista;

        while (ptr1->prox != ultimo) {
            if (ptr1->dado > ptr1->prox->dado) {
                int temp = ptr1->dado;
                ptr1->dado = ptr1->prox->dado;
                ptr1->prox->dado = temp;
                trocou = 1;
            }
            ptr1 = ptr1->prox;
        }
        ultimo = ptr1;
    } while (trocou);
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

    inserirFinal(&lista, 30);
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 50);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 40);

    printf("Lista antes da ordenação:\n");
    imprimirLista(lista);

    ordenarLista(lista);

    printf("Lista depois da ordenação:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}