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

int removerNPrimeiros(Celula **lista, int n) {
    if (n <= 0) return 1; // nada a remover, sucesso

    Celula *atual = *lista;
    int removidos = 0;

    while (atual != NULL && removidos < n) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
        removidos++;
    }

    *lista = atual;

    return (removidos == n) ? 1 : 0;
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

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);
    inserirFinal(&lista, 50);

    printf("Lista antes de remover os primeiros elementos:\n");
    imprimirLista(lista);

    int n = 3;
    int sucesso = removerNPrimeiros(&lista, n);

    if (sucesso) {
        printf("Sucesso ao remover os %d primeiros elementos.\n", n);
    } else {
        printf("Não foi possível remover %d elementos (lista muito pequena).\n", n);
    }

    printf("Lista depois da remoção:\n");
    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}