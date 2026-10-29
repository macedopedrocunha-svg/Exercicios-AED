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
    novo->ant = NULL;
    novo->prox = lista->pFirst;
    if (lista->pFirst != NULL) {
        lista->pFirst->ant = novo;
    }
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
        novo->ant = NULL;
        lista->pFirst = novo;
        return;
    }
    Nodo *aux = lista->pFirst;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }
    Nodo *remover = lista->pFirst;
    lista->pFirst = remover->prox;
    if (lista->pFirst != NULL) {
        lista->pFirst->ant = NULL;
    }
    free(remover);
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }
    Nodo *aux = lista->pFirst;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    if (aux->ant == NULL) {
        lista->pFirst = NULL;
    } else {
        aux->ant->prox = NULL;
    }
    free(aux);
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
        printf("[%d] ⇄ ", aux->info.valor);
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
