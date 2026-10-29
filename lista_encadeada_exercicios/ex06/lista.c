#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Head *criaLista() {
    Head *lista = (Head *)malloc(sizeof(Head));
    if (lista != NULL) {
        lista->pFirst = NULL;
    }
    return lista;
}

int listaVazia(Head *lista) {
    return lista == NULL || lista->pFirst == NULL;
}

void inserirInicio(Head *lista, Info dado) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL) {
        return;
    }
    novo->info = dado;
    novo->prox = lista->pFirst;
    lista->pFirst = novo;
}

void inserirFinal(Head *lista, Info dado) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL) {
        return;
    }
    novo->info = dado;
    novo->prox = NULL;
    if (lista->pFirst == NULL) {
        lista->pFirst = novo;
        return;
    }
    Nodo *aux = lista->pFirst;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }
    Nodo *remover = lista->pFirst;
    lista->pFirst = remover->prox;
    free(remover);
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }
    if (lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }
    Nodo *aux = lista->pFirst;
    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
    return 1;
}

int buscar(Head *lista, int valor, Info *resultado) {
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        if (aux->info.valor == valor) {
            if (resultado != NULL) {
                *resultado = aux->info;
            }
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void imprimirLista(Head *lista) {
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        printf("[%d] → ", aux->info.valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberaLista(Head *lista) {
    Nodo *aux = lista->pFirst;
    while (aux != NULL) {
        Nodo *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(lista);
}

void concatenar(Head *lista1, Head *lista2) {
    if (lista2->pFirst == NULL) {
        return;
    }
    if (lista1->pFirst == NULL) {
        lista1->pFirst = lista2->pFirst;
    } else {
        Nodo *aux = lista1->pFirst;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = lista2->pFirst;
    }
    lista2->pFirst = NULL;
}
