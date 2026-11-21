#include <stdio.h>
#include <stdlib.h>
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

static int aux_contar(No *raiz){
    if(raiz == NULL) {
        return 0;
    }
    return 1 + aux_contar(raiz->esq) + aux_contar(raiz->dir);
}

static int aux_altura(No *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int he = aux_altura(raiz->esq);
    int hd = aux_altura(raiz->dir);
    return 1 + (he > hd ? he : hd);
}

int ehPerfeita(Arv *a) {
    if (a == NULL) {
        return 1;
    }
    int h = aux_altura(a->raiz);
    int n = aux_contar(a->raiz);
    return n == (1 << (h + 1)) - 1;
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
