#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int valor;
    struct Elem* prox;
} Elem;

typedef struct {
    Elem* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

void empilhar(Pilha* p, int valor) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void imprimir(Pilha* p) {
    Elem* atual = p->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    Pilha positivos, negativos;
    inicializar(&positivos);
    inicializar(&negativos);

    int valor;

    while (1) {
        printf("Digite um número (0 para parar): ");
        scanf("%d", &valor);

        if (valor == 0)
            break;

        if (valor > 0)
            empilhar(&positivos, valor);
        else
            empilhar(&negativos, valor);
    }

    printf("Pilha de positivos: ");
    imprimir(&positivos);

    printf("Pilha de negativos: ");
    imprimir(&negativos);

    return 0;
}