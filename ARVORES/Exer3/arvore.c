#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arvore.h"

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
}No;

struct arvore {
    No *raiz;
};

Arv* criar_arv_vazia(void){
    Arv *a = (Arv*) malloc(sizeof(Arv));
    if (a != NULL){
        a->raiz = NULL;
    }
    return a;
}

Arv* criar_arv(int valor, Arv *esq, Arv *dir) {
    Arv *a = (Arv*) malloc(sizeof(Arv));
    if (a != NULL) {
        a->raiz = (No*) malloc(sizeof(No));
        a->raiz->dado = valor;
        a->raiz->esq = (esq != NULL) ? esq->raiz : NULL;
        a->raiz->dir = (dir != NULL) ? dir->raiz : NULL;
    }
    if (esq != NULL) free(esq);
    if (dir != NULL) free(dir);
    return a;
}

static int aux_maior(No *raiz) {
    if (raiz == NULL) {
        return INT_MIN;
    }
    int maior = raiz->dado;
    int me = aux_maior(raiz->esq);
    int md = aux_maior(raiz->dir);
    if (me > maior) {
        maior = me;
    }
    if (md > maior) {
        maior = md;
    }
    return maior;
}

int maiorElemento(Arv *a) {
    if (a == NULL) {
        return INT_MIN;
    }
    return aux_maior(a->raiz);
}

static void aux_liberar(No *raiz) {
    if (raiz != NULL) {
        aux_liberar(raiz->esq);
        aux_liberar(raiz->dir);
        free(raiz);
    }
}

void liberar_arv(Arv *a) {
    if (a != NULL) {
        aux_liberar(a->raiz);
        free(a);
    }
}
