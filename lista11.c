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

Celula* intercalarListas(Celula *A, Celula *B) {
    Celula *C = NULL;
    Celula **ptr = &C;

    while (A != NULL && B != NULL) {
        if (A->dado <= B->dado) {
            *ptr = criarCelula(A->dado);
            A = A->prox;
        } else {
            *ptr = criarCelula(B->dado);
            B = B->prox;
        }
        ptr = &((*ptr)->prox);
    }

    while (A != NULL) {
        *ptr = criarCelula(A->dado);
        A = A->prox;
        ptr = &((*ptr)->prox);
    }

    while (B != NULL) {
        *ptr = criarCelula(B->dado);
        B = B->prox;
        ptr = &((*ptr)->prox);
    }

    return C;
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
    Celula *A = NULL;
    Celula *B = NULL;

    inserirFinal(&A, 1);
    inserirFinal(&A, 3);
    inserirFinal(&A, 5);
    inserirFinal(&A, 7);

    inserirFinal(&B, 2);
    inserirFinal(&B, 4);
    inserirFinal(&B, 6);
    inserirFinal(&B, 8);
    inserirFinal(&B, 10);

    printf("Lista A:\n");
    imprimirLista(A);

    printf("Lista B:\n");
    imprimirLista(B);

    Celula *C = intercalarListas(A, B);

    printf("Lista C (intercalada):\n");
    imprimirLista(C);

    liberarLista(A);
    liberarLista(B);
    liberarLista(C);

    return 0;
}