#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#define TAM 6

typedef struct {
    int numero;
    char nome[100];
} Cliente;

typedef struct filaCircular FilaCircular;

FilaCircular *createCircular(void);
void destroyCircular(FilaCircular *fila);
int emptyCircular(FilaCircular *fila);
int fullCircular(FilaCircular *fila);
int sizeCircular(FilaCircular *fila);
int enqueueCircular(FilaCircular *fila, Cliente cliente);
Cliente dequeueCircular(FilaCircular *fila);
Cliente peekCircular(FilaCircular *fila);
void printCircular(FilaCircular *fila);

#endif
