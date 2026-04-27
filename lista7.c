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

void calcularMaiorMenorMedia(Celula *lista, int *maior, int *menor, double *media) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        *maior = 0;
        *menor = 0;
        *media = 0.0;
        return;
    }

    int soma = 0, contador = 0;
    *maior = lista->dado;
    *menor = lista->dado;

    Celula *atual = lista;
    while (atual != NULL) {
        if (atual->dado > *maior) *maior = atual->dado;
        if (atual->dado < *menor) *menor = atual->dado;
        soma += atual->dado;
        contador++;
        atual = atual->prox;
    }

    *media = (double) soma / contador;
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

    inserirFinal(&lista, 15);
    inserirFinal(&lista, 7);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 12);

    imprimirLista(lista);

    int maior, menor;
    double media;

    calcularMaiorMenorMedia(lista, &maior, &menor, &media);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média: %.2lf\n", media);

    liberarLista(lista);

    return 0;
}