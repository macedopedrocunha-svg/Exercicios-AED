#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha *createPilha(void);
void destroyPilha(Pilha *pilha);
int emptyPilha(Pilha *pilha);
void pushPilha(Pilha *pilha, int valor);
int popPilha(Pilha *pilha);

#endif
