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

static void aux_internos_externos(No *raiz, int *internos, int *externos) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        (*externos)++;
    } else {
        (*internos)++;
    }
    aux_internos_externos(raiz->esq, internos, externos);
    aux_internos_externos(raiz->dir, internos, externos);
}

void contarInternosExternos(Arv *a) {
    int internos = 0;
    int externos = 0;
    if (a != NULL) {
        aux_internos_externos(a->raiz, &internos, &externos);
    }
    printf("Nós internos: %d\n", internos);
    printf("Nós externos (folhas): %d\n", externos);
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
