#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int dado;
    struct Celula *prox;
} Celula;

int contarElementos(Celula *lista) {
    if (lista == NULL) return 0;
    int contador = 1;
    Celula *atual = lista->prox;
    while (atual != lista) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

void inserirEsquerdaUltimo(Celula **lista, int valor) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if (!nova) exit(1);
    nova->dado = valor;
    if (*lista == NULL) {
        nova->prox = nova;
        *lista = nova;
        return;
    }
    Celula *ultimo = *lista;
    Celula *penultimo = NULL;
    while (ultimo->prox != *lista) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    if (penultimo == NULL) {
        nova->prox = ultimo;
        ultimo->prox = nova;
    } else {
        nova->prox = ultimo;
        penultimo->prox = nova;
    }
}

Celula* concatenarListas(Celula *A, Celula *B) {
    if (A == NULL) return B;
    if (B == NULL) return A;
    Celula *ultimoA = A;
    while (ultimoA->prox != A) ultimoA = ultimoA->prox;
    Celula *ultimoB = B;
    while (ultimoB->prox != B) ultimoB = ultimoB->prox;
    ultimoA->prox = B;
    ultimoB->prox = A;
    return A;
}

Celula* intercalarListasCirculares(Celula *A, Celula *B) {
    if (A == NULL) return B;
    if (B == NULL) return A;
    Celula *C = NULL;
    Celula **ptr = &C;
    Celula *inicioA = A;
    Celula *inicioB = B;
    do {
        if (A->dado <= B->dado) {
            Celula *nova = (Celula*) malloc(sizeof(Celula));
            nova->dado = A->dado;
            nova->prox = NULL;
            if (*ptr == NULL) {
                *ptr = nova;
                ptr = &nova->prox;
            } else {
                *ptr = nova;
                ptr = &nova->prox;
            }
            A = A->prox;
            if (A == inicioA) break;
        } else {
            Celula *nova = (Celula*) malloc(sizeof(Celula));
            nova->dado = B->dado;
            nova->prox = NULL;
            if (*ptr == NULL) {
                *ptr = nova;
                ptr = &nova->prox;
            } else {
                *ptr = nova;
                ptr = &nova->prox;
            }
            B = B->prox;
            if (B == inicioB) break;
        }
    } while (1);
    while (A != inicioA) {
        Celula *nova = (Celula*) malloc(sizeof(Celula));
        nova->dado = A->dado;
        nova->prox = NULL;
        *ptr = nova;
        ptr = &nova->prox;
        A = A->prox;
    }
    while (B != inicioB) {
        Celula *nova = (Celula*) malloc(sizeof(Celula));
        nova->dado = B->dado;
        nova->prox = NULL;
        *ptr = nova;
        ptr = &nova->prox;
        B = B->prox;
    }
    *ptr = C;
    return C;
}

Celula* copiarListaCircular(Celula *lista) {
    if (lista == NULL) return NULL;
    Celula *nova = NULL;
    Celula **ptr = &nova;
    Celula *inicio = lista;
    do {
        Celula *cel = (Celula*) malloc(sizeof(Celula));
        cel->dado = lista->dado;
        cel->prox = NULL;
        *ptr = cel;
        ptr = &cel->prox;
        lista = lista->prox;
    } while (lista != inicio);
    *ptr = nova;
    return nova;
}

void imprimirListaCircular(Celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Celula *atual = lista;
    do {
        printf("%d ", atual->dado);
        atual = atual->prox;
    } while (atual != lista);
    printf("\n");
}

void liberarListaCircular(Celula *lista) {
    if (lista == NULL) return;
    Celula *inicio = lista;
    Celula *atual = lista->prox;
    while (atual != inicio) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(inicio);
}

int main() {
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    Celula *c1 = (Celula*) malloc(sizeof(Celula));
    Celula *c2 = (Celula*) malloc(sizeof(Celula));
    Celula *c3 = (Celula*) malloc(sizeof(Celula));
    c1->dado = 1; c2->dado = 3; c3->dado = 5;
    c1->prox = c2; c2->prox = c3; c3->prox = c1;
    lista1 = c1;

    Celula *d1 = (Celula*) malloc(sizeof(Celula));
    Celula *d2 = (Celula*) malloc(sizeof(Celula));
    Celula *d3 = (Celula*) malloc(sizeof(Celula));
    d1->dado = 2; d2->dado = 4; d3->dado = 6;
    d1->prox = d2; d2->prox = d3; d3->prox = d1;
    lista2 = d1;

    printf("Lista 1: ");
    imprimirListaCircular(lista1);

    printf("Lista 2: ");
    imprimirListaCircular(lista2);

    printf("Número de elementos em lista1: %d\n", contarElementos(lista1));

    printf("Inserir 10 à esquerda do último em lista1.\n");
    inserirEsquerdaUltimo(&lista1, 10);
    imprimirListaCircular(lista1);

    printf("Concatenar lista1 e lista2:\n");
    Celula *concatenada = concatenarListas(lista1, lista2);
    imprimirListaCircular(concatenada);

    printf("Intercalar lista1 e lista2 em uma nova lista:\n");
    Celula *intercalada = intercalarListasCirculares(lista1, lista2);
    imprimirListaCircular(intercalada);

    printf("Fazer cópia da lista intercalada:\n");
    Celula *copia = copiarListaCircular(intercalada);
    imprimirListaCircular(copia);

    liberarListaCircular(concatenada);
    liberarListaCircular(intercalada);
    liberarListaCircular(copia);

    return 0;
}