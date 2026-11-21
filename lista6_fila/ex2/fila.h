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

#endif
