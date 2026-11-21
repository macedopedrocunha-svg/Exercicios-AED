#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore Arv;

Arv* criar_arv_vazia(void);
Arv* criar_arv(int valor, Arv *esq, Arv *dir);
void liberar_arv(Arv *a);

int maiorElemento(Arv *a);

#endif
