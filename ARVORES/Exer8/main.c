#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    Arv *b2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *b5 = criar_arv(5, b2, criar_arv_vazia());
    Arv *b15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());
    Arv *outra = criar_arv(10, b5, b15);

    printf("Primeira árvore: %s\n", ehCheia(raiz) ? "cheia" : "não é cheia");
    printf("Segunda árvore: %s\n", ehCheia(outra) ? "cheia" : "não é cheia");

    liberar_arv(outra);

    liberar_arv(raiz);

    return 0;
}
