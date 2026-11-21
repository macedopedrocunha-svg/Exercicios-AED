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

typedef struct noDocumento {
    Documento doc;
    struct noDocumento *prox;
} NoDocumento;

struct filaDocumento {
    NoDocumento *inicio;
    NoDocumento *fim;
    int tamanho;
};

FilaDocumento *createDocumento(void) {
    FilaDocumento *fila = alocar(sizeof(FilaDocumento));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void destroyDocumento(FilaDocumento *fila) {
    if (fila == NULL) {
        return;
    }
    clearDocumento(fila);
    free(fila);
}

int emptyDocumento(FilaDocumento *fila) {
    return fila->tamanho == 0;
}

int sizeDocumento(FilaDocumento *fila) {
    return fila->tamanho;
}

void enqueueDocumento(FilaDocumento *fila, Documento doc) {
    NoDocumento *novo = alocar(sizeof(NoDocumento));
    novo->doc = doc;
    novo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

Documento dequeueDocumento(FilaDocumento *fila) {
    Documento doc = {0, "", 0};
    if (emptyDocumento(fila)) {
        return doc;
    }
    NoDocumento *removido = fila->inicio;
    doc = removido->doc;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(removido);
    fila->tamanho--;
    return doc;
}

void clearDocumento(FilaDocumento *fila) {
    while (!emptyDocumento(fila)) {
        dequeueDocumento(fila);
    }
}

void printDocumento(FilaDocumento *fila) {
    if (emptyDocumento(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    for (NoDocumento *no = fila->inicio; no != NULL; no = no->prox) {
        printf("ID=%d, Nome=\"%s\", Páginas=%d\n", no->doc.id, no->doc.nome, no->doc.paginas);
    }
}
