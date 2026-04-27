#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct Solicitação {
    int id;
    char ip[16];
} Solicitação;

typedef struct Deque {
    int inicio;
    int fim;
    int qtd;
    Solicitação dados[TAM];
} Deque;

void iniciar(Deque *d) {
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

int inserirInicio(Deque *d, Solicitação valor) {
    if (dequeCheio(d)) {
        printf("\nDeque cheio!");
        return 1;
    }
    d->inicio = (d->inicio - 1 + TAM) % TAM;
    d->dados[d->inicio] = valor;
    d->qtd++;
    return 0;
}

int inserirFim(Deque *d, Solicitação valor) {
    if (dequeCheio(d)) {
        printf("\nDeque cheio!");
        return 1;
    }
    d->dados[d->fim] = valor;
    d->fim = (d->fim + 1) % TAM;
    d->qtd++;
    return 0;
}

int removerInicio(Deque *d, Solicitação *valorRemovido) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
        return 1;
    }
    *valorRemovido = d->dados[d->inicio];
    d->inicio = (d->inicio + 1) % TAM;
    d->qtd--;
    return 0;
}

void listarDeque(Deque *d) {
    if (dequeVazio(d)) {
        printf("\nDeque vazio!");
    } else {
        for (int i = 0; i < d->qtd; i++) {
            int pos = (d->inicio + i) % TAM;
            printf("ID: %d, IP: %s\n", d->dados[pos].id, d->dados[pos].ip);
        }
    }
}

int main() {
    Deque d;
    iniciar(&d);

    Solicitação s1 = {1, "192.168.0.1"};
    Solicitação s2 = {2, "192.168.0.2"};
    Solicitação s3 = {3, "192.168.0.3"};
    Solicitação s4 = {4, "192.168.0.4"};

    
    inserirInicio(&d, s1); 
    inserirInicio(&d, s2); 

    
    inserirFim(&d, s3);  
    inserirFim(&d, s4);  

    printf("\nSolicitações na DEQUE:\n");
    listarDeque(&d);

    Solicitação removida;
    removerInicio(&d, &removida);  
    printf("\nSolicitação removida: ID: %d, IP: %s\n", removida.id, removida.ip);

    removerInicio(&d, &removida);  
    printf("Solicitação removida: ID: %d, IP: %s\n", removida.id, removida.ip);

    removerInicio(&d, &removida); 
    printf("Solicitação removida: ID: %d, IP: %s\n", removida.id, removida.ip);

    removerInicio(&d, &removida); 
    printf("Solicitação removida: ID: %d, IP: %s\n", removida.id, removida.ip);

    return 0;
}