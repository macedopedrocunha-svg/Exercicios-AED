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

static int aux_altura(No *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int he = aux_altura(raiz->esq);
    int hd = aux_altura(raiz->dir);
    return 1 + (he > hd ? he : hd);
}

static int aux_caminho(No *raiz, int alvo, int *caminho, int nivel) {
    if (raiz == NULL) {
        return 0;
    }
    caminho[nivel] = raiz->dado;
    if (raiz->dado == alvo) {
        for (int i = 0; i <= nivel; i++) {
            printf(i == 0 ? "%d" : " -> %d", caminho[i]);
        }
        printf("\n");
        return 1;
    }
    return aux_caminho(raiz->esq, alvo, caminho, nivel + 1) ||
           aux_caminho(raiz->dir, alvo, caminho, nivel + 1);
}

void imprimirCaminho(Arv *a, int alvo) {
    if (a == NULL || a->raiz == NULL) {
        return;
    }
    int *caminho = (int*) malloc((aux_altura(a->raiz) + 1) * sizeof(int));
    if (caminho == NULL) {
        return;
    }
    aux_caminho(a->raiz, alvo, caminho, 0);
    free(caminho);
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
