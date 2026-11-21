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

static int aux_caminho_soma(No *raiz, int alvo) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return raiz->dado == alvo;
    }
    return aux_caminho_soma(raiz->esq, alvo - raiz->dado) ||
           aux_caminho_soma(raiz->dir, alvo - raiz->dado);
}

int existeCaminhoSoma(Arv *a, int alvo) {
    if (a == NULL) {
        return 0;
    }
    return aux_caminho_soma(a->raiz, alvo);
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
