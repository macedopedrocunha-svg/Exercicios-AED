#include <stdio.h>
#include <stdlib.h>
#include "fila_circular.h"

struct filaCircular {
    Cliente dados[TAM];
    int inicio;
    int fim;
};

FilaCircular *createCircular(void) {
    FilaCircular *fila = malloc(sizeof(FilaCircular));
    if (fila == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

void destroyCircular(FilaCircular *fila) {
    free(fila);
}

int emptyCircular(FilaCircular *fila) {
    return fila->inicio == fila->fim;
}

int fullCircular(FilaCircular *fila) {
    return (fila->fim + 1) % TAM == fila->inicio;
}

int sizeCircular(FilaCircular *fila) {
    return (fila->fim - fila->inicio + TAM) % TAM;
}

int enqueueCircular(FilaCircular *fila, Cliente cliente) {
    if (fullCircular(fila)) {
        return 0;
    }
    fila->dados[fila->fim] = cliente;
    fila->fim = (fila->fim + 1) % TAM;
    return 1;
}

Cliente dequeueCircular(FilaCircular *fila) {
    Cliente cliente = {0, ""};
    if (emptyCircular(fila)) {
        return cliente;
    }
    cliente = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM;
    return cliente;
}

Cliente peekCircular(FilaCircular *fila) {
    Cliente cliente = {0, ""};
    if (!emptyCircular(fila)) {
        cliente = fila->dados[fila->inicio];
    }
    return cliente;
}

void printCircular(FilaCircular *fila) {
    if (emptyCircular(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % TAM) {
        printf("%d - %s\n", fila->dados[i].numero, fila->dados[i].nome);
    }
}
