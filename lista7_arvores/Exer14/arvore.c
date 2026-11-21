#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct No {
    int dado;
    struct No *esq;
    struct No *dir;
};

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

static No* aux_lca(No *raiz, int v1, int v2) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->dado == v1 || raiz->dado == v2) {
        return raiz;
    }
    No *esq = aux_lca(raiz->esq, v1, v2);
    No *dir = aux_lca(raiz->dir, v1, v2);
    if (esq != NULL && dir != NULL) {
        return raiz;
    }
    return (esq != NULL) ? esq : dir;
}

No* ancestralComum(Arv *a, int v1, int v2) {
    if (a == NULL) {
        return NULL;
    }
    return aux_lca(a->raiz, v1, v2);
}

int dadoNo(No *no) {
    return no->dado;
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
