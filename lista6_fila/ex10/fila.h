#ifndef FILA_H
#define FILA_H

typedef struct {
    int valor;
} Elem;

typedef struct fila Fila;

Fila *create(void);
void destroy(Fila *fila);
void reset(Fila *fila);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);

typedef struct {
    int id;
    char nome[100];
    int paginas;
} Documento;

typedef struct filaDocumento FilaDocumento;

FilaDocumento *createDocumento(void);
void destroyDocumento(FilaDocumento *fila);
int emptyDocumento(FilaDocumento *fila);
int sizeDocumento(FilaDocumento *fila);
void enqueueDocumento(FilaDocumento *fila, Documento doc);
Documento dequeueDocumento(FilaDocumento *fila);
void clearDocumento(FilaDocumento *fila);
void printDocumento(FilaDocumento *fila);

#endif
