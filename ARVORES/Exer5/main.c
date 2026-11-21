#include <stdio.h>
#include "arvore.h"

int main() {

    Arv *no2 = criar_arv(2, criar_arv_vazia(), criar_arv_vazia());
    Arv *no7 = criar_arv(7, criar_arv_vazia(), criar_arv_vazia());
    Arv *no5 = criar_arv(5, no2, no7);
    Arv *no15 = criar_arv(15, criar_arv_vazia(), criar_arv_vazia());

    Arv *raiz = criar_arv(10, no5, no15);

    printf("Nós com exatamente dois filhos: %d\n", contarNosDoisFilhos(raiz));

    liberar_arv(raiz);

    return 0;
}
