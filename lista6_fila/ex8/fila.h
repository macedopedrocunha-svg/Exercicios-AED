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
    int numero;
    char nome[100];
} Cliente;

typedef struct filaCliente FilaCliente;

FilaCliente *createCliente(void);
void destroyCliente(FilaCliente *fila);
void resetCliente(FilaCliente *fila);
int emptyCliente(FilaCliente *fila);
int sizeCliente(FilaCliente *fila);
void enqueueCliente(FilaCliente *fila, Cliente cliente);
Cliente dequeueCliente(FilaCliente *fila);
Cliente peekCliente(FilaCliente *fila);
void frontCliente(FilaCliente *fila);
void clearCliente(FilaCliente *fila);
void printCliente(FilaCliente *fila);

#endif
