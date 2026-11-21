#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct no {
    Elem elem;
    struct no *prox;
} No;

struct fila {
    No *inicio;
    No *fim;
    int tamanho;
};

static void *alocar(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

Fila *create(void) {
    Fila *fila = alocar(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void destroy(Fila *fila) {
    if (fila == NULL) {
        return;
    }
    clear(fila);
    free(fila);
}

void reset(Fila *fila) {
    clear(fila);
}

int empty(Fila *fila) {
    return fila->tamanho == 0;
}

int size(Fila *fila) {
    return fila->tamanho;
}

void enqueue(Fila *fila, Elem elem) {
    No *novo = alocar(sizeof(No));
    novo->elem = elem;
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

Elem dequeue(Fila *fila) {
    Elem elem = {0};
    if (empty(fila)) {
        return elem;
    }
    No *removido = fila->inicio;
    elem = removido->elem;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(removido);
    fila->tamanho--;
    return elem;
}

void front(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Primeiro: %d\n", fila->inicio->elem.valor);
}

void clear(Fila *fila) {
    while (!empty(fila)) {
        dequeue(fila);
    }
}

void print(Fila *fila) {
    printf("Início");
    for (No *no = fila->inicio; no != NULL; no = no->prox) {
        printf(" → %d", no->elem.valor);
    }
    printf(" → Fim\n");
}

typedef struct noCliente {
    Cliente cliente;
    struct noCliente *prox;
} NoCliente;

struct filaCliente {
    NoCliente *inicio;
    NoCliente *fim;
    int tamanho;
};

FilaCliente *createCliente(void) {
    FilaCliente *fila = alocar(sizeof(FilaCliente));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void destroyCliente(FilaCliente *fila) {
    if (fila == NULL) {
        return;
    }
    clearCliente(fila);
    free(fila);
}

void resetCliente(FilaCliente *fila) {
    clearCliente(fila);
}

int emptyCliente(FilaCliente *fila) {
    return fila->tamanho == 0;
}

int sizeCliente(FilaCliente *fila) {
    return fila->tamanho;
}

void enqueueCliente(FilaCliente *fila, Cliente cliente) {
    NoCliente *novo = alocar(sizeof(NoCliente));
    novo->cliente = cliente;
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

Cliente dequeueCliente(FilaCliente *fila) {
    Cliente cliente = {0, ""};
    if (emptyCliente(fila)) {
        return cliente;
    }
    NoCliente *removido = fila->inicio;
    cliente = removido->cliente;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(removido);
    fila->tamanho--;
    return cliente;
}

Cliente peekCliente(FilaCliente *fila) {
    Cliente cliente = {0, ""};
    if (!emptyCliente(fila)) {
        cliente = fila->inicio->cliente;
    }
    return cliente;
}

void frontCliente(FilaCliente *fila) {
    if (emptyCliente(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Primeiro: %d - %s\n", fila->inicio->cliente.numero, fila->inicio->cliente.nome);
}

void clearCliente(FilaCliente *fila) {
    while (!emptyCliente(fila)) {
        dequeueCliente(fila);
    }
}

void printCliente(FilaCliente *fila) {
    if (emptyCliente(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    for (NoCliente *no = fila->inicio; no != NULL; no = no->prox) {
        printf("%d - %s\n", no->cliente.numero, no->cliente.nome);
    }
}
