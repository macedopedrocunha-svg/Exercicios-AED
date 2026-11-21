#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    Arv *p2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *p7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *p5 = criar_arv(5, p2, p7);
    Arv *p12 = criar_arv(12, criar_arv_vazia(), criar_arv_vazia());
    Arv *p20 = criar_arv(20, criar_arv_vazia(), criar_arv_vazia());
    Arv *p15 = criar_arv(15, p12, p20);
    Arv *perfeita = criar_arv(10, p5, p15);

    printf("Primeira árvore: %s\n", ehPerfeita(raiz) ? "perfeita" : "não é perfeita");
    printf("Segunda árvore: %s\n", ehPerfeita(perfeita) ? "perfeita" : "não é perfeita");

    liberar_arv(perfeita);

    liberar_arv(raiz);

    return 0;
}
