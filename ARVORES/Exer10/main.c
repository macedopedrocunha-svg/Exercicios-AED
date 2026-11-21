#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    Arv *c7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *c5 = criar_arv(5, criar_arv_vazia(), c7);
    Arv *c15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());
    Arv *outra = criar_arv(10, c5, c15);

    printf("Primeira árvore: %s\n", ehCompleta(raiz) ? "completa" : "não é completa");
    printf("Segunda árvore: %s\n", ehCompleta(outra) ? "completa" : "não é completa");

    liberar_arv(outra);

    liberar_arv(raiz);

    return 0;
}
