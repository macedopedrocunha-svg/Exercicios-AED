#ifndef PILHANUM_H
#define PILHANUM_H

typedef struct pilhaNum PilhaNum;

PilhaNum *createNum(void);
void destroyNum(PilhaNum *pilha);
int emptyNum(PilhaNum *pilha);
int sizeNum(PilhaNum *pilha);
void pushNum(PilhaNum *pilha, double valor);
double popNum(PilhaNum *pilha);

#endif
