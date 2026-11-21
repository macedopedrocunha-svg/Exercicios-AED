#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    Elem elem;
    struct no *prox;
} No;

struct pilha {
    No *topo;
    int tamanho;
};

Pilha *create(void) {
    Pilha *pilha = malloc(sizeof(Pilha));
    if (pilha == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void destroy(Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }
    clear(pilha);
    free(pilha);
}

void reset(Pilha *pilha) {
    clear(pilha);
}

int empty(Pilha *pilha) {
    return pilha->tamanho == 0;
}

int size(Pilha *pilha) {
    return pilha->tamanho;
}

void push(Pilha *pilha, Elem elem) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->elem = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

Elem pop(Pilha *pilha) {
    Elem elem = {'\0'};
    if (empty(pilha)) {
        return elem;
    }
    No *removido = pilha->topo;
    elem = removido->elem;
    pilha->topo = removido->prox;
    free(removido);
    pilha->tamanho--;
    return elem;
}

void top(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Topo: %c\n", pilha->topo->elem.carac);
}

void clear(Pilha *pilha) {
    while (!empty(pilha)) {
        pop(pilha);
    }
}

void print(Pilha *pilha) {
    if (empty(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    char *v = malloc((size_t)pilha->tamanho);
    if (v == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    int i = pilha->tamanho - 1;
    for (No *no = pilha->topo; no != NULL; no = no->prox) {
        v[i--] = no->elem.carac;
    }
    for (i = 0; i < pilha->tamanho; i++) {
        printf("[%c]%s", v[i], i < pilha->tamanho - 1 ? " " : "\n");
    }
    free(v);
}
