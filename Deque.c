#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct Deque {
    int inicio;
    int fim;
    int qtd;
    char dados[TAM];
} Deque;

void iniciar(Deque *d) {
    d->inicio = 0;
    d->fim = 0;
    d->qtd = 0;
}

void destruir(Deque *d) {
    d->inicio = 0;
    d->fim = 0;
    d->qtd = 0;
}

int dequeCheio(Deque *d) {
    return d->qtd >= TAM;
}

int dequeVazio(Deque *d) {
    return d->qtd == 0;
}

int inserirInicio(Deque *d, char valor) {
    if (dequeCheio(d)) {
        printf("\nDeque cheio!");
        return 1;
    }
    d->inicio = (d->inicio - 1 + TAM) % TAM;
    d->dados[d->inicio] = valor;
    d->qtd++;
    return 0;
}

int removerInicio(Deque *d, char *valorRemovido) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
        return 1;
    }
    *valorRemovido = d->dados[d->inicio];
    d->inicio = (d->inicio + 1) % TAM;
    d->qtd--;
    return 0;
}

int inserirFim(Deque *d, char valor) {
    if (dequeCheio(d)) {
        printf("\nDeque cheio!");
        return 1;
    }
    d->dados[d->fim] = valor;
    d->fim = (d->fim + 1) % TAM;
    d->qtd++;
    return 0;
}

int removerFim(Deque *d, char *valorRemovido) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
        return 1;
    }
    d->fim = (d->fim - 1 + TAM) % TAM;
    *valorRemovido = d->dados[d->fim];
    d->qtd--;
    return 0;
}

void acessarInicio(Deque *d) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
    } else {
        printf("Início: %c\n", d->dados[d->inicio]);
    }
}

void acessarFim(Deque *d) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
    } else {
        int pos = (d->fim - 1 + TAM) % TAM;
        printf("Fim: %c\n", d->dados[pos]);
    }
}

int inverterElementos(Deque *d) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
        return 1;
    }

    char temp[TAM];
    int i, pos;

    for (i = 0; i < d->qtd; i++) {
        pos = (d->inicio + i) % TAM;
        temp[d->qtd - 1 - i] = d->dados[pos];
    }

    for (i = 0; i < d->qtd; i++) {
        pos = (d->inicio + i) % TAM;
        d->dados[pos] = temp[i];
    }

    return 0;
}

void copiarDeque(Deque *origem, Deque *destino) {
    iniciar(destino);

    for (int i = 0; i < origem->qtd; i++) {
        int pos = (origem->inicio + i) % TAM;
        destino->dados[i] = origem->dados[pos];
    }

    destino->inicio = 0;
    destino->fim = origem->qtd % TAM;
    destino->qtd = origem->qtd;
}

void listarDeque(Deque *d) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
    } else {
        for (int i=0; i < d->qtd; i++) {
            int pos = (d->inicio + i) % TAM;
            printf("%c ", d->dados[pos]);
        }
    }
}

int main() {

    Deque d;
    iniciar(&d);

    inserirInicio(&d, 'A');
    inserirFim(&d, 'B');
    inserirFim(&d, 'C');

    acessarInicio(&d);
    acessarFim(&d);

    char removido;
    removerInicio(&d, &removido);
    printf("Removido do início: %c\n", removido);

    removerFim(&d, &removido);
    printf("Removido do fim: %c\n", removido);

    return 0;
}