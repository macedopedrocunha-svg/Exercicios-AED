#include <stdio.h>
#include <stdlib.h>
#include "pilhanum.h"

typedef struct noNum {
    double valor;
    struct noNum *prox;
} NoNum;

struct pilhaNum {
    NoNum *topo;
    int tamanho;
};

PilhaNum *createNum(void) {
    PilhaNum *pilha = malloc(sizeof(PilhaNum));
    if (pilha == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void destroyNum(PilhaNum *pilha) {
    if (pilha == NULL) {
        return;
    }
    while (!emptyNum(pilha)) {
        popNum(pilha);
    }
    free(pilha);
}

int emptyNum(PilhaNum *pilha) {
    return pilha->tamanho == 0;
}

int sizeNum(PilhaNum *pilha) {
    return pilha->tamanho;
}

void pushNum(PilhaNum *pilha, double valor) {
    NoNum *novo = malloc(sizeof(NoNum));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

double popNum(PilhaNum *pilha) {
    if (emptyNum(pilha)) {
        return 0;
    }
    NoNum *removido = pilha->topo;
    double valor = removido->valor;
    pilha->topo = removido->prox;
    free(removido);
    pilha->tamanho--;
    return valor;
}
