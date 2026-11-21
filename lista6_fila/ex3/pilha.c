#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct noPilha {
    int valor;
    struct noPilha *prox;
} NoPilha;

struct pilha {
    NoPilha *topo;
    int tamanho;
};

Pilha *createPilha(void) {
    Pilha *pilha = malloc(sizeof(Pilha));
    if (pilha == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void destroyPilha(Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }
    while (!emptyPilha(pilha)) {
        popPilha(pilha);
    }
    free(pilha);
}

int emptyPilha(Pilha *pilha) {
    return pilha->tamanho == 0;
}

void pushPilha(Pilha *pilha, int valor) {
    NoPilha *novo = malloc(sizeof(NoPilha));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

int popPilha(Pilha *pilha) {
    if (emptyPilha(pilha)) {
        return 0;
    }
    NoPilha *removido = pilha->topo;
    int valor = removido->valor;
    pilha->topo = removido->prox;
    free(removido);
    pilha->tamanho--;
    return valor;
}
