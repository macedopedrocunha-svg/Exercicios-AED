#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    No *lca1 = ancestralComum(raiz, 2, 7);
    No *lca2 = ancestralComum(raiz, 2, 15);
    No *lca3 = ancestralComum(raiz, 5, 7);

    printf("Ancestral comum mais baixo de 2 e 7: %d\n", dadoNo(lca1));
    printf("Ancestral comum mais baixo de 2 e 15: %d\n", dadoNo(lca2));
    printf("Ancestral comum mais baixo de 5 e 7: %d\n", dadoNo(lca3));

    liberar_arv(raiz);

    return 0;
}
