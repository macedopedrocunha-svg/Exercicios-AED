#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    Arv *i2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *i7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *i5 = criar_arv(5, i2, i7);
    Arv *i15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());
    Arv *igual = criar_arv(10, i5, i15);

    Arv *d2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *d8 = criar_arv(8, criar_arv_vazia(), criar_arv_vazia());
    Arv *d5 = criar_arv(5, d2, d8);
    Arv *d15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());
    Arv *diferente = criar_arv(10, d5, d15);

    printf("Primeira e segunda: %s\n", arvoresIdenticas(raiz, igual) ? "idênticas" : "diferentes");
    printf("Primeira e terceira: %s\n", arvoresIdenticas(raiz, diferente) ? "idênticas" : "diferentes");

    liberar_arv(igual);
    liberar_arv(diferente);

    liberar_arv(raiz);

    return 0;
}
