#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore Arv;
typedef struct No No;

Arv* criar_arv_vazia(void);
Arv* criar_arv(int valor, Arv *esq, Arv *dir);
void liberar_arv(Arv *a);

No* ancestralComum(Arv *a, int v1, int v2);
int dadoNo(No *no);

#endif
