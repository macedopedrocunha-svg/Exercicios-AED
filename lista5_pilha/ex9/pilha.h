#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char carac;
} Elem;

typedef struct pilha Pilha;

Pilha *create(void);
void destroy(Pilha *pilha);
void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);

typedef struct {
    char texto[256];
} ElemStr;

typedef struct pilhaStr PilhaStr;

PilhaStr *createString(void);
void destroyString(PilhaStr *pilha);
int emptyString(PilhaStr *pilha);
int sizeString(PilhaStr *pilha);
void pushString(PilhaStr *pilha, ElemStr elem);
ElemStr popString(PilhaStr *pilha);
void topString(PilhaStr *pilha);
void clearString(PilhaStr *pilha);
void printString(PilhaStr *pilha);

#endif
